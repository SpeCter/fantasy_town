#pragma once
#include "ComponentSystem.hpp"
#include "Components/Sprite.hpp"
#include "Components/Position.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

namespace ft {
namespace Systems {
    struct RenderSystem : public ComponentSystem<Components::Sprite,
                                                 Components::Position>
    {
      RenderSystem(sf::RenderTarget& target);
      void Update(double dt = 0) override;
      const std::string GetName() const override;
      sf::RenderTarget& m_target;
    };
  }
}
