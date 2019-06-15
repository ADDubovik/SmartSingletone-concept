#pragma once

#include <memory>
#include <iostream>


template<typename T>
class SingletonWeak : public T
{
public:
  ~SingletonWeak()
  {
    std::cout << "~SingletonWeak()" << std::endl;
  }

  SingletonWeak(const SingletonWeak &) = delete;
  SingletonWeak(SingletonWeak &&) = delete;

  SingletonWeak& operator=(const SingletonWeak &) = delete;
  SingletonWeak& operator=(SingletonWeak &&) = delete;

  static std::weak_ptr<SingletonWeak> instance()
  {
    std::cout << "instance()" << std::endl;
    // "new" and no std::make_shared because of private c-tor
    static auto inst = std::shared_ptr<SingletonWeak>(new SingletonWeak);
    return inst;
  }

private:
  SingletonWeak()
  {
    std::cout << "SingletonWeak()" << std::endl;
  }
};
