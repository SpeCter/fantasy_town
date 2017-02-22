#include "ComponentManager.hpp"
#include "World.hpp"

void ComponentManager::ComponentAdded(uint64_t entity)
{
  m_world.EntityUpdated(entity);
}
