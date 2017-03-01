#pragma once
#include "Tasks/Task.hpp"
#include "Components/Inventory.hpp"

namespace flak
{
  namespace Tasks
  {
    struct ChopWood : public Task
    {
      ChopWood()
      {
        m_choptime = 5.0;
      }

      void SetOwner(Entity entity) override
      {
        m_inventory = entity.GetComponent<Components::Inventory>();
        m_assigned = true;
      }
      void Update(double dt) override
      {
        if(m_choptime < 0.0)
        {
          m_choptime = 5.0;
        }
        m_choptime -= dt;
      }
      bool Finished() const override
      {
        if(m_choptime < 0.0)
        {
          m_inventory->m_items.push_back(Components::InventoryItem("Treetrunk","A chopped treetrunk"));
          return true;
        }
        return false;
      }
      double m_choptime;
      flak::Components::Inventory* m_inventory;
    };
  }
}
