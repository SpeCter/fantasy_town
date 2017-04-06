#include "Tasks/GetWood.hpp"
//#incldue "

ft::Tasks::GetWood::GetWood()
  : n(0)
{
  m_repeat    = false;
  m_assigned  = false;
}

void ft::Tasks::GetWood::Update(double dt)
{
  if(n >= m_subtasks.size() && m_repeat == true)
  {
    n = 0;
  }
  else if(n >= m_subtasks.size() && m_repeat == false)
  {
    return;
  }
  m_subtasks[n]->Update(dt);
  if(m_subtasks[n]->Finished())
  {
    n++;
  }
}

bool ft::Tasks::GetWood::Finished() const
{
  return m_repeat && n >= m_subtasks.size();
}

void ft::Tasks::GetWood::SetOwner(Entity* entity)
{
  m_owner = entity->GetID();
  for(auto&& task : m_subtasks)
  {
    task->SetOwner(entity);
  }
  m_assigned = true;
}

void ft::Tasks::GetWood::SetOwner(uint64_t ent)
{
  m_owner = ent;
  for(auto&& task : m_subtasks)
  {
    task->SetOwner(ent);
  }
  m_assigned = true;
}

const std::string ft::Tasks::GetWood::GetTaskName()
{
  if(n < m_subtasks.size())
  {
    return "GetWood - " + m_subtasks[n]->GetTaskName();
  }
  return "GetWood - Finished";
}
