#pragma once
#include "Tasks/Task.hpp"
#include "Components/Velocity.hpp"

namespace flak
{
  namespace Tasks
  {
    struct Wait : public Task
    {
      void SetOwner(Entity entity) override
      {
        m_velocity = entity.GetComponent<Components::Velocity>();
      }
      void Update(double dt) override
      {
        m_velocity->x = 0.0;
        m_velocity->y = 0.0;
      }
      bool Finished() const override
      {
        return true;
      }
      Components::Velocity* m_velocity;
    };
  }
}
