#pragma once
#include <vector>
#include "Entity.hpp"


namespace flak
{
  namespace Tasks
  {
    class Task;
  }
  namespace Components
  {
    class TaskQueue;
  }
  class TaskManager
  {
  public:
    TaskManager(World& world);
    void RegisterTask(Tasks::Task* task);
    void RegisterTask(Tasks::Task* task,uint64_t entity);
    void Register(Entity entity);
    void Update(double dt);
  protected:
    std::vector<Tasks::Task*>             m_available_tasks;
    std::vector<Components::TaskQueue*>   m_available_queues;
    std::vector<Entity>                   m_occupied_entities;
    World& m_world;
  };
}




