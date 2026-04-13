#include <napi.h>
#include <windows.h>

Napi::String Hello(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    GetComputerNameA(computerName, &size);
    
    std::string message = "Привет из C++! Твой компьютер: ";
    message += computerName;
    message += ". WinAPI работает в Node.js!";
    
    return Napi::String::New(env, message);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Hello));
    return exports;
}

NODE_API_MODULE(hello, Init)