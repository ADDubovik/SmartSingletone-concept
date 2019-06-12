#pragma once

#include "SingletonPayload.h"

#include <memory>


class SingletonShared : public SingletonPayload
{
public:
  ~SingletonShared() = default;

  SingletonShared(const SingletonShared &) = delete;
  SingletonShared(SingletonShared &&) = delete;

  SingletonShared& operator=(const SingletonShared &) = delete;
  SingletonShared& operator=(SingletonShared &&) = delete;

  static std::shared_ptr<SingletonShared> instance()
  {
    // "new" and no std::make_shared because of private c-tor
    static auto inst = std::shared_ptr<SingletonShared>(new SingletonShared);
    return inst;
  }

private:
  SingletonShared() = default;
};
