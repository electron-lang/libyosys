#include <napi.h>
#include <kernel/yosys.h>

namespace libyosys_napi {
  std::string hello();
  Napi::String HelloWrapped(const Napi::CallbackInfo& info);

  int add(int a, int b);
  Napi::Number AddWrapped(const Napi::CallbackInfo& info);
}

std::string libyosys_napi::hello() {
  return "Hello World";
}

Napi::String libyosys_napi::HelloWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::String returnValue = Napi::String::New(env, hello());

  return returnValue;
}

int libyosys_napi::add(int a, int b) {
  return a + b;
}

Napi::Number libyosys_napi::AddWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }

  Napi::Number first = info[0].As<Napi::Number>();
  Napi::Number second = info[1].As<Napi::Number>();

  int returnValue = libyosys_napi::add(first.Int32Value(), second.Int32Value());

  return Napi::Number::New(env, returnValue);
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  exports.Set("hello", Napi::Function::New(env, libyosys_napi::HelloWrapped));
  exports.Set("add", Napi::Function::New(env, libyosys_napi::AddWrapped));

  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
