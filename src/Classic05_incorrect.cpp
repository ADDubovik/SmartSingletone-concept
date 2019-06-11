#include "SingletoneClassic.h"

#include <memory>


class ClassicSingleThreadedUser
{
public:
  ClassicSingleThreadedUser()
  {
    // To ensure that singletone will be constucted before user
    auto &instance = SingletoneClassic::instance();
  }

  ~ClassicSingleThreadedUser()
  {
    auto &instance = SingletoneClassic::instance();
    for ( int i = 0; i < 100; ++i )
      instance.add(i);
  }
};


auto& getEmptyStaticUniqueUser()
{
  static std::unique_ptr<ClassicSingleThreadedUser> emptyUnique;
  return emptyUnique;
}


auto& getStaticUniqueUser()
{
  static auto userUnique = std::make_unique<ClassicSingleThreadedUser>();
  return userUnique;
}


int main()
{
  // 1. Create an empty unique_ptr
  getEmptyStaticUniqueUser();
  // 2. Create singletone (because of modified ClassicSingleThreadedUser c-tor)
  // 3. Create user
  getStaticUniqueUser();

  // This guarantee destruction in order:
  // - userUnique;
  // - singletone;
  // - emptyUnique.
  // This order is correct ...
  // ... but we swap unique_ptrs
  getEmptyStaticUniqueUser().swap(getStaticUniqueUser());

  // Guaranteed destruction order is the same:
  // - userUnique;
  // - singletone;
  // - emptyUnique,
  // but now userUnique is empty, and userUnique is filled,
  // so destruction order is incorrect

	return 0;
}
