#pragma once
#include "Components/Component.hpp"

namespace ft
{
  namespace Components
  {
    struct InventoryItem : public Component<InventoryItem>
    {
      InventoryItem(const std::string& label, const std::string& description);
      const std::string GetName() override;

      std::string label;
      std::string description;

    };
  }
}
