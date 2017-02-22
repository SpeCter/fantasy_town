#pragma once
#include "Tasks/Task.hpp"

namespace flak
{
  namespace Tasks
  {
    struct ChopWood : public Task
    {
      ChopWood()
      {
        m_choptime = 5.0;
      }

      void SetOwner(Entity entity) override
      {
        m_assigned = true;
      }
      void Update(double dt) override
      {
        if(m_choptime < 0.0)
        {
          m_choptime = 5.0;
        }
        m_choptime -= dt;
      }
      bool Finished() const override
      {
        if(m_choptime < 0.0)
        {
          return true;
        }
        return false;
      }
      double m_choptime;
    };
  }
}
