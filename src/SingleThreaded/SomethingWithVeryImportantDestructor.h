#pragma once

#include <iostream>


class SomethingWithVeryImportantDestructor
{
public:
  SomethingWithVeryImportantDestructor()
  {
    std::cout << "SomethingWithVeryImportantDestructor()" << std::endl;
  }
  ~SomethingWithVeryImportantDestructor()
  {
    std::cout << "~SomethingWithVeryImportantDestructor()" << std::endl;
  }

  SomethingWithVeryImportantDestructor(const SomethingWithVeryImportantDestructor &) = default;
  SomethingWithVeryImportantDestructor(SomethingWithVeryImportantDestructor &&) = default;

  SomethingWithVeryImportantDestructor& operator=(const SomethingWithVeryImportantDestructor &) = default;
  SomethingWithVeryImportantDestructor& operator=(SomethingWithVeryImportantDestructor &&) = default;
};
