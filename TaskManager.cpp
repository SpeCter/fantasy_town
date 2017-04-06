#include "Tasks/TaskManager.hpp"
#include "Tasks/Task.hpp"
#include "World.hpp"
#include "Components/TaskQueue.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include <string>
#include <algorithm>

uint64_t ft::TaskManager::m_next_id = 0;

ft::TaskManager::TaskManager()
{
}

void ft::TaskManager::Update(float dt)
{
  static int current_index  = 0;
  static int entity_index   = 0;
  static bool repeat = false;
  std::vector<std::string> m_available_tasks;
  std::vector<std::string> m_running_tasks;
  std::vector<std::string> m_entities;
  for(auto&& task : m_tasks)
  {
    if(!task->IsAssigned())
    {
      m_available_tasks.push_back(std::to_string(task->m_id));
    }
  }
  for(auto&& entity: m_free_entities)
  {
    m_entities.push_back(std::to_string(entity));
  }
  for(auto&& task : m_assigned_tasks)
  {
    std::string task_description;
    task_description = "ID(" + std::to_string(task->GetID()) + ") " + task->GetTaskName() + "  Entity: " + std::to_string(task->GetOwnerID());
    m_running_tasks.push_back(task_description);
  }
  ImGui::Begin("Lumberyard"); // begin window
  if (ImGui::Button(" + "))
  {
    if(!m_available_tasks.empty() && !m_entities.empty())
    {
      uint64_t task_id    = std::stoull(m_available_tasks[current_index]);
      uint64_t entity_id  = std::stoull(m_entities[entity_index]);
      auto task = std::find_if(std::begin(m_tasks),std::end(m_tasks),[&](Tasks::Task* task)
      {
        return task->m_id == task_id;
      });

      (*task)->SetRepeatable(repeat);

      AssignTask(*task,entity_id);
      m_free_entities.erase(std::remove_if(m_free_entities.begin(), m_free_entities.end(),
                                           [&](uint64_t ent)
      {
        return ent == entity_id;
      }), m_free_entities.end());
      current_index = 0;
      entity_index  = 0;
    }
  }
  ImGui::SameLine();
  ImGui::PushItemWidth(150);
  ImGui::Combo("Jobs:",&current_index,m_available_tasks);
  ImGui::SameLine();
  ImGui::PushItemWidth(50);
  ImGui::Combo("Entity:",&entity_index,m_entities);
  ImGui::SameLine();
  ImGui::Checkbox("Repeat",&repeat);
  ImGui::PopItemWidth();
  ImGui::NewLine();
  if(ImGui::TreeNode("Running Tasks:"))
  {
    for(auto&& description : m_running_tasks)
    {
      ImGui::Text("%s", description.data());
    }
    ImGui::TreePop();
  }
  ImGui::End();
}

void ft::TaskManager::AssignTask(ft::Tasks::Task* task, Entity* entity)
{
  task->SetOwner(entity);
}

void ft::TaskManager::AssignTask(ft::Tasks::Task* task, uint64_t entity_id)
{
  task->SetOwner(entity_id);
  m_assigned_tasks.push_back(task);
}

void ft::TaskManager::AssignEntity(uint64_t entity_id)
{
  m_free_entities.push_back(entity_id);
}

std::vector<ft::Tasks::Task*>* ft::TaskManager::GetTasks()
{
  return &m_tasks;
}

ft::Tasks::Task* ft::TaskManager::GetTask(uint64_t id)
{
  auto it = std::find_if(m_tasks.begin(),m_tasks.end(),
                         [id](ft::Tasks::Task* task)
  {
    return (task->m_id == id);
  });
  if(it != m_tasks.end())
  {
    return *(it);
  }
  return nullptr;
}




