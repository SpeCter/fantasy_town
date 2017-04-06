#include "TimeStep.hpp"


ft::TimeStep::TimeStep()
  : m_step(sf::seconds(0.0016f)),
    m_overall(sf::seconds(0.0)),
    m_accumulator(0.0)
{

}

void ft::TimeStep::Update(sf::Time dt)
{
  m_accumulator += dt.asSeconds();
}

bool ft::TimeStep::timeToIntegrate()
{
  if(m_accumulator >= m_step.asSeconds())
  {
    m_accumulator -= m_step.asSeconds();
    m_overall     += m_step;
    return true;
  }
  return false;
}

sf::Time ft::TimeStep::GetStep() const
{
  return m_step;
}

sf::Time ft::TimeStep::GetOverall() const
{
  return m_overall;
}
