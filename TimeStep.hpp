#pragma once
#include <SFML/System/Time.hpp>

namespace ft
{
  class TimeStep
  {
  public:
    TimeStep();
    void Update(sf::Time dt);
    bool timeToIntegrate();
    void SetStep(sf::Time step);
    sf::Time GetStep() const;
    sf::Time GetOverall() const;
  private:
    sf::Time  m_step;
    sf::Time  m_overall;
    float     m_accumulator;

  };

}

