#pragma once
#include "Tasks/Task.hpp"
#include "Tasks/GotoTask.hpp"
#include "Tasks/ChopWood.hpp"
#include "Tasks/Wait.hpp"
#include "randutils.hpp"
#include "Tasks/TaskFactory.hpp"

namespace flak
{
  namespace Tasks
  {
    struct GetWood : public Task
    {
      GetWood()
      {
        randutils::mt19937_rng rng;
        m_subtasks.push_back(new GotoTask(rng.uniform(0,100),rng.uniform(0,100)));
        m_subtasks.push_back(new Wait());
        m_subtasks.push_back(new ChopWood());
        m_subtasks.push_back(new GotoTask(400,300));
      }
      void Update(double dt) override
      {
        m_subtasks[n]->Update(dt);
        if(m_subtasks[n]->Finished())
        {
          n++;
          if(n == m_subtasks.size()) n = 0;
        }
      }
      bool Finished() const override
      {
        return false;
      }
      unsigned int n = 0;

      void SetOwner(Entity entity) override
      {
        m_owner = entity;
        for(auto&& task : m_subtasks)
        {
          task->SetOwner(entity);
        }
        m_assigned = true;
      }
      uint64_t GetOwnerID() const override
      {
        return m_owner;
      }
    };
  }
}
