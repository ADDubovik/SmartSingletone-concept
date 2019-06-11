#pragma once

#include <set>
#include <memory>


class SingletoneWeak
{
public:
  ~SingletoneWeak() = default;

  SingletoneWeak(const SingletoneWeak &) = delete;
  SingletoneWeak(SingletoneWeak &&) = delete;

  SingletoneWeak& operator=(const SingletoneWeak &) = delete;
  SingletoneWeak& operator=(SingletoneWeak &&) = delete;

  static std::weak_ptr<SingletoneWeak> instance()
  {
    // "new" and no std::make_shared because of private c-tor
    static auto inst = std::shared_ptr<SingletoneWeak>(new SingletoneWeak);
    return inst;
  }

  void add(int value)
  {
    m_data.emplace(value);
  }

private:
  SingletoneWeak() = default;

  std::set<int> m_data;
};
