#include "Job.hpp"

flak::Components::Job::Job(uint64_t entity_id, const std::string description)
  : m_description(description)
{
  m_entity_id = entity_id;
}

const std::string flak::Components::Job::GetName()
{
  return "Job";
}
