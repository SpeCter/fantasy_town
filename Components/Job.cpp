#include "Job.hpp"

flak::Components::Job::Job(uint64_t entity_id, const std::string description)
  : m_description(description)
{
  m_entity_id = entity_id;
}

flak::Components::Job::Job(Entity* entity, const std::string description)
  : m_description(description)
{
  m_entity_id = entity->GetID();
  m_entity = entity;
}

const std::string flak::Components::Job::GetName()
{
  return "Job";
}
