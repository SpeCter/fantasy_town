#include "Tasks/TaskManager.hpp"
#include "Tasks/Task.hpp"
#include "Components/TaskQueue.hpp"
#include "World.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

flak::TaskManager::TaskManager(World& world)
 : m_world(world)
{

}
void flak::TaskManager::RegisterTask(flak::Tasks::Task* task)
{
  m_available_tasks.push_back(task);
}

void flak::TaskManager::RegisterTask(flak::Tasks::Task* task, uint64_t entity)
{
  task->SetOwner(m_world.GetEntity(entity));
  m_available_tasks.push_back(task);
}

void flak::TaskManager::Register(Entity entity)
{
  //m_available_entities.push_back(entity);
  m_available_queues.push_back(entity.GetComponent<Components::TaskQueue>());
}

void flak::TaskManager::Update(double dt)
{

  ImGui::Begin("Lumberyard");
  if(ImGui::TreeNode("Tasks:"))
  {
    for(auto&& task : m_available_tasks)
    {
      ImGui::Text("%s Entity:%d","GetWood",task->GetOwnerID());
    }
    ImGui::TreePop();
  }
  ImGui::End();

  for(auto&& queue : m_available_queues)
  { /* Look for workers */
    if(queue->m_tasks.empty())
    { /* Worker idle ? */
      for(auto&& task : m_available_tasks)
      { /* Task available ?*/
        if(!task->IsAssigned())
        { /* Task not assigned ?*/
          queue->m_tasks.push_back(task);
        }
        else
        {
          if(task->GetOwnerID() == queue->m_entity_id)
          {
            queue->m_tasks.push_back(task);
          }
        }
      }
    }
  }
  //for(auto&& task_queue : m_available_queues)
  //{
  //  if(!task_queue->m_tasks.empty()) continue;
  //  for(unsigned int n = 0;n < m_available_tasks.size();++n)
  //  {
  //    if(m_available_tasks[n]->IsAssigned())
  //    {
  //      continue;
  //    }
  //    else
  //    {
  //      task_queue->m_tasks.push_back(m_available_tasks[n]);
  //      m_available_tasks[n]->SetOwner(m_world.GetEntity(task_queue->m_entity_id));
  //      break;
  //    }
  //  }
  //}
}


