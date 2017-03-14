#pragma once
#include "Tasks/Task.hpp"

template<typename T,typename... Args>
T* CreateTask(Args&&... args)
{
  static uint64_t task_id = 1;
  T task = new T(args...);
  task->SetID(task_id++);
  return task;
}
