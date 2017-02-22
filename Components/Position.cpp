#include "Components/Position.hpp"
#include "Entity.hpp"

flak::Components::Position::Position(uint64_t entity_id, float x, float y)
  : x(x),
    y(y)
{
  m_entity_id = entity_id;
}

flak::Components::Position::Position(uint64_t entity_id)
  : x(0),
    y(0)
{
  m_entity_id = entity_id;
}

const std::string flak::Components::Position::GetName()
{
  return "Position";
}
