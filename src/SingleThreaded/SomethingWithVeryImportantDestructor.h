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

  SomethingWithVeryImportantDestructor(const SomethingWithVeryImportantDestructor &) = delete;
  SomethingWithVeryImportantDestructor(SomethingWithVeryImportantDestructor &&) = delete;

  SomethingWithVeryImportantDestructor& operator=(const SomethingWithVeryImportantDestructor &) = delete;
  SomethingWithVeryImportantDestructor& operator=(SomethingWithVeryImportantDestructor &&) = delete;
};
