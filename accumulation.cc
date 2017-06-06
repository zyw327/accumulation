#include <nan.h>

void change(long long *num1, long long *num2){
  *num1 = *num2 + *num1;
  *num2 = *num1 - *num2;
  *num1 = *num1 - *num2;
}

long long add(long long min, long long max){
  if (min > max) {
    change(&min, &max);
  }
  long long sum = 0;
  long long addTimes = 0;
  if ((min + max) % 2 == 0) {
    addTimes = (max - min) / 2;
    return addTimes * (max + min ) + (max + min ) /2;
  } else {
    addTimes = (max - min + 1) / 2;
    return (max+min)*addTimes;
  }
}

void accumulation(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.Length() < 2) {
    Nan::ThrowTypeError("至少需要两个参数");
    return;
  }

  if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
    Nan::ThrowTypeError("错误的参数");
    return;
  }
  long long arg0 = (long long) info[0]->NumberValue();
  long long arg1 = (long long) info[1]->NumberValue();
 
  long long sum = 0;
  sum = add(arg0, arg1);
  char buf[100];
  sprintf(buf,"%lld",sum);
  v8::Local<v8::String> num = Nan::New(buf).ToLocalChecked();
  info.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("accumulation").ToLocalChecked(),
  Nan::New<v8::FunctionTemplate>(accumulation)->GetFunction());
}
NODE_MODULE(accumulation, Init)