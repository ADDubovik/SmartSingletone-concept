#include "SingletonShared.h"

#include <memory>
#include <cstdlib>


class SharedSingleThreadedUtility
{
public:
  SharedSingleThreadedUtility()
      // To ensure that singletone will be constucted before utility
      : m_singletone(SingletonShared::instance())
  {
  }

  ~SharedSingleThreadedUtility()
  {
    // Sometimes this check may result as "false" even for destroyed singletone
    // preventing from visual effects of undefined behaviour ...
    //if ( m_singletone )
    //  for ( int i = 0; i < 100; ++i )
    //    m_singletone->add(i);

    // ... so this code will allow to demonstrate UB in colour
    for ( int i = 0; i < 100; ++i )
      m_singletone->add(i);
  }

private:
  // A copy of smart pointer, not a reference
  std::shared_ptr<SingletonShared> m_singletone;
};


void cracker()
{
  SharedSingleThreadedUtility();
}


// 1. Register cracker() using std::atexit
// 2. Create singletone
// 3. Create utility
auto reg = [](){ std::atexit(&cracker); return 0; }();
auto utility = SharedSingleThreadedUtility();

// This guarantee destruction in order:
// - utility;
// - singletone.
// This order is correct.
// Additionally, there's a copy of shared_ptr in the class instance...
// ... but there was std::atexit registered before singletone,
// so cracker() will be invoked after destruction of utility and singletone.
// There's second try to create a singletone - and it's incorrect.


int main()
{
	return 0;
}
