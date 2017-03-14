#include "Buildings/Lumberyard.hpp"
#include "World.hpp"
#include "Components/Components.hpp"

flak::Buildings::Lumberyard::Lumberyard(World& world)
  : m_world(world),
    m_entity(m_world.CreateEntity())
{
  m_entity.AddComponent<Components::Position>(400,400);
  m_entity.AddComponent<Components::Inventory>();
  m_entity.AddComponent<Components::Sprite>(50,50);
  m_world.EntityUpdated(m_entity);
}
