#pragma once
#include "Components/Component.hpp"
#include "Components/InventoryItem.hpp"
#include <vector>

namespace ft
{
  namespace Components
  {
    struct Inventory : public  Component<Inventory>
    {
    public:
      Inventory(uint64_t entity_id);
      const std::string GetName() override;
      std::vector<InventoryItem> m_items;
    };
  }
}

