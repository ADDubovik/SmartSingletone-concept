#include "SingletonClassic.h"


class ClassicSingleThreadedUtility
{
public:
  ClassicSingleThreadedUtility() = default;

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

  // This will cause destruction in order:
  // - singletone;
  // - user.
  // This order is incorrect.

	return 0;
}
