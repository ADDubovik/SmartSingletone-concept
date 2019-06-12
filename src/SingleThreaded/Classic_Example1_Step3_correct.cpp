#include "SingletonClassic.h"


class ClassicSingleThreadedUtility
{
public:
  ClassicSingleThreadedUtility()
  {
    // To ensure that singletone will be constucted before utility
    SingletonClassic::instance();
  }

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

// This seems to guarantee destruction in order:
// - singletone;
// - utility.
// This order is incorrect.
// But ClassicSingleThreadedUtility c-tor was modified to prevent this.


int main()
{
	return 0;
}
