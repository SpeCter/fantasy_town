#pragma once
#include <cstdint>
#include "Type.hpp"
#include <string>

struct Entity;

namespace flak
{
  namespace Components
  {
    struct BaseComponent
    {
      BaseComponent()
      {
      }
      virtual ~BaseComponent() = default;
      virtual const std::string GetName() = 0;
      uint64_t m_type;
      uint64_t m_entity_id;
    };

    template<typename T>
    struct Component : public BaseComponent
    {
      Component()
      {
        m_type = Type::value<T>();
      }
    };
  }
}

