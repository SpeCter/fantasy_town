#pragma once
#include <cstdint>

class Type
{
public:
  template<typename T>
  static uint64_t value()
  {
    static uint64_t id = counter++;
    return id;
  }
private:
  static uint64_t counter;
};


