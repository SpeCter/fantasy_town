#include "Inventory.hpp"


ft::Components::Inventory::Inventory(uint64_t entity_id)
{
  m_entity_id = entity_id;
}



const std::string ft::Components::Inventory::GetName()
{
  std::string ret;
  ret.append("Inventory: ");
  for(auto&& item : m_items)
  {
    ret.append(item.GetName());
    ret.append(" ");
  }
  return ret;
}
