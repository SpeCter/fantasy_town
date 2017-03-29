#include "Systems/TaskSystem.hpp"

void flak::Systems::TaskSystem::Update(double dt)
{
  for(auto&& manager : m_taskmanagers)
  {
    manager->Update(dt);
    auto tasks = manager->GetTasks();
    for(auto&& task : *tasks)
    {
      if(task->IsAssigned())
      {
        auto queue = World::Get().GetEntity(task->GetOwnerID()).GetComponent<Components::TaskQueue>();
        if(queue->m_tasks.empty())
        {
          queue->m_tasks.push_back(task);
        }
      }
    }
  }
  for(auto&& pack : m_components)
  {
    auto queue = std::get<Components::TaskQueue*>(pack);
    if(!queue->m_tasks.empty())
    {
      queue->m_tasks.front()->Update(dt);
    }
  }
}

const std::string flak::Systems::TaskSystem::GetName() const
{
  return "TaskSystem";
}

void flak::Systems::TaskSystem::RegisterTaskManager(flak::TaskManager* manager)
{
    m_taskmanagers.push_back(manager);
}
