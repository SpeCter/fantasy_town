#include "Components/TaskQueue.hpp"
#include "Entity.hpp"

flak::Components::TaskQueue::TaskQueue(uint64_t entity_id)
{
  m_entity_id = entity_id;
}

const std::string flak::Components::TaskQueue::GetName()
{
  return "TaskQueue";
}

void flak::Components::TaskQueue::Pop()
{
  m_tasks.pop_front();
}

void flak::Components::TaskQueue::Push(flak::Tasks::Task* task)
{
  m_tasks.push_back(task);
}
