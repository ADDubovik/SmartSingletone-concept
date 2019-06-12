#include "SingletonClassic.h"


class ClassicSingleThreadedUser
{
public:
  ClassicSingleThreadedUser() = default;

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

  // This will cause destruction in order:
  // - singletone;
  // - user.
  // This order is incorrect.

	return 0;
}
