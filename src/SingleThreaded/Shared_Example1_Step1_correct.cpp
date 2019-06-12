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
    if ( auto instance = SingletonShared::instance() )
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
  // This order is correct

	return 0;
}
