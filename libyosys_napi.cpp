#include <napi.h>
#include <kernel/yosys.h>

namespace libyosys_napi {
  Napi::Value SetupWrapped(const Napi::CallbackInfo& info);
  Napi::Value RunPassWrapped(const Napi::CallbackInfo& info);
  Napi::Value ShutdownWrapped(const Napi::CallbackInfo& info);
}

Napi::Value libyosys_napi::SetupWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Yosys::log_streams.push_back(&std::cout);
  Yosys::log_error_stderr = true;
  Yosys::yosys_setup();
  return env.Null();
}

Napi::Value libyosys_napi::RunPassWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() != 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::String command = info[0].As<Napi::String>();

  Yosys::run_pass(command, nullptr);
  return env.Null();
}

Napi::Value libyosys_napi::ShutdownWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Yosys::yosys_shutdown();
  return env.Null();
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  exports.Set("setup", Napi::Function::New(env, libyosys_napi::SetupWrapped));
  exports.Set("run", Napi::Function::New(env, libyosys_napi::RunPassWrapped));
  exports.Set("shutdown", Napi::Function::New(env, libyosys_napi::ShutdownWrapped));

  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
