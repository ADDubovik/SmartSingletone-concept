#pragma once

#include "SingletonePayload.h"

#include <set>


class SingletoneClassic : public SingletonePayload
{
public:
  ~SingletoneClassic() = default;

  SingletoneClassic(const SingletoneClassic &) = delete;
  SingletoneClassic(SingletoneClassic &&) = delete;

  SingletoneClassic& operator=(const SingletoneClassic &) = delete;
  SingletoneClassic& operator=(SingletoneClassic &&) = delete;

  static SingletoneClassic& instance()
  {
    static SingletoneClassic inst;
    return inst;
  }

private:
  SingletoneClassic() = default;
};
