#include "InventoryItem.hpp"

ft::Components::InventoryItem::InventoryItem(const std::string& label, const std::string& description)
  : label(label),
    description(description)
{
}

const std::string ft::Components::InventoryItem::GetName()
{
  return label;
}
