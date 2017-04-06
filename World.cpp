#include "World.hpp"
#include "imgui.h"
#include "imconfig-SFML.h"
#include "SFML/System/Clock.hpp"
#include "Components/TaskQueue.hpp"

namespace ft
{
  World::World()
    :m_componentManager(*this)
  {

  }

  Entity& World::CreateEntity()
  {
    m_entities.push_back(Entity(m_componentManager,++next_id));
    return m_entities.back();
  }

  Entity World::GetEntity(uint64_t entity_id)
  {
    return Entity(m_componentManager,entity_id);
  }

  std::vector<std::string> World::GetEntityNames()
  {
    std::vector<std::string> entities;
    entities.reserve(m_entities.size());
    for(auto&& entity : m_entities)
    {
      entities.push_back(std::to_string(entity));
    }
    return entities;
  }

  void World::EntityUpdated(uint64_t entity)
  {
    for(auto&& system : m_systems)
    {
      system.second->EntityUpdated(Entity(m_componentManager,entity));
    }
  }

  void World::Finished(uint64_t entity)
  {
    m_componentManager.ComponentAdded(entity);
  }


  void World::PrintSystems()
  {
    //for(const auto&& system : m_systems)
    {
      //std::cout << system->GetName() << (system->IsEnabled() ? " enabled" : " disabled") << '\n';
    }
  }

  std::vector<std::string> World::GetWorkerNames()
  {
    std::vector<std::string> workers;
    for(auto&& entity : m_entities)
    {
      if(entity.HasComponent<ft::Components::TaskQueue>())
      {
        workers.push_back(std::to_string(entity));
      }
    }
    return workers;
  }
}
