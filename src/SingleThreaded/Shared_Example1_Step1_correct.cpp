#include "SingletonShared.h"

#include <memory>


class SharedSingleThreadedUtility
{
public:
  SharedSingleThreadedUtility()
  {
    // To ensure that singletone will be constucted before utility
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
  // This order is correct

	return 0;
}
