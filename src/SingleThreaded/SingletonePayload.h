#pragma once

#include <set>


class SingletonePayload
{
public:
  SingletonePayload() = default;
  ~SingletonePayload() = default;

  SingletonePayload(const SingletonePayload &) = delete;
  SingletonePayload(SingletonePayload &&) = delete;

  SingletonePayload& operator=(const SingletonePayload &) = delete;
  SingletonePayload& operator=(SingletonePayload &&) = delete;

  void add(int value)
  {
    m_data.emplace(value);
  }

private:
  std::set<int> m_data;
};
