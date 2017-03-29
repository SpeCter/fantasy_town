#pragma once
#include "Entity.hpp"
#include <deque>

namespace flak
{
  namespace Tasks
  {
    struct Task
    {
      Task()
      {
      }
      virtual void AddTask(Task* task)
      {
        m_subtasks.push_back(task);
      }
      virtual void SetOwner(Entity* entity) = 0;
      virtual void SetOwner(uint64_t entity_id)
      {
        m_owner = entity_id;
      }
      virtual const std::string GetTaskName() = 0;
      virtual uint64_t GetOwnerID() const
      {
        return m_owner;
      }
      virtual void SetRepeatable(bool repeat)
      {
        m_repeat = repeat;
      }
      virtual bool IsRepeatable() const
      {
        return m_repeat;
      }
      virtual void Update(double dt)  = 0;
      virtual bool Finished() const = 0;
      virtual bool IsAssigned()
      {
        return m_assigned;
      }
      virtual uint64_t GetID() const
      {
        return m_id;
      }
      virtual void SetID(uint64_t id)
      {
        m_id = id;
      }


      bool m_assigned   = false;
      bool m_repeat     = false;
      uint64_t m_id     = 0;
      uint64_t m_owner  = 0;
      std::deque<Task*>  m_subtasks;
    };



  }
}
