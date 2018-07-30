#include <napi.h>
#include <kernel/yosys.h>

namespace libyosys_napi {
  std::string hello();
  Napi::String HelloWrapped(const Napi::CallbackInfo& info);
}

std::string libyosys_napi::hello(){
  return "Hello World";
}

Napi::String libyosys_napi::HelloWrapped(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();
  Napi::String returnValue = Napi::String::New(env, hello());

  return returnValue;
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  exports.Set("hello", Napi::Function::New(env, libyosys_napi::HelloWrapped));

  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
