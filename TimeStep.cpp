#include "TimeStep.hpp"


flak::TimeStep::TimeStep()
  : m_step(sf::seconds(0.0016)),
    m_overall(sf::seconds(0.0)),
    m_accumulator(0.0)
{

}

void flak::TimeStep::Update(sf::Time dt)
{
  m_accumulator += dt.asSeconds();
}

bool flak::TimeStep::timeToIntegrate()
{
  if(m_accumulator >= m_step.asSeconds())
  {
    m_accumulator -= m_step.asSeconds();
    m_overall     += m_step;
    return true;
  }
  return false;
}

sf::Time flak::TimeStep::GetStep() const
{
  return m_step;
}

sf::Time flak::TimeStep::GetOverall() const
{
  return m_overall;
}
