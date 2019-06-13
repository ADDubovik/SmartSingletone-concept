#include "SingletonClassic.h"

#include <memory>


class ClassicSingleThreadedUtility
{
public:
  ClassicSingleThreadedUtility()
  {
    thread_local auto semaphore_strong = std::make_shared<char>(0);
    m_semaphore_weak = semaphore_strong;
  }

  ~ClassicSingleThreadedUtility()
  {
    if ( m_semaphore_weak.lock() )
      for ( int i = 0; i < 100; ++i )
        SingletonClassic::instance().add(i);
  }

private:
  std::weak_ptr<char> m_semaphore_weak;
};


// 1. Create an empty unique_ptr
// 2. Create singletone (because of modified ClassicSingleThreadedUtility c-tor)
// 3. Create utility
std::unique_ptr<ClassicSingleThreadedUtility> emptyUnique;
auto utilityUnique = std::make_unique<ClassicSingleThreadedUtility>();

// This guarantee destruction in order:
// - utilityUnique;
// - singletone;
// - emptyUnique.
// This order seems to be correct ...


int main()
{
  // ... but user swaps unique_ptrs
  emptyUnique.swap(utilityUnique);

  // Guaranteed destruction order is still the same:
  // - utilityUnique;
  // - singletone;
  // - emptyUnique,
  // but now utilityUnique is empty, and emptyUnique is filled,
  // so destruction order is incorrect ...
  // ... but utility uses a variable with thread storage duration to detect thread termination.

	return 0;
}
