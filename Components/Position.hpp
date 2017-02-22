#pragma once
#include "Component.hpp"


namespace flak
{
  namespace Components
  {
    struct Position : public Component<Position>
    {
      Position(uint64_t entity_id,float x, float y);
      Position(Entity* entity,float x, float y);
      Position(uint64_t entity_id);

      const std::string GetName() override;
      float x,y;
    };
  }
}
