#pragma once
#include "GameState.hpp"

namespace sf
{
  class RenderWindow;
}
namespace ft
{
  class World;
  class PlayState : public GameState
  {
  public:
    PlayState(World& world, sf::RenderWindow& window);
    void Update(float dt) override;
    void HandleInput(sf::Event& event) override;
    void Draw() override;

    void RenderOverlay(float dt);
  private:
    World&            m_world;
    sf::RenderWindow& m_window;
    float             m_frametime;
  };
}

