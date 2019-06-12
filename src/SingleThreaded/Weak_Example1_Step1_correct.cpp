#include "SingletonWeak.h"

#include <memory>


class WeakSingleThreadedUser
{
public:
  WeakSingleThreadedUser()
      // To ensure that singletone will be constucted before user
      : m_weak(SingletonWeak::instance())
  {
  }

  ~WeakSingleThreadedUser()
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


auto& getEmptyStaticUniqueUser()
{
  static std::unique_ptr<WeakSingleThreadedUser> emptyUnique;
  return emptyUnique;
}


auto& getStaticUniqueUser()
{
  static auto userUnique = std::make_unique<WeakSingleThreadedUser>();
  return userUnique;
}


int main()
{
  // 1. Create an empty unique_ptr
  getEmptyStaticUniqueUser();
  // 2. Create singletone (because of modified WeakSingleThreadedUser c-tor)
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
  // so destruction order is incorrect...

  // ... but user have made a weak copy of shared_ptr when it was available,
  // so it's correct again.

	return 0;
}
