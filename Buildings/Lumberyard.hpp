#pragma once
#include "Entity.hpp"
#include "Tasks/TaskManager.hpp"

class World;
namespace flak
{
  namespace Buildings
  {
    struct Lumberyard
    {
      Lumberyard(World& world);
      World&      m_world;
      Entity&     m_entity;
      TaskManager m_task_mgr;
    };
  }
}
