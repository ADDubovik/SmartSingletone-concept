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


// 1. Create utility
// 2. Create singletone
auto utility = ClassicSingleThreadedUtility();
auto &singleton = SingletonClassic::instance();

// This guarantee destruction in order:
// - singletone;
// - utility.
// This order is incorrect.


int main()
{
	return 0;
}
