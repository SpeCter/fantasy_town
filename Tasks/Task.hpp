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
      virtual void SetOwner(Entity entity) = 0;
      virtual uint64_t GetOwnerID() const = 0;
      virtual void Update(double dt)  = 0;
      virtual bool Finished() const = 0;
      virtual bool IsAssigned()
      {
        return m_assigned;
      }
      virtual void SetID(uint64_t id)
      {
        m_id = id;
      }

      std::vector<Task*>  m_subtasks;
      bool m_assigned   = false;
      uint64_t m_id     = 0;
      uint64_t m_owner  = 0;
    };

  }
}
