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


// 1. Create singletone
// 2. Create utility
auto &singleton = SingletonClassic::instance();
auto utility = ClassicSingleThreadedUtility();

// This guarantee destruction in order:
// - utility;
// - singletone.
// This order is correct.


int main()
{
	return 0;
}
