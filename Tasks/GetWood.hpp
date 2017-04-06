#pragma once
#include "Tasks/Task.hpp"
#include "Tasks/GotoTask.hpp"
#include "Tasks/ChopWood.hpp"
#include "Tasks/Wait.hpp"
#include "randutils.hpp"
#include "Tasks/TaskFactory.hpp"

namespace ft
{
  namespace Tasks
  {
    struct GetWood : public Task
    {
      GetWood();
      void Update(double dt) override;
      bool Finished() const override;
      void SetOwner(Entity* entity) override;
      void SetOwner(uint64_t ent) override;
      const std::string GetTaskName() override;
      unsigned int n = 0;
    };
  }
}
