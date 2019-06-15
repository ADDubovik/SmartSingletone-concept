#include "SingletonWeak.h"
#include "Payload.h"

#include <memory>


class WeakSingleThreadedUtility
{
public:
  WeakSingleThreadedUtility()
      // To ensure that singleton will be constucted before utility
      : m_weak(SingletonWeak<Payload>::instance())
  {
  }

  ~WeakSingleThreadedUtility()
  {
    // Sometimes this check may result as "false" even in case of incorrect usage,
    // and there's no way to guarantee a demonstration of undefined behaviour in colour
    if ( auto strong = m_weak.lock() )
      for ( int i = 0; i < 100; ++i )
        strong->add(i);
  }

private:
  // A weak copy of smart pointer, not a reference
  std::weak_ptr<SingletonWeak<Payload>> m_weak;
};


// 1. Create an empty unique_ptr
// 2. Create singleton (because of WeakSingleThreadedUtility c-tor)
// 3. Create utility
std::unique_ptr<WeakSingleThreadedUtility> emptyUnique;
auto utilityUnique = std::make_unique<WeakSingleThreadedUtility>();


int main()
{
  // This guarantee destruction in order:
  // - utilityUnique;
  // - singleton;
  // - emptyUnique.
  // This order is correct ...
  // ... but user swaps unique_ptrs
  emptyUnique.swap(utilityUnique);

  // Guaranteed destruction order is the same:
  // - utilityUnique;
  // - singleton;
  // - emptyUnique,
  // but now utilityUnique is empty, and emptyUnique is filled,
  // so destruction order is incorrect...

  // ... but utility have made a weak copy of shared_ptr when it was available,
  // so it's correct again.

  return 0;
}
