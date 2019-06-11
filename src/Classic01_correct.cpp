#include "SingletoneClassic.h"


class ClassicSingleThreadedUser
{
public:
  ClassicSingleThreadedUser() = default;
  ~ClassicSingleThreadedUser()
  {
    auto &instance = SingletoneClassic::instance();
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
  // 1. Create singletone
  SingletoneClassic::instance();
  // 2. Create user
  createStaticUser();

  // This guarantee destruction in order:
  // - user;
  // - singletone.
  // This order is correct.

	return 0;
}
