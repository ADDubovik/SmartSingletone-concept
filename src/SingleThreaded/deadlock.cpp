#include "SingletonShared.h"

#include <iostream>
#include <functional>


class CallbackPayload
{
public:
  CallbackPayload() = default;
  ~CallbackPayload()
  {
    std::cout << "~CallbackPayload()" << std::endl;
  }

  CallbackPayload(const CallbackPayload &) = delete;
  CallbackPayload(CallbackPayload &&) = delete;

  CallbackPayload& operator=(const CallbackPayload &) = delete;
  CallbackPayload& operator=(CallbackPayload &&) = delete;

  void setCallback(std::function<void()> &&fn)
  {
    m_callbackFn = std::move(fn);
  }

private:
  std::function<void()> m_callbackFn;
};


int main()
{
  SingletonShared<CallbackPayload>::instance()->setCallback(
      [capture = SingletonShared<CallbackPayload>::instance()](){}
  );

  return 0;
}
