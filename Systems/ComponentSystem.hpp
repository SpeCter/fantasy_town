#pragma once
#include <vector>
#include "Entity.hpp"
#include <iostream>

struct ComponentSystemBase
{
  ComponentSystemBase()
    : m_enabled(true)
  {
  }
  virtual ~ComponentSystemBase()
  {
  }

  virtual void Update(double delta = 0)         = 0;
  virtual void EntityUpdated(Entity entity) = 0;
  virtual const std::string GetName() const = 0;
  void Enable()
  {
    m_enabled = true;
  }
  void Disable()
  {
    m_enabled = false;
  }
  bool Enabled()
  {
    return m_enabled;
  }

  bool      m_enabled;
  uint64_t  m_id;
};

template <typename... Args>
struct ComponentSystem : public ComponentSystemBase
{
  ComponentSystem()
  {
  }
  virtual ~ComponentSystem()
  {
  }

  virtual void Update(double dt = 0) = 0;
  virtual void EntityUpdated(Entity entity) override
  {
    std::vector<int> result = {entity.HasComponent<Args>()...};
    bool hasAllComponents = true;
    for(auto&& ok : result)
    {
       hasAllComponents &= ok;
    }
    if(hasAllComponents)
    {
      m_entities.push_back(entity);
      m_components.push_back(std::make_tuple(entity.GetComponent<Args>()...));
    }
  }


  std::vector<Entity>               m_entities;
  std::vector<std::tuple<Args*...>> m_components;
};


