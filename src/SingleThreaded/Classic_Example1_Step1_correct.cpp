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
  // 1. Create singletone
  SingletonClassic::instance();
  // 2. Create user
  createStaticUtility();

  // This guarantee destruction in order:
  // - user;
  // - singletone.
  // This order is correct.

	return 0;
}
