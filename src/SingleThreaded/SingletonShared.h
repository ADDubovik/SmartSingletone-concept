#pragma once

#include "SingletonPayload.h"

#include <memory>
#include <iostream>


class SingletonShared : public SingletonPayload
{
public:
  ~SingletonShared()
  {
    std::cout << "~SingletonShared()" << std::endl;
  }

  SingletonShared(const SingletonShared &) = delete;
  SingletonShared(SingletonShared &&) = delete;

  SingletonShared& operator=(const SingletonShared &) = delete;
  SingletonShared& operator=(SingletonShared &&) = delete;

  static std::shared_ptr<SingletonShared> instance()
  {
    std::cout << "instance()" << std::endl;
    // "new" and no std::make_shared because of private c-tor
    static auto inst = std::shared_ptr<SingletonShared>(new SingletonShared);
    return inst;
  }

private:
  SingletonShared()
  {
    std::cout << "SingletonShared()" << std::endl;
  }
};
