#include "PlayState.hpp"
#include "World.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "imgui-SFML.h"
#include "imgui.h"
#include "Components/Components.hpp"
#include "Systems/Systems.hpp"

namespace ft
{
  PlayState::PlayState(World& world, sf::RenderWindow& window)
    : m_world(world),
      m_window(window)
  {
    for(auto n = 0u;n < 100;++n)
    {
      auto ent = world.CreateEntity();
      ent.AddComponent<Components::Position>(400.0f,300.0f);
      ent.AddComponent<Components::Velocity>(0.0f,0.0f);
      ent.AddComponent<Components::Sprite>(5,5);
      ent.AddComponent<Components::TaskQueue>();
      ent.AddComponent<Components::Inventory>();
      world.Finished(ent);
    }
  }

  void PlayState::Update(float dt)
  {
    m_frametime = dt;
    auto movement_system  = m_world.RegisterSystem<Systems::MovementSystem>();
    auto task_system      = m_world.RegisterSystem<Systems::TaskSystem>();
    movement_system->Update(dt);
    task_system->Update(dt);
  }

  void PlayState::HandleInput(sf::Event& event)
  {
    ImGui::SFML::ProcessEvent(event);
  }

  void PlayState::Draw()
  {
    m_window.clear(sf::Color::Black);
    RenderOverlay(m_frametime);
    m_world.GetSystem<Systems::RenderSystem>()->Update(0);
    ImGui::Render();
    m_window.display();
  }

  void PlayState::RenderOverlay(float dt)
  {
    static int fps_index = 0;
    ImGui::SetNextWindowPos(ImVec2(10,10));
    if (!ImGui::Begin("Example: Fixed Overlay", nullptr, ImVec2(0,100), 0.3f, ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoSavedSettings))
    {
        ImGui::End();
    }
    ImGui::Text("Mouse Position: (%.1f,%.1f)", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);
    ImGui::Text("FPS:%.f",1/dt);
    ImGui::PushItemWidth(60.0f);
    if(ImGui::Combo("FPS:Limit",&fps_index," 30\0 60\0 90\0 None\0"))
    {
      switch(fps_index)
      {
        case 0:
          m_window.setFramerateLimit(30);
          break;
        case 1:
          m_window.setFramerateLimit(60);
          break;
        case 2:
          m_window.setFramerateLimit(90);
          break;
        case 3:
          m_window.setFramerateLimit(0);
          break;
      }
    }
    ImGui::PopItemWidth();
    ImGui::End();
  }
}
