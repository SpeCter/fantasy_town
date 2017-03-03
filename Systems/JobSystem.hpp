#pragma once
#include "ComponentSystem.hpp"
#include "Components/Job.hpp"
#include "Tasks/TaskManager.hpp"

namespace flak
{
  namespace Systems
  {
    struct JobSystem : public ComponentSystem<Components::Job>
    {
      JobSystem()
      {

      }
      void Update(double dt = 0)
      {
      }

      const std::string GetName() const override
      {
        return "JobSystem";
      }
    };

  }
}
