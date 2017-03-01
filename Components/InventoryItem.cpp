#include "InventoryItem.hpp"

flak::Components::InventoryItem::InventoryItem(const std::string& label, const std::string& description)
  : label(label),
    description(description)
{
}

const std::string flak::Components::InventoryItem::GetName()
{
  return label;
}
