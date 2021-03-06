#include "Components/Velocity.hpp"
#include "Entity.hpp"


flak::Components::Velocity::Velocity(uint64_t entity_id, float x, float y)
  : x(x),
    y(y)
{
  m_entity_id = entity_id;
}

flak::Components::Velocity::Velocity(uint64_t entity_id)
  : x(0),
    y(0)
{
  m_entity_id = entity_id;
}



const std::string flak::Components::Velocity::GetName()
{
  return "Velocity"+std::string(" x:") + std::to_string(x)+" y:"+std::to_string(y);
}
