#include "Systems/TaskSystem.hpp"

void flak::Systems::TaskSystem::Update(double dt)
{
  for(auto&& manager : m_taskmanagers)
  {
    manager->Update(dt);
  }
  for(auto&& pack : m_components)
  {
    auto queue = std::get<0>(pack);
    if(!queue->m_tasks.empty())
    {
      queue->m_tasks.front()->Update(dt);
    }
  }
}

void flak::Systems::TaskSystem::RegisterTaskManager(flak::TaskManager* manager)
{
    m_taskmanagers.push_back(manager);
}
