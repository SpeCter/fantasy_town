#pragma once
#include "ComponentSystem.hpp"
#include "Components/Position.hpp"
#include "Components/Velocity.hpp"

namespace ft
{
  namespace Systems
  {
    struct MovementSystem : public ComponentSystem<Components::Position,
                                                   Components::Velocity>
    {
      MovementSystem();
      void Update(double dt = 0) override;
      const std::string GetName() const override;
    };
  }
}
