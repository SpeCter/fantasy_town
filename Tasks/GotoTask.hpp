#pragma once
#include "Task.hpp"
#include "Components/Position.hpp"
#include "Components/Velocity.hpp"
#include <cmath>

namespace ft
{
  namespace Tasks
  {
    struct GotoTask : public Task
    {
    public:
      GotoTask(int x, int y);
      void SetOwner(Entity* entity) override;
      void SetOwner(uint64_t entity) override;
      const std::string GetTaskName() override;
      void Update(double dt) override;
      bool Finished() const override;
      float x,y;
      Components::Position* m_position;
      Components::Velocity* m_velocity;
    };
  }
}
