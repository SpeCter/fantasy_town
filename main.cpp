#include "Entity.hpp"
#include "World.hpp"
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>
#include "Systems/Systems.hpp"
#include "Components/Components.hpp"
#include "Tasks/TaskManager.hpp"
#include "Tasks/GetWood.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

using namespace flak;

int main(int argc, char *argv[])
{

  sf::RenderWindow window({800,600},"fantasy_town_prototype");
  ImGui::SFML::Init(window);
  int current_index = 0;
  //window.setVerticalSyncEnabled(true);
  World world;
  //world.RegisterSystem<TestSystem>();
  //world.RegisterSystem<Systems::AutomoveSystem>();
  world.RegisterSystem<Systems::MovementSystem>();
  world.RegisterSystem<Systems::RenderSystem>(window);
  world.RegisterSystem<Systems::TaskSystem>();
  TaskManager lumberyard(world);

  world.GetSystem<Systems::TaskSystem>()->RegisterTaskManager(&lumberyard);
  for(auto n = 0u;n < 100;++n)
  {
    auto ent = world.CreateEntity();
    ent.AddComponent<Components::Position>(400.0f,300.0f);
    ent.AddComponent<Components::Velocity>(0.0f,0.0f);
    ent.AddComponent<Components::Sprite>();
    ent.AddComponent<Components::TaskQueue>();

    lumberyard.Register(ent);

    world.Finished(ent);
  }
  int tag = 1;
  sf::Clock clock;
  sf::String time_string = "";
  float time_ticks = 0.0;

  while(window.isOpen())
  {
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
    auto time = clock.restart();
    time_ticks += time.asSeconds();

    ImGui::SFML::Update(window, time);

    window.clear(sf::Color::Black);
    ImGui::Begin("Lumberyard"); // begin window
      if (ImGui::Button("+"))
      {
        switch(current_index)
        {
          case 0:
            break;
          case 1:
            break;
          case 2:
            lumberyard.RegisterTask(new Tasks::GetWood());
            break;
          default:
            break;
        }
      }
      ImGui::SameLine();
      ImGui::Combo("Jobs:",&current_index,"Goto\0ChopWood\0GetWood\0\0");
    ImGui::End();

    world.Update(16.0/1000.0);
    //ImGui::Begin("Entities");
    //for(auto&& entity : *world.GetEntities())
    //{
    //  std::string text = "Entity " +std::to_string(entity);
    //  if(ImGui::TreeNode(text.data()))
    //  {
    //    auto vec = entity.GetAllComponents();
    //
    //    for(auto component : vec)
    //    {
    //      ImGui::Text("%s", component.data());
    //    }
    //    ImGui::TreePop();
    //  }
    //}
    //ImGui::End();
    ImGui::SetNextWindowPos(ImVec2(10,10));
    if (!ImGui::Begin("Example: Fixed Overlay", nullptr, ImVec2(0,0), 0.3f, ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoSavedSettings))
    {
        ImGui::End();
    }
    ImGui::Text("Mouse Position: (%.1f,%.1f)", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);
    ImGui::Text("FPS:%.f",1/time.asSeconds());
    ImGui::End();
    ImGui::Render();
    window.display();
    //std::cout << std::chrono::duration<double,std::milli>(diff).count() <<"ms" << '\n';
  }
  ImGui::SFML::Shutdown();
  return 0;
}
