#pragma once

#include <set>


class SingletonPayload
{
public:
  SingletonPayload() = default;
  ~SingletonPayload() = default;

  SingletonPayload(const SingletonPayload &) = delete;
  SingletonPayload(SingletonPayload &&) = delete;

  SingletonPayload& operator=(const SingletonPayload &) = delete;
  SingletonPayload& operator=(SingletonPayload &&) = delete;

  void add(int value)
  {
    m_data.emplace(value);
  }

private:
  std::set<int> m_data;
};
