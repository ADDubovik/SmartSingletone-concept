#pragma once

#include <set>


class Payload
{
public:
  Payload() = default;
  ~Payload() = default;

  Payload(const Payload &) = delete;
  Payload(Payload &&) = delete;

  Payload& operator=(const Payload &) = delete;
  Payload& operator=(Payload &&) = delete;

  void add(int value)
  {
    m_data.emplace(value);
  }

private:
  std::set<int> m_data;
};
