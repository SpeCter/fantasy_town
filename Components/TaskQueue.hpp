#pragma once
#include "Components/Component.hpp"
#include <vector>
#include "Tasks/Task.hpp"

class Entity;

namespace flak
{
  namespace Components
  {
    struct TaskQueue : public Component<TaskQueue>
    {
      TaskQueue(uint64_t entity_id);
      TaskQueue(Entity* entity);
      const std::string GetName() override;
      std::vector<Tasks::Task*> m_tasks;
    };
  }
}
