#include "SingletonWeak.h"

#include <memory>
#include <cstdlib>


class WeakSingleThreadedUtility
{
public:
  WeakSingleThreadedUtility()
      // To ensure that singletone will be constucted before utility
      : m_weak(SingletonWeak::instance())
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
  std::weak_ptr<SingletonWeak> m_weak;
};


void getStaticUtility()
{
  static auto utility = WeakSingleThreadedUtility();
}


void cracker()
{
  WeakSingleThreadedUtility();
}


int main()
{
  // 1. Register cracker() using std::atexit
  std::atexit(&cracker);
  // 2. Create singletone
  // 3. Create utility
  getStaticUtility();

  // This guarantee destruction in order:
  // - utility;
  // - singletone.
  // This order is correct.
  // Additionally, there's a copy of shared_ptr in the class instance...

  // ... but there's std::atexit registered before singletone,
  // so cracker() will be invoked after destruction of utility and singletone.
  // There's second try to create a singletone - and it's incorrect.

	return 0;
}
