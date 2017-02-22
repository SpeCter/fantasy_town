#include "RenderSystem.hpp"
#include <SFML/Graphics/VertexArray.hpp>

flak::Systems::RenderSystem::RenderSystem(sf::RenderTarget& target)
  : m_target(target)
{

}

void flak::Systems::RenderSystem::Update(double dt)
{
  std::vector<sf::Vertex> verts;
  verts.reserve(m_components.size()*4);
  for(auto&& pack : m_components)
  {
    auto sprite   = std::get<0>(pack);
    auto position = std::get<1>(pack);
    sprite->shape.setPosition(position->x,position->y);
    verts.push_back(sf::Vertex(sf::Vector2f(position->x,position->y),sf::Color::White));
    verts.push_back(sf::Vertex(sf::Vector2f(position->x + sprite->shape.getSize().x,position->y),sf::Color::White));
    verts.push_back(sf::Vertex(sf::Vector2f(position->x + sprite->shape.getSize().x,position->y + + sprite->shape.getSize().y),sf::Color::White));
    verts.push_back(sf::Vertex(sf::Vector2f(position->x,position->y + + sprite->shape.getSize().x),sf::Color::White));
    //m_target.draw(sprite->shape);
  }
  m_target.draw(&verts[0], verts.size(), sf::Quads);
}
