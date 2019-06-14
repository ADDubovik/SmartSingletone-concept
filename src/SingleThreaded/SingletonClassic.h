#pragma once

#include "SingletonPayload.h"


class SingletonClassic : public SingletonPayload
{
public:
  ~SingletonClassic() = default;

  SingletonClassic(const SingletonClassic &) = delete;
  SingletonClassic(SingletonClassic &&) = delete;

  SingletonClassic& operator=(const SingletonClassic &) = delete;
  SingletonClassic& operator=(SingletonClassic &&) = delete;

  static SingletonClassic& instance()
  {
    static SingletonClassic inst;
    return inst;
  }

private:
  SingletonClassic() = default;
};
