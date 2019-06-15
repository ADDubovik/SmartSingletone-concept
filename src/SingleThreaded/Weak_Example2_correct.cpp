#include "SingletonWeak.h"
#include "CallbackPayload.h"
#include "SomethingWithVeryImportantDestructor.h"


class WeakSingleThreadedUtility
{
public:
  WeakSingleThreadedUtility()
      // To ensure that singleton will be constucted before utility
      : m_weak(SingletonWeak<CallbackPayload>::instance())
  {
    std::cout << "WeakSingleThreadedUtility()" << std::endl;
  }

  ~WeakSingleThreadedUtility()
  {
    std::cout << "~WeakSingleThreadedUtility()" << std::endl;
  }

  void setCallback(std::function<void()> &&fn)
  {
    if ( auto strong = m_weak.lock() )
      strong->setCallback(std::move(fn));
  }

private:
  // A weak copy of smart pointer, not a reference
  std::weak_ptr<SingletonWeak<CallbackPayload>> m_weak;
};



int main()
{
  auto utility = std::make_shared<WeakSingleThreadedUtility>();

  utility->setCallback(
      [
        utility,
        something = std::make_shared<SomethingWithVeryImportantDestructor>()
      ]
      ()
      {}
  );

  return 0;
}
