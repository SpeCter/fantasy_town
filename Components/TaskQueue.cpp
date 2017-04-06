#include "Components/TaskQueue.hpp"
#include "Entity.hpp"

ft::Components::TaskQueue::TaskQueue(uint64_t entity_id)
{
  m_entity_id = entity_id;
}

const std::string ft::Components::TaskQueue::GetName()
{
  return "TaskQueue";
}

void ft::Components::TaskQueue::Pop()
{
  m_tasks.pop_front();
}

void ft::Components::TaskQueue::Push(ft::Tasks::Task* task)
{
  m_tasks.push_back(task);
}
