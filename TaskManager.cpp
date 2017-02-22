#include "Tasks/TaskManager.hpp"
#include "Tasks/Task.hpp"
#include "Components/TaskQueue.hpp"

flak::TaskManager::TaskManager()
{

}
void flak::TaskManager::RegisterTask(flak::Tasks::Task* task)
{
  m_available_tasks.push_back(task);
}

void flak::TaskManager::Register(Entity entity)
{
  //m_available_entities.push_back(entity);
  m_available_queues.push_back(entity.GetComponent<Components::TaskQueue>());
}

void flak::TaskManager::Update(double dt)
{
  for(auto&& task_queue : m_available_queues)
  {
    if(!task_queue->m_tasks.empty()) continue;
    for(unsigned int n = 0;n < m_available_tasks.size();++n)
    {
      if(m_available_tasks[n]->IsAssigned())
      {
        continue;
      }
      else
      {
        task_queue->m_tasks.push_back(m_available_tasks[n]);
        m_available_tasks[n]->SetOwner(task_queue->m_entity);
        break;
      }
    }
  }
}


