#pragma once
#include "Task.hpp"
#include "Components/Position.hpp"
#include "Components/Velocity.hpp"
#include <cmath>

namespace flak
{
  namespace Tasks
  {
    struct GotoTask : public Task
    {
    public:
      GotoTask(int x, int y);
      void SetOwner(Entity entity) override;
      uint64_t GetOwnerID() const override;
      void Update(double dt) override;
      bool Finished() const override;
      float x,y;
      Components::Position* m_position;
      Components::Velocity* m_velocity;
    };
  }
}
