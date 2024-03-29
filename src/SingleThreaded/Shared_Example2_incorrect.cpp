#include "SingletonShared.h"
#include "Payload.h"

#include <memory>


class SharedSingleThreadedUtility
{
public:
  SharedSingleThreadedUtility()
  {
    // To ensure that singleton will be constucted before utility
    SingletonShared<Payload>::instance();
  }

  ~SharedSingleThreadedUtility()
  {
    // Sometimes this check may result as "false" even for destroyed singleton
    // preventing from visual effects of undefined behaviour ...
    //if ( auto instance = SingletonShared::instance() )
    //  for ( int i = 0; i < 100; ++i )
    //    instance->add(i);

    // ... so this code will demonstrate UB in colour
    auto instance = SingletonShared<Payload>::instance();
    for ( int i = 0; i < 100; ++i )
      instance->add(i);
  }
};


// 1. Create an empty unique_ptr
// 2. Create singleton (because of modified SharedSingleThreadedUtility c-tor)
// 3. Create utility
std::unique_ptr<SharedSingleThreadedUtility> emptyUnique;
auto utilityUnique = std::make_unique<SharedSingleThreadedUtility>();

// This guarantee destruction in order:
// - utilityUnique;
// - singleton;
// - emptyUnique.
// This order seems to be correct ...


int main()
{
  // ... but user swaps unique_ptrs
  emptyUnique.swap(utilityUnique);

  // Guaranteed destruction order is the same:
  // - utilityUnique;
  // - singleton;
  // - emptyUnique,
  // but now utilityUnique is empty, and emptyUnique is filled,
  // so destruction order is incorrect

  return 0;
}
