#pragma once
#include "Components/Component.hpp"
#include "Tasks/TaskFactory.hpp"
#include <vector>
#include <algorithm>

namespace flak
{
  namespace Tasks
  {
    struct Task;
  }
  namespace Components
  {
    struct TaskList : public Component<TaskList>
    {
      TaskList(uint64_t entity_id)
      {
        m_entity_id = entity_id;
      }
      template<typename T,typename... Args>
      void AddTask(Args&&... args)
      {
        m_possible_tasks.push_back(CreateTask<T>(args...));
      }
      void RemoveTask(uint64_t id)
      {
        m_possible_tasks.erase(std::remove(m_possible_tasks.begin(),
                                           m_possible_tasks.end(),
                                           [id](Tasks::Task* task)
                                           {
                                             return task->m_id == id;
                                           }),
                               m_possible_tasks.end());
      }

      std::vector<Tasks::Task*> m_possible_tasks;
    };
  }
}
