#include "Components/TaskQueue.hpp"
#include "Entity.hpp"

flak::Components::TaskQueue::TaskQueue(uint64_t entity_id)
{
  m_entity_id = entity_id;
}

flak::Components::TaskQueue::TaskQueue(Entity* entity)
{
  m_entity = entity;
  m_entity_id = entity->GetID();
}

const std::string flak::Components::TaskQueue::GetName()
{
  return "TaskQueue";
}
