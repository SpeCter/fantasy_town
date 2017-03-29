#pragma once
#include <vector>
#include "Entity.hpp"
#include "Tasks/Task.hpp"
#include "imgui_helper.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include "World.hpp"

namespace flak
{
  class TaskManager
  {
  public:
    TaskManager();
    template<typename T,typename... Args>
    T* CreateTask(Args&&... args)
    {
      m_tasks.push_back(new T(args...));
      m_tasks.back()->SetID(m_next_id++);
      return static_cast<T*>(m_tasks.back());
    }
    template<typename T,typename... Args>
    void CreateSubTask(Tasks::Task* task,Args&&... args)
    {
      task->AddTask(new T(args...));
      task->m_subtasks.back()->SetID(m_next_id++);
    }
    void Update(float dt);
    void AssignTask(Tasks::Task* task,Entity* entity);
    void AssignTask(Tasks::Task* task,uint64_t entity_id);
    void AssignEntity(uint64_t entity_id);
    std::vector<Tasks::Task*>* GetTasks();

    Tasks::Task* GetTask(uint64_t id);
  protected:
    std::vector<Tasks::Task*> m_tasks;
    std::vector<Tasks::Task*> m_assigned_tasks;
    std::vector<uint64_t>     m_free_entities;
    std::vector<uint64_t>     m_used_entities;
    static uint64_t           m_next_id;
  };
}




