#pragma once

#include <iostream>


template<typename T>
class SingletonClassic : public T
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
