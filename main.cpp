#include "Entity.hpp"
#include "World.hpp"
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>
#include "Systems/Systems.hpp"
#include "Components/Components.hpp"
#include "Tasks/TaskManager.hpp"
#include "Tasks/GetWood.hpp"

#include "imgui_helper.hpp"
#include "imgui-SFML.h"

#include "TimeStep.hpp"
#include "Buildings/Lumberyard.hpp"

using namespace flak;

void RenderOverlay(const sf::Time& time,sf::RenderWindow& window)
{
  static int fps_index = 0;
  ImGui::SetNextWindowPos(ImVec2(10,10));
  if (!ImGui::Begin("Example: Fixed Overlay", nullptr, ImVec2(0,100), 0.3f, ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoSavedSettings))
  {
      ImGui::End();
  }
  ImGui::Text("Mouse Position: (%.1f,%.1f)", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);
  ImGui::Text("FPS:%.f",1/time.asSeconds());
  ImGui::PushItemWidth(60.0f);
  if(ImGui::Combo("FPS:Limit",&fps_index," 30\0 60\0 90\0 None\0"))
  {
    switch(fps_index)
    {
      case 0:
        window.setFramerateLimit(30);
        break;
      case 1:
        window.setFramerateLimit(60);
        break;
      case 2:
        window.setFramerateLimit(90);
        break;
      case 3:
        window.setFramerateLimit(0);
        break;
    }
  }
  ImGui::PopItemWidth();
  ImGui::End();
}

int main(int argc, char *argv[])
{
  sf::RenderWindow window({800,600},"fantasy_town_prototype");
  ImGui::SFML::Init(window);
  flak::TimeStep timestep;
  sf::Clock clock;
  int entity_index = 0;
  World& world = World::Get();
  auto movement_system  = world.RegisterSystem<Systems::MovementSystem>();
  auto render_system    = world.RegisterSystem<Systems::RenderSystem>(window);
  auto task_system      = world.RegisterSystem<Systems::TaskSystem>();
  flak::Buildings::Lumberyard ly(world);

  task_system->RegisterTaskManager(&ly.m_task_mgr);
  for(auto n = 0u;n < 100;++n)
  {
    auto ent = world.CreateEntity();
    ent.AddComponent<Components::Position>(400.0f,300.0f);
    ent.AddComponent<Components::Velocity>(0.0f,0.0f);
    ent.AddComponent<Components::Sprite>(5,5);
    ent.AddComponent<Components::TaskQueue>();
    ent.AddComponent<Components::Inventory>();

    //lumberyard.Register(ent);

    world.Finished(ent);
  }



  while(window.isOpen())
  {
    sf::Time current_time = clock.restart();
    timestep.Update(current_time);
    sf::Event event;
    while(window.pollEvent(event))
    {
      ImGui::SFML::ProcessEvent(event);
      switch(event.type)
      {
        case sf::Event::Closed:
        {
          window.close();
        }
      }
    }

    ImGui::SFML::Update(window, timestep.GetStep());
    ImGui::Begin("Lumberyard"); // begin window
      std::vector<std::string> entity_names = world.GetWorkerNames();//world.GetEntityNames();
      if (ImGui::Button("Hire person"))
      {
        ly.m_task_mgr.AssignEntity(std::stoull(entity_names[entity_index]));
      }
      ImGui::SameLine();
      ImGui::Combo("Person:",&entity_index,entity_names);
    ImGui::End();
    RenderOverlay(current_time,window);
    while(timestep.timeToIntegrate())
    {
      movement_system->Update(timestep.GetStep().asSeconds());
    }
    task_system->Update(current_time.asSeconds());
    window.clear(sf::Color::Black);
    render_system->Update();


    ImGui::Render();
    window.display();
    //std::cout << std::chrono::duration<double,std::milli>(diff).count() <<"ms" << '\n';
  }
  ImGui::SFML::Shutdown();
  return 0;
}
