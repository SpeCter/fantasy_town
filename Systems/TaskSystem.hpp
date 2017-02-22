#pragma once
#include "Systems/ComponentSystem.hpp"
#include "Components/TaskQueue.hpp"
#include "Tasks/Task.hpp"
#include "Tasks/TaskManager.hpp"
#include <vector>

namespace flak
{
  namespace Systems
  {
    struct TaskSystem : public ComponentSystem<Components::TaskQueue>
    {
      void Update(double dt) override;
      void RegisterTaskManager(TaskManager* manager);

      std::vector<TaskManager*> m_taskmanagers;
    };
  }
}
