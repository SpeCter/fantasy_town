#pragma once
#include "Systems/ComponentSystem.hpp"
#include "Components/TaskQueue.hpp"
#include "Tasks/Task.hpp"
#include "Tasks/TaskManager.hpp"
#include <vector>

namespace ft
{
  namespace Systems
  {
    struct TaskSystem : public ComponentSystem<Components::TaskQueue>
    {
      void Update(double dt = 0) override;
      const std::string GetName() const override;
      void RegisterTaskManager(TaskManager* manager);

      std::deque<TaskManager*> m_taskmanagers;
    };
  }
}
