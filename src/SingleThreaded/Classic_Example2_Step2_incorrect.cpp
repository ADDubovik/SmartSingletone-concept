#include "SingletonClassic.h"

#include <memory>


class ClassicSingleThreadedUtility
{
public:
  ClassicSingleThreadedUtility()
  {
    // To ensure that singletone will be constucted before user
    SingletonClassic::instance();
  }

  ~ClassicSingleThreadedUtility()
  {
    auto &instance = SingletonClassic::instance();
    for ( int i = 0; i < 100; ++i )
      instance.add(i);
  }
};


auto& getEmptyStaticUniqueUtility()
{
  static std::unique_ptr<ClassicSingleThreadedUtility> emptyUnique;
  return emptyUnique;
}


auto& getStaticUniqueUtility()
{
  static auto userUnique = std::make_unique<ClassicSingleThreadedUtility>();
  return userUnique;
}


int main()
{
  // 1. Create an empty unique_ptr
  getEmptyStaticUniqueUtility();
  // 2. Create singletone (because of modified ClassicSingleThreadedUtility c-tor)
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
