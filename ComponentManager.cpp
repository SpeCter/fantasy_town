#include "ComponentManager.hpp"
#include "World.hpp"

namespace ft
{
  void ComponentManager::ComponentAdded(uint64_t entity)
  {
    m_world.EntityUpdated(entity);
  }
}
