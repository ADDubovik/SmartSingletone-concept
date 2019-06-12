#include "SingletonClassic.h"


class ClassicSingleThreadedUser
{
public:
  ClassicSingleThreadedUser()
  {
    // To ensure that singletone will be constucted before user
    SingletonClassic::instance();
  }

  ~ClassicSingleThreadedUser()
  {
    auto &instance = SingletonClassic::instance();
    for ( int i = 0; i < 100; ++i )
      instance.add(i);
  }
};


void createStaticUser()
{
  static auto user = ClassicSingleThreadedUser();
}


int main()
{
  // 1. Create user
  createStaticUser();
  // 2. Create singletone
  SingletonClassic::instance();

  // This seems to guarantee destruction in order:
  // - singletone;
  // - user.
  // This order is incorrect.
  // But ClassicSingleThreadedUser c-tor was modified to prevent this.

	return 0;
}
