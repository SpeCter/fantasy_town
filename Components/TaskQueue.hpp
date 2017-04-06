#pragma once
#include "Components/Component.hpp"
#include <deque>
#include "Tasks/Task.hpp"

class Entity;

namespace ft
{
  namespace Components
  {
    struct TaskQueue : public Component<TaskQueue>
    {
      TaskQueue(uint64_t entity_id);
      const std::string GetName() override;
      void Pop();
      void Push(Tasks::Task* task);
      std::deque<Tasks::Task*> m_tasks;
    };
  }
}
