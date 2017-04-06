#include "Sprite.hpp"
#include "Entity.hpp"

ft::Components::Sprite::Sprite(uint64_t entity_id)
{
  m_entity_id = entity_id;
  shape.setSize({10.0,10.0});
  shape.setFillColor(sf::Color::White);
}

ft::Components::Sprite::Sprite(uint64_t entity_id, int x, int y)
{
  m_entity_id = entity_id;
  shape.setSize(sf::Vector2f(x,y));
  shape.setFillColor(sf::Color::Green);
}
const std::string ft::Components::Sprite::GetName()
{
  return "Sprite";
}
