#include "SingletonShared.h"

#include <memory>


class SharedSingleThreadedUtility
{
public:
  SharedSingleThreadedUtility()
  {
    // To ensure that singletone will be constucted before user
    SingletonShared::instance();
  }

  ~SharedSingleThreadedUtility()
  {
    // Sometimes this check may result as "false" even for destroyed singleton
    // preventing from visual effects of undefined behaviour ...
    //if ( auto instance = SingletonShared::instance() )
    //  for ( int i = 0; i < 100; ++i )
    //    instance->add(i);

    // ... so this code will demonstrate UB in colour
    auto instance = SingletonShared::instance();
    for ( int i = 0; i < 100; ++i )
      instance->add(i);
  }
};


auto& getEmptyStaticUniqueUtility()
{
  static std::unique_ptr<SharedSingleThreadedUtility> emptyUnique;
  return emptyUnique;
}


auto& getStaticUniqueUtility()
{
  static auto userUnique = std::make_unique<SharedSingleThreadedUtility>();
  return userUnique;
}


int main()
{
  // 1. Create an empty unique_ptr
  getEmptyStaticUniqueUtility();
  // 2. Create singletone (because of modified SharedSingleThreadedUtility c-tor)
  // 3. Create user
  getStaticUniqueUtility();

  // This guarantee destruction in order:
  // - userUnique;
  // - singletone;
  // - emptyUnique.
  // This order is correct ...
  // ... but we swap unique_ptrs
  getEmptyStaticUniqueUtility().swap(getStaticUniqueUtility());

  // Guaranteed destruction order is the same:
  // - userUnique;
  // - singletone;
  // - emptyUnique,
  // but now userUnique is empty, and userUnique is filled,
  // so destruction order is incorrect

	return 0;
}
