#pragma once

#include "SingletonePayload.h"

#include <memory>


class SingletoneShared : public SingletonePayload
{
public:
  ~SingletoneShared() = default;

  SingletoneShared(const SingletoneShared &) = delete;
  SingletoneShared(SingletoneShared &&) = delete;

  SingletoneShared& operator=(const SingletoneShared &) = delete;
  SingletoneShared& operator=(SingletoneShared &&) = delete;

  static std::shared_ptr<SingletoneShared> instance()
  {
    // "new" and no std::make_shared because of private c-tor
    static auto inst = std::shared_ptr<SingletoneShared>(new SingletoneShared);
    return inst;
  }

private:
  SingletoneShared() = default;
};
