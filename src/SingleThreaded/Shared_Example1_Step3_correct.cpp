#include "SingletonShared.h"

#include <memory>


class SharedSingleThreadedUtility
{
public:
  SharedSingleThreadedUtility()
      // To ensure that singletone will be constucted before utility
      : m_singletone(SingletonShared::instance())
  {
  }

  ~SharedSingleThreadedUtility()
  {
    // Sometimes this check may result as "false" even for destroyed singletone
    // preventing from visual effects of undefined behaviour ...
    //if ( m_singletone )
    //  for ( int i = 0; i < 100; ++i )
    //    m_singletone->add(i);

    // ... so this code will demonstrate UB in colour
    for ( int i = 0; i < 100; ++i )
      m_singletone->add(i);
  }

private:
  // A copy of smart pointer, not a reference
  std::shared_ptr<SingletonShared> m_singletone;
};


auto& getEmptyStaticUniqueUtility()
{
  static std::unique_ptr<SharedSingleThreadedUtility> emptyUnique;
  return emptyUnique;
}


auto& getStaticUniqueUtility()
{
  static auto utilityUnique = std::make_unique<SharedSingleThreadedUtility>();
  return utilityUnique;
}


int main()
{
  // 1. Create an empty unique_ptr
  getEmptyStaticUniqueUtility();
  // 2. Create singletone (because of modified SharedSingleThreadedUtility c-tor)
  // 3. Create utility
  getStaticUniqueUtility();

  // This guarantee destruction in order:
  // - utilityUnique;
  // - singletone;
  // - emptyUnique.
  // This order is correct ...
  // ... but we swap unique_ptrs
  getEmptyStaticUniqueUtility().swap(getStaticUniqueUtility());

  // Guaranteed destruction order is the same:
  // - utilityUnique;
  // - singletone;
  // - emptyUnique,
  // but now utilityUnique is empty, and utilityUnique is filled,
  // so destruction order is incorrect...

  // ... but utility have made a copy of shared_ptr when it was available,
  // so it's correct again.

	return 0;
}
