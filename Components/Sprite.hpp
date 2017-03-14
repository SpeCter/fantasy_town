#pragma once
#include "Component.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

namespace flak {
namespace Components {
    struct Sprite : public Component<Sprite>
    {
      Sprite(uint64_t entity_id);
      Sprite(uint64_t entity_id,int x, int y);
      const std::string GetName() override;
      sf::RectangleShape shape;
    };
  }
}
