#include <iostream>
#include <JavaScriptCore/JavaScript.h>

// https://karhm.com/JavaScriptCore_C_API/
int main(int argc, char* argv[]) {
  JSGlobalContextRef context = JSGlobalContextCreate(0);
  JSValueRef exception;
  JSStringRef code = JSStringCreateWithUTF8CString("const helloWorld = () => 1 + 1; helloWorld();");
  JSStringRef file = JSStringCreateWithUTF8CString("");
  JSValueRef value = JSEvaluateScript(context, code, /* thisObject*/ 0, file, 1, &exception);
  bool assert = JSValueIsNumber(context, value);
  int number = (int)JSValueToNumber(context, value, NULL);
  std::cout << "Value: " << number << " from JSCore! " << std::endl;
  return 0;
}
