#include "Sprite.hpp"
#include "Entity.hpp"

flak::Components::Sprite::Sprite(uint64_t entity_id)
{
  m_entity_id = entity_id;
  shape.setSize({10.0,10.0});
  shape.setFillColor(sf::Color::White);
}

flak::Components::Sprite::Sprite(Entity* entity)
{
  m_entity = entity;
  m_entity_id = entity->GetID();
  shape.setSize({10.0,10.0});
  shape.setFillColor(sf::Color::White);
}

const std::string flak::Components::Sprite::GetName()
{
  return "Sprite";
}
