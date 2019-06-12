#include "SingletonShared.h"

#include <memory>


class SharedSingleThreadedUser
{
public:
  SharedSingleThreadedUser()
  {
    // To ensure that singletone will be constucted before user
    SingletonShared::instance();
  }

  ~SharedSingleThreadedUser()
  {
    if ( auto instance = SingletonShared::instance() )
      for ( int i = 0; i < 100; ++i )
        instance->add(i);
  }
};


auto& getEmptyStaticUniqueUser()
{
  static std::unique_ptr<SharedSingleThreadedUser> emptyUnique;
  return emptyUnique;
}


auto& getStaticUniqueUser()
{
  static auto userUnique = std::make_unique<SharedSingleThreadedUser>();
  return userUnique;
}


int main()
{
  // 1. Create an empty unique_ptr
  getEmptyStaticUniqueUser();
  // 2. Create singletone (because of modified SharedSingleThreadedUser c-tor)
  // 3. Create user
  getStaticUniqueUser();

  // This guarantee destruction in order:
  // - userUnique;
  // - singletone;
  // - emptyUnique.
  // This order is correct

	return 0;
}
