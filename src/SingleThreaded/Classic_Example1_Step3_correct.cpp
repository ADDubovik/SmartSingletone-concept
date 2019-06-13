#include "SingletonClassic.h"

#include <memory>
#include <iostream>


class ClassicSingleThreadedUtility
{
public:
  ClassicSingleThreadedUtility()
  {
    thread_local auto flag_strong = std::make_shared<char>(0);
    m_flag_weak = flag_strong;

    SingletonClassic::instance();
  }

  ~ClassicSingleThreadedUtility()
  {
    if ( m_flag_weak.lock() )
    {
      std::cout << "Normal processing" << std::endl;
      for ( int i = 0; i < 100; ++i )
        SingletonClassic::instance().add(i);
    }
  }

private:
  std::weak_ptr<char> m_flag_weak;
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

  {
    // To demonstrate normal processing before application ends
    auto utility = ClassicSingleThreadedUtility();
  }

  // Guaranteed destruction order is still the same:
  // - utilityUnique;
  // - singletone;
  // - emptyUnique,
  // but now utilityUnique is empty, and emptyUnique is filled,
  // so destruction order is incorrect ...
  // ... but utility uses a variable with thread storage duration to detect thread termination.

	return 0;
}
