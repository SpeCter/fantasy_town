#include "Buildings/Lumberyard.hpp"
#include "World.hpp"
#include "Components/Components.hpp"
#include "Tasks/GetWood.hpp"

flak::Buildings::Lumberyard::Lumberyard(World& world)
  : m_world(world),
    m_entity(m_world.CreateEntity())
{
  m_entity.AddComponent<Components::Position>(400,400);
  m_entity.AddComponent<Components::Inventory>();
  m_entity.AddComponent<Components::Sprite>(50,50);
  m_entity.AddComponent<Components::TaskList>();
  m_world.EntityUpdated(m_entity);

  auto get_wood = m_task_mgr.CreateTask<Tasks::GetWood>();
  m_task_mgr.CreateSubTask<Tasks::GotoTask>(get_wood,20,20);
  m_task_mgr.CreateSubTask<Tasks::Wait>(get_wood);
  m_task_mgr.CreateSubTask<Tasks::ChopWood>(get_wood);
  m_task_mgr.CreateSubTask<Tasks::GotoTask>(get_wood,400,400);
}
