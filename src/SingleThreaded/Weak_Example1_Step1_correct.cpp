#include "SingletonWeak.h"

#include <memory>


class WeakSingleThreadedUtility
{
public:
  WeakSingleThreadedUtility()
      // To ensure that singletone will be constucted before utility
      : m_weak(SingletonWeak::instance())
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
  std::weak_ptr<SingletonWeak> m_weak;
};


auto& getEmptyStaticUniqueUtility()
{
  static std::unique_ptr<WeakSingleThreadedUtility> emptyUnique;
  return emptyUnique;
}


auto& getStaticUniqueUtility()
{
  static auto utilityUnique = std::make_unique<WeakSingleThreadedUtility>();
  return utilityUnique;
}


int main()
{
  // 1. Create an empty unique_ptr
  getEmptyStaticUniqueUtility();
  // 2. Create singletone (because of modified WeakSingleThreadedUtility c-tor)
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

  // ... but utility have made a weak copy of shared_ptr when it was available,
  // so it's correct again.

	return 0;
}
