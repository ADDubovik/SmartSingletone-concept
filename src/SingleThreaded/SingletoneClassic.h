#pragma once

#include <set>


class SingletoneClassic
{
public:
  ~SingletoneClassic() = default;

  SingletoneClassic(const SingletoneClassic &) = delete;
  SingletoneClassic(SingletoneClassic &&) = delete;

  SingletoneClassic& operator=(const SingletoneClassic &) = delete;
  SingletoneClassic& operator=(SingletoneClassic &&) = delete;

  static SingletoneClassic& instance()
  {
    static SingletoneClassic inst;
    return inst;
  }

  void add(int value)
  {
    m_data.emplace(value);
  }

private:
  SingletoneClassic() = default;

  std::set<int> m_data;
};
