#include "Game.hpp"
#include "World.hpp"
#include "TimeStep.hpp"
#include <SFML/System/Clock.hpp>

#include "imgui_helper.hpp"
#include "imgui-SFML.h"
#include "Systems/Systems.hpp"
#include "States/PlayState.hpp"

namespace ft
{
  Game::Game()
    : m_world(World::Get())
  {
    m_window.create(sf::VideoMode(800,600),"fantasy_town_dev");
    ImGui::SFML::Init(m_window);
    InitSystems();
  }

  void Game::Run()
  {
    PushState<PlayState>(m_world,m_window);
    TimeStep  timestep;
    sf::Clock clock;
    while(m_window.isOpen())
    {
      sf::Time current_time = clock.restart();
      timestep.Update(current_time);
      sf::Event event;
      while(m_window.pollEvent(event))
      {
        PeekState()->HandleInput(event);
        switch(event.type)
        {
          case sf::Event::Closed:
            m_window.close();
            break;
          default:
            break;
        }
      }
      ImGui::SFML::Update(m_window, timestep.GetStep());
      while(timestep.timeToIntegrate())
      {
        PeekState()->Update(timestep.GetStep().asSeconds());
      }
      PeekState()->Draw();
    }
    ImGui::SFML::Shutdown();
  }

  void Game::LoadResources()
  {

  }

  void Game::InitSystems()
  {
    m_world.RegisterSystem<Systems::MovementSystem>();
    m_world.RegisterSystem<Systems::RenderSystem>(m_window);
    m_world.RegisterSystem<Systems::TaskSystem>();
  }


  void Game::PopState()
  {
    if(!m_states.empty())
    {
      m_states.pop();
    }
  }

  GameState* Game::PeekState()
  {
    return m_states.top().get();
  }
}
