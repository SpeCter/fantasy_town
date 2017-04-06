#pragma once
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <iostream>
#include "Systems/ComponentSystem.hpp"
#include "ComponentManager.hpp"
#include "Entity.hpp"
#include "Type.hpp"


namespace ft
{
  class World
  {
  public:
    World();
    //void Update(double delta);
    Entity& CreateEntity();
    static World& Get()
    {
      static World world;
      return world;
    }

    Entity GetEntity(uint64_t entity_id);
    std::vector<std::string> GetEntityNames();
    void EntityUpdated(uint64_t entity);
    template<typename T,typename... Args>
    void AddComponent(uint64_t entity, Args&&... args)
    {
      m_componentManager.Add(entity,std::move(args...));
    }

    template<typename T,typename... Args>
    T* RegisterSystem(Args&&... args)
    {
      m_systems[Type::value<T>()] = new T(args...);
      return static_cast<T*>(m_systems[Type::value<T>()]);
    }
    template<typename T>
    T* GetSystem()
    {
      return static_cast<T*>(m_systems[Type::value<T>()]);
    }

    void Finished(uint64_t entity);
    template<typename T>
    void DisableSystem()
    {
      auto system = m_systems[Type::value<T>()];
      system->Disable();
    }
    template<typename T>
    void EnableSystem()
    {
      auto system = m_systems[Type::value<T>()];
      system->Enable();
    }

    void PrintSystems();
    std::vector<Entity>* GetEntities()
    {
      return &m_entities;
    }
    std::vector<std::string> GetWorkerNames();

  private:
    ComponentManager                                  m_componentManager;
    std::unordered_map<uint64_t,ComponentSystemBase*> m_systems;
    std::vector<Entity>                               m_entities;
    uint64_t next_id = 0;
    uint64_t next_system_id = 0;
  };
}



