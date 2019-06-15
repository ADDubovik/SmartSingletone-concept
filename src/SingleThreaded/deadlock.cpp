#include <memory>
#include <iostream>
#include <functional>


class SingletonShared
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

  void setCallback(std::function<void()> &&fn)
  {
    m_callbackFn = std::move(fn);
  }

private:
  SingletonShared()
  {
    std::cout << "SingletonShared()" << std::endl;
  }

  std::function<void()> m_callbackFn;
};


int main()
{
  SingletonShared::instance()->setCallback(
      [capture = SingletonShared::instance()](){}
  );

  return 0;
}
