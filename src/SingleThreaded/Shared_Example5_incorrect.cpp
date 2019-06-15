#include "SingletonShared.h"
#include "CallbackPayload.h"
#include "SomethingWithVeryImportantDestructor.h"


class SharedSingleThreadedUtility
{
public:
  SharedSingleThreadedUtility()
      // To ensure that singleton will be constucted before utility
      : m_singleton(SingletonShared<CallbackPayload>::instance())
  {
    std::cout << "SharedSingleThreadedUtility()" << std::endl;
  }

  ~SharedSingleThreadedUtility()
  {
    std::cout << "~SharedSingleThreadedUtility()" << std::endl;
  }

  void setCallback(std::function<void()> &&fn)
  {
    if ( m_singleton )
      m_singleton->setCallback(std::move(fn));
  }

private:
  // A copy of smart pointer, not a reference
  std::shared_ptr<SingletonShared<CallbackPayload>> m_singleton;
};



int main()
{
  auto utility = std::make_shared<SharedSingleThreadedUtility>();

  SingletonShared<CallbackPayload>::instance()->setCallback(
      [
        utility,
        something = std::make_shared<SomethingWithVeryImportantDestructor>()
      ]
      ()
      {}
  );

  return 0;
}
