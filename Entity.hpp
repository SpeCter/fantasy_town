#pragma once
#include "ComponentManager.hpp"
#include <vector>

namespace flak
{
  namespace Components
  {
    struct ComponentBase;
  }
}
class Entity
{
public:
  Entity(ComponentManager& cm,uint64_t id)
    : m_componentManager(cm),
      m_id(id)
  {

  }
  template<typename T,typename...Args>
  void AddComponent(Args&&... args)
  {
    m_componentManager.Add<T>(m_id,args...);
    m_component_ids.push_back(Type::value<T>());
  }
  template<typename T>
  bool HasComponent() const
  {
    return m_componentManager.HasComponent<T>(m_id);
  }
  template<typename T>
  T* GetComponent() const
  {
    return m_componentManager.Get<T>(m_id);
  }
  std::vector<std::string> GetAllComponents()
  {
    return m_componentManager.GetAllComponents(m_id);
  }
  uint64_t GetID() const
  {
    return m_id;
  }

  friend bool operator==(const Entity& lhs, const Entity& rhs)
  {
    return lhs.m_id == rhs.m_id;
  }
  friend bool operator!=(const Entity& lhs, const Entity& rhs)
  {
    return !(lhs == rhs);
  }
  operator uint64_t() const
  {
    return m_id;
  }
  std::vector<uint64_t>   m_component_ids;
private:
  ComponentManager&       m_componentManager;
  uint64_t                m_id;
};
