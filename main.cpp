//#include "Entity.hpp"
//#include "World.hpp"
//#include <chrono>
//#include <random>
//#include <SFML/Graphics.hpp>
//#include "Systems/Systems.hpp"
//#include "Components/Components.hpp"
//#include "Tasks/TaskManager.hpp"
//#include "Tasks/GetWood.hpp"
//
//#include "imgui_helper.hpp"
//#include "imgui-SFML.h"
//
//#include "TimeStep.hpp"
//#include "Buildings/Lumberyard.hpp"
#include "Game.hpp"
using namespace ft;
int main(int argc, char *argv[])
{
  Game game;
  game.Run();
//sf::RenderWindow window({800,600},"fantasy_town_prototype");
//ImGui::SFML::Init(window);
//ft::TimeStep timestep;
//sf::Clock clock;
//int entity_index = 0;
//ft::World& world = ft::World::Get();
//auto movement_system  = world.RegisterSystem<Systems::MovementSystem>();
//auto render_system    = world.RegisterSystem<Systems::RenderSystem>(window);
//auto task_system      = world.RegisterSystem<Systems::TaskSystem>();
//ft::Buildings::Lumberyard ly(world);
//task_system->RegisterTaskManager(&ly.m_task_mgr);
//for(auto n = 0u;n < 100;++n)
//{
//  auto ent = world.CreateEntity();
//  ent.AddComponent<Components::Position>(400.0f,300.0f);
//  ent.AddComponent<Components::Velocity>(0.0f,0.0f);
//  ent.AddComponent<Components::Sprite>(5,5);
//  ent.AddComponent<Components::TaskQueue>();
//  ent.AddComponent<Components::Inventory>();
//
//  //lumberyard.Register(ent);
//
//  world.Finished(ent);
//}
//
//
//
//while(window.isOpen())
//{
//  sf::Time current_time = clock.restart();
//  timestep.Update(current_time);
//  sf::Event event;
//  while(window.pollEvent(event))
//  {
//    ImGui::SFML::ProcessEvent(event);
//    switch(event.type)
//    {
//      case sf::Event::Closed:
//      {
//        window.close();
//      }
//    }
//  }
//
//  ImGui::SFML::Update(window, timestep.GetStep());
//  ImGui::Begin("Lumberyard"); // begin window
//    std::vector<std::string> entity_names = world.GetWorkerNames();//world.GetEntityNames();
//    if (ImGui::Button("Hire person"))
//    {
//      ly.m_task_mgr.AssignEntity(std::stoull(entity_names[entity_index]));
//    }
//    ImGui::SameLine();
//    ImGui::Combo("Person:",&entity_index,entity_names);
//  ImGui::End();
//  RenderOverlay(current_time,window);
//  while(timestep.timeToIntegrate())
//  {
//    movement_system->Update(timestep.GetStep().asSeconds());
//  }
//  task_system->Update(current_time.asSeconds());
//  window.clear(sf::Color::Black);
//  render_system->Update();
//
//
//  ImGui::Render();
//  window.display();
//  //std::cout << std::chrono::duration<double,std::milli>(diff).count() <<"ms" << '\n';
//}
//ImGui::SFML::Shutdown();
//return 0;
}
