#pragma once

#include <set>
#include <mutex>


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

  void add(double d)
  {
    std::lock_guard<std::mutex> guard(m_data.first);
    m_data.second.emplace(d);
  }

private:
  SingletoneClassic() = default;

  std::pair<std::mutex, std::set<double>> m_data;
};
