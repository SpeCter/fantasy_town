#pragma once
#include "ComponentSystem.hpp"
#include "Components/Velocity.hpp"

namespace flak
{
  namespace Systems
  {
    struct AutomoveSystem : public ComponentSystem<Components::Velocity>
    {
      AutomoveSystem()
      {
        time = 5.0;
        mt = std::mt19937(rd());
        dist = std::uniform_real_distribution<double>(-10.0,10.0);
      }

      void Update(double dt) override
      {
        time += dt;

          for(auto pack : m_components)
          {
            auto vel = std::get<0>(pack);
            vel->x = dist(mt) * 5.0;
            vel->y = dist(mt) * 5.0;
            //auto distance = std::sqrt(vel->x*vel->x + vel->y*vel->y);
            //vel->x /= distance;
            //vel->y /= distance;
          }
      }
      std::random_device rd;
      std::mt19937 mt;
      std::uniform_real_distribution<double> dist;
      double time = 0.0;
    };
  }
}
