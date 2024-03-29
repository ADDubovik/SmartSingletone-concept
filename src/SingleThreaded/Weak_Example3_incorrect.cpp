#include "SingletonWeak.h"
#include "Payload.h"

#include <memory>
#include <cstdlib>


class WeakSingleThreadedUtility
{
public:
  WeakSingleThreadedUtility()
      // To ensure that singleton will be constucted before utility
      : m_weak(SingletonWeak<Payload>::instance())
  {
  }

  ~WeakSingleThreadedUtility()
  {
    // Sometimes this check may result as "false" even in case of incorrect usage,
    // and there's no way to guarantee a demonstration of undefined behaviour in colour
    if ( auto strong = m_weak.lock() )
      for ( int i = 0; i < 100; ++i )
        strong->add(i);
  }

private:
  // A weak copy of smart pointer, not a reference
  std::weak_ptr<SingletonWeak<Payload>> m_weak;
};


void cracker()
{
  WeakSingleThreadedUtility();
}


// 1. Register cracker() using std::atexit
// 2. Create singleton
// 3. Create utility
auto reg = [](){ std::atexit(&cracker); return 0; }();
auto utility = WeakSingleThreadedUtility();

// This guarantee destruction in order:
// - utility;
// - singleton.
// This order is correct.
// Additionally, there's a copy of shared_ptr in the class instance...
// ... but there was std::atexit registered before singleton,
// so cracker() will be invoked after destruction of utility and singleton.
// There's second try to create a singleton - and it's incorrect.


int main()
{
  return 0;
}
