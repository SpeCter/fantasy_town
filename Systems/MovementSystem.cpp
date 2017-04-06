#include "Systems/MovementSystem.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/System/Clock.hpp"

ft::Systems::MovementSystem::MovementSystem()
{

}

void ft::Systems::MovementSystem::Update(double dt)
{
  for(auto pack : m_components)
  {
    auto pos = std::get<0>(pack);
    auto vel = std::get<1>(pack);
    pos->x = pos->x + (vel->x * 10.0 * dt);
    pos->y = pos->y + (vel->y * 10.0 * dt);
  }
}

const std::string ft::Systems::MovementSystem::GetName() const
{
  return "MovementSystem";
}
