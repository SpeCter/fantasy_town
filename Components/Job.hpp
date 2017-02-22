#pragma once
#include "Component.hpp"
#include <string>
#include "Entity.hpp"

namespace flak {
namespace Components {
    struct Job : public Component<Job>
    {
      Job(uint64_t entity_id,const std::string description);
      Job(Entity* entity,const std::string description);
      const std::string GetName() override;
      std::string m_description;

    };
  }
}
