#pragma once

#include "SingletonPayload.h"

#include <memory>


class SingletonWeak : public SingletonPayload
{
public:
  ~SingletonWeak() = default;

  SingletonWeak(const SingletonWeak &) = delete;
  SingletonWeak(SingletonWeak &&) = delete;

  SingletonWeak& operator=(const SingletonWeak &) = delete;
  SingletonWeak& operator=(SingletonWeak &&) = delete;

  static std::weak_ptr<SingletonWeak> instance()
  {
    // "new" and no std::make_shared because of private c-tor
    static auto inst = std::shared_ptr<SingletonWeak>(new SingletonWeak);
    return inst;
  }

private:
  SingletonWeak() = default;
};
