#include "SingletonClassic.h"


class ClassicSingleThreadedUtility
{
public:
  ClassicSingleThreadedUtility()
  {
    // To ensure that singletone will be constucted before user
    SingletonClassic::instance();
  }

  ~ClassicSingleThreadedUtility()
  {
    auto &instance = SingletonClassic::instance();
    for ( int i = 0; i < 100; ++i )
      instance.add(i);
  }
};


void createStaticUtility()
{
  static auto user = ClassicSingleThreadedUtility();
}


int main()
{
  // 1. Create user
  createStaticUtility();
  // 2. Create singletone
  SingletonClassic::instance();

  // This seems to guarantee destruction in order:
  // - singletone;
  // - user.
  // This order is incorrect.
  // But ClassicSingleThreadedUtility c-tor was modified to prevent this.

	return 0;
}
