#pragma once
#include "Entity.hpp"
#include <vector>

namespace flak
{
  namespace Tasks
  {
    struct Task
    {
      Task()
      {
      }
      void AddTask();
      virtual void SetOwner(Entity* entity) = 0;
      virtual void Update(double dt)  = 0;
      virtual bool Finished() const = 0;
      virtual bool IsAssigned()
      {
        return m_assigned;
      }

      bool m_assigned = false;
      std::vector<Task*>   m_subtasks;
    };

  }
}
