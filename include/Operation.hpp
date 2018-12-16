#ifndef _PM_OPERATION_H
#define _PM_OPERATION_H

#include <em/EventManager.hpp>
#include <PMEvent.hpp>
#include <Project.hpp>

namespace pm
{
class Operation : public em::EventManager<PMEvent, std::map<std::string, Project &>>
{

public:
  typedef std::function<void()> OperationCallback;

private:
  OperationCallback operationCallback;

public:
  Operation(OperationCallback);
  ~Operation();
};
} // namespace dot

#endif
