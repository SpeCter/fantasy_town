#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include "Type.hpp"
#include "Components/Component.hpp"

class World;
class ComponentManager
{
   using component_map = std::unordered_map<uint64_t,std::vector<flak::Components::BaseComponent*>*>;
public:
   ComponentManager(World& world)
    : m_world(world)
   {

   }
   ~ComponentManager() {}


   template<typename T,typename... Args>
   void Add(uint64_t entity,Args&&... args)
   {
      std::vector<flak::Components::BaseComponent*>* container = map[Type::value<T>()];
      if(container == nullptr)
      {
         map[Type::value<T>()] = new std::vector<flak::Components::BaseComponent*>();
      }

      map[Type::value<T>()]->push_back(new T(entity,args...));
      //ComponentAdded(entity);
   }
   template<typename T>
   void Remove(uint64_t entity)
   {
      auto container = map[Type::value<T>()];
      for(auto&& ent : container)
      {

      }
   }

   template<typename T,typename... Args>
   void Add(Entity* entity,Args&&... args)
   {
      std::vector<flak::Components::BaseComponent*>* container = map[Type::value<T>()];
      if(container == nullptr)
      {
         map[Type::value<T>()] = new std::vector<flak::Components::BaseComponent*>();
      }

      map[Type::value<T>()]->push_back(new T(entity,args...));
      //ComponentAdded(entity);
   }
   void ComponentAdded(uint64_t entity);
   template<typename T>
   bool HasComponent(uint64_t entity)
   {
      auto container = map[Type::value<T>()];
      if(!container) return false;
      auto it = std::find_if(container->begin(),container->end(),
                             [&] (const flak::Components::BaseComponent* component)
      {
         return component->m_entity_id == entity;
      });
      return it != container->end();
   }
   template<typename T>
   T* Get(uint64_t ent)
   {
      auto container = map[Type::value<T>()];
      auto it = std::find_if(container->begin(),container->end(),
                             [&] (const flak::Components::BaseComponent* component)
      {
         return component->m_entity_id == ent;
      });

      return static_cast<T*>(*it);
   }
   std::vector<std::string> GetAllComponents(uint64_t entity)
   {
     std::vector<std::string> strings;
     for(auto&& container : map)
     {
       auto it = std::find_if(container.second->begin(),container.second->end(),
                              [&] (const flak::Components::BaseComponent* component)
       {
          return component->m_entity_id == entity;
       });

       if(it != container.second->end())
       {
         strings.push_back((*it)->GetName());
       }
     }
     return strings;
   }

   template<typename... Args>
   std::tuple<Args*...> getComponents(uint64_t ent)
   {
      return std::make_tuple(Get<Args>(ent)...);
   }

   template<typename... Args>
   bool hasComponents(unsigned int e)
   {
      bool result = {true && HasComponent<Args>(e)...};
      return result;
   }
   component_map  map;
   World&         m_world;
};


