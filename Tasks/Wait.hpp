#pragma once
#include "Tasks/Task.hpp"
#include "Components/Velocity.hpp"
#include "World.hpp"

namespace flak
{
  namespace Tasks
  {
    struct Wait : public Task
    {
      void SetOwner(Entity* entity) override
      {
        m_velocity = entity->GetComponent<Components::Velocity>();
        m_owner = entity->GetID();
      }
      void SetOwner(uint64_t entity_id) override
      {
        auto entity = World::Get().GetEntity(entity_id);
        m_velocity  = entity.GetComponent<Components::Velocity>();
        m_owner     = entity_id;
      }
      const std::string GetTaskName() override
      {
        return "Wait";
      }

      void Update(double dt) override
      {
        m_velocity->x = 0.0;
        m_velocity->y = 0.0;
      }
      bool Finished() const override
      {
        return true;
      }
      Components::Velocity* m_velocity;
    };
  }
}
