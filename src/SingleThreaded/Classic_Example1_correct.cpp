#include "SingletonClassic.h"
#include "Payload.h"

#include <memory>


class ClassicSingleThreadedUtility
{
public:
  ClassicSingleThreadedUtility()
  {
    // To ensure that singleton will be constucted before utility
    SingletonClassic<Payload>::instance();
  }

  ~ClassicSingleThreadedUtility()
  {
    auto &instance = SingletonClassic<Payload>::instance();
    for ( int i = 0; i < 100; ++i )
      instance.add(i);
  }
};


// 1. Create an empty unique_ptr
// 2. Create singleton (because of modified ClassicSingleThreadedUtility c-tor)
// 3. Create utility
std::unique_ptr<ClassicSingleThreadedUtility> emptyUnique;
auto utilityUnique = std::make_unique<ClassicSingleThreadedUtility>();

// This guarantee destruction in order:
// - utilityUnique;
// - singleton;
// - emptyUnique.
// This order is correct


int main()
{
  return 0;
}
