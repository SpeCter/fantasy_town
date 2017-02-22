#include "World.hpp"

World::World()
  :m_componentManager(*this)
{

}

void World::Update(double delta)
{
  for(auto&& system : m_systems)
  {
    if(system.second->Enabled())
    {
      system.second->Update(delta);
    }
  }
}

Entity World::CreateEntity()
{
  m_entities.push_back(Entity(m_componentManager,++next_id));
  return m_entities.back();
}

Entity World::GetEntity(uint64_t entity_id)
{
  return Entity(m_componentManager,entity_id);
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
