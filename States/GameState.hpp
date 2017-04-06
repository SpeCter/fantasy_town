#pragma once

namespace sf
{
  class Event;
}
namespace ft
{
  struct GameState
  {
    GameState();
    virtual void Update(float dt) = 0;
    virtual void HandleInput(sf::Event& event) = 0;
    virtual void Draw() = 0;
  };
}
