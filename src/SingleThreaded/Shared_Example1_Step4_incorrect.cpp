#include "SingletoneShared.h"

#include <memory>
#include <cstdlib>


class SharedSingleThreadedUser
{
public:
  SharedSingleThreadedUser()
      // To ensure that singletone will be constucted before user
      : m_singletone(SingletoneShared::instance())
  {
  }

  ~SharedSingleThreadedUser()
  {
    // Sometimes this check may result as "false" even for destroyed singletone
    // preventing from visual effects of undefined behaviour ...
    //if ( m_singletone )
    //  for ( int i = 0; i < 100; ++i )
    //    m_singletone->add(i);

    // ... so this code will demonstrate UB in colour
    for ( int i = 0; i < 100; ++i )
      m_singletone->add(i);
  }

private:
  // A copy of smart pointer, not a reference
  std::shared_ptr<SingletoneShared> m_singletone;
};


void getStaticUser()
{
  static auto user = SharedSingleThreadedUser();
}


void cracker()
{
  SharedSingleThreadedUser();
}


int main()
{
  // 1. Register cracker() using std::atexit
  std::atexit(&cracker);
  // 2. Create singletone
  // 3. Create user
  getStaticUser();

  // This guarantee destruction in order:
  // - user;
  // - singletone.
  // This order is correct.
  // Additionally, there's a copy of shared_ptr in the class instance...

  // ... but there's std::atexit registered before singletone,
  // so cracker() will be invoked after destruction of user and singletone.
  // There's second try to create a singletone - and it's incorrect.

	return 0;
}
