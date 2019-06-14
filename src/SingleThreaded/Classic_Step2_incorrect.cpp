#include "SingletonClassic.h"

#include <memory>


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


// 1. Create an empty unique_ptr
// 2. Create singletone (because of modified ClassicSingleThreadedUtility c-tor)
// 3. Create utility
std::unique_ptr<ClassicSingleThreadedUtility> emptyUnique;
auto utilityUnique = std::make_unique<ClassicSingleThreadedUtility>();

// This guarantee destruction in order:
// - utilityUnique;
// - singletone;
// - emptyUnique.
// This order seems to be correct ...


int main()
{
  // ... but user swaps unique_ptrs
  emptyUnique.swap(utilityUnique);

  // Guaranteed destruction order is still the same:
  // - utilityUnique;
  // - singletone;
  // - emptyUnique,
  // but now utilityUnique is empty, and emptyUnique is filled,
  // so destruction order is incorrect

  return 0;
}
