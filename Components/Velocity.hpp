#pragma once
#include "Component.hpp"

class Entity;

namespace flak
{
  namespace Components
  {
    struct Velocity : public Component<Velocity>
    {
      Velocity(uint64_t entity_id, float x, float y);
      Velocity(uint64_t entity_id);
      const std::string GetName() override;
      float x,y;
    };
  }
}
