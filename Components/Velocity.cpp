#include "Components/Velocity.hpp"
#include "Entity.hpp"

flak::Components::Velocity::Velocity(Entity* entity, float x, float y)
  : x(x),
    y(y)
{
  m_entity = entity;
  m_entity_id = entity->GetID();
}

flak::Components::Velocity::Velocity(uint64_t entity_id)
  : x(0),
    y(0)
{
  m_entity_id = entity_id;
}

flak::Components::Velocity::Velocity(Entity* entity)
  : x(0),
    y(0)
{
  m_entity = entity;
  m_entity_id = entity->GetID();
}

const std::string flak::Components::Velocity::GetName()
{
  return "Velocity"+std::string(" x:") + std::to_string(x)+" y:"+std::to_string(y);
}
