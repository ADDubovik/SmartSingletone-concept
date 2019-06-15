#include "SingletonShared.h"
#include <Payload.h>

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
    if ( auto instance = SingletonShared<Payload>::instance() )
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
// This order is correct


int main()
{
  return 0;
}
