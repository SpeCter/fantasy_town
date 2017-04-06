#pragma once
#include <stack>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include "States/GameState.hpp"

namespace ft
{
  class World;
  class Game
  {
  public:
    Game();
    void Run();
    void LoadResources();
    void InitSystems();
    template<typename T,typename... Args>
    void PushState(Args&&... args)
    {
      m_states.push(std::make_unique<T>(args...));
    }

    void PopState();
    template<typename T>
    void ChangeState()
    {
      if(!m_states.empty())
      {
        m_states.pop();
      }
      PushState<T>();
    }
    GameState* PeekState();
  private:
    std::stack<std::unique_ptr<GameState>>  m_states;
    sf::RenderWindow                        m_window;
    World&                                  m_world;
  };

}

