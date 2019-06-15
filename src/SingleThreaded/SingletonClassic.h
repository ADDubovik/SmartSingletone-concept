#pragma once

#include "SingletonPayload.h"

#include <iostream>


class SingletonClassic : public SingletonPayload
{
public:
  ~SingletonClassic()
  {
    std::cout << "~SingletonClassic()" << std::endl;
  }

  SingletonClassic(const SingletonClassic &) = delete;
  SingletonClassic(SingletonClassic &&) = delete;

  SingletonClassic& operator=(const SingletonClassic &) = delete;
  SingletonClassic& operator=(SingletonClassic &&) = delete;

  static SingletonClassic& instance()
  {
    std::cout << "instance()" << std::endl;
    static SingletonClassic inst;
    return inst;
  }

private:
  SingletonClassic()
  {
    std::cout << "SingletonClassic()" << std::endl;
  }
};
