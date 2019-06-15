#include "SingletonShared.h"
#include "CallbackPayload.h"
#include "SomethingWithVeryImportantDestructor.h"


int main()
{
  SingletonShared<CallbackPayload>::instance()->setCallback(
      [
        capture = SingletonShared<CallbackPayload>::instance(),
        something = std::make_shared<SomethingWithVeryImportantDestructor>()
      ]
      ()
      {}
  );

  return 0;
}
