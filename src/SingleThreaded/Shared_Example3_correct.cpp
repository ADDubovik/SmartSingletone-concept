#include "SingletonShared.h"

#include <memory>


class SharedSingleThreadedUtility
{
public:
  SharedSingleThreadedUtility()
      // To ensure that singleton will be constucted before utility
      : m_singleton(SingletonShared::instance())
  {
  }

  ~SharedSingleThreadedUtility()
  {
    // Sometimes this check may result as "false" even for destroyed singleton
    // preventing from visual effects of undefined behaviour ...
    //if ( m_singleton )
    //  for ( int i = 0; i < 100; ++i )
    //    m_singleton->add(i);

    // ... so this code will allow to demonstrate UB in colour
    for ( int i = 0; i < 100; ++i )
      m_singleton->add(i);
  }

private:
  // A copy of smart pointer, not a reference
  std::shared_ptr<SingletonShared> m_singleton;
};


// 1. Create an empty unique_ptr
// 2. Create singleton (because of SharedSingleThreadedUtility c-tor)
// 3. Create utility
std::unique_ptr<SharedSingleThreadedUtility> emptyUnique;
auto utilityUnique = std::make_unique<SharedSingleThreadedUtility>();


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

  // ... but utility have made a copy of shared_ptr when it was available,
  // so it's correct again.

  return 0;
}
