#include "Tasks/GotoTask.hpp"

flak::Tasks::GotoTask::GotoTask(int x, int y)
  : x(x),
    y(y)
{
}

void flak::Tasks::GotoTask::SetOwner(Entity entity)
{
  m_velocity = entity.GetComponent<flak::Components::Velocity>();
  m_position = entity.GetComponent<flak::Components::Position>();
  m_assigned = true;
}

void flak::Tasks::GotoTask::Update(double dt)
{
  m_velocity->x = x - m_position->x;
  m_velocity->y = y - m_position->y;
  auto distance = std::sqrt(m_velocity->x*m_velocity->x + m_velocity->y*m_velocity->y);
  m_velocity->x /= distance;
  m_velocity->y /= distance;
  m_velocity->x *= 10.0;
  m_velocity->y *= 10.0;

}

bool flak::Tasks::GotoTask::Finished() const
{
  auto test_x = x - m_position->x;
  auto test_y = y - m_position->y;
  auto distance = std::sqrt(test_x*test_x + test_y*test_y);
  if(distance < 5.0)
  {
    return true;
  }
  return false;
}
