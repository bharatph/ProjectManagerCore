#include <Operation.hpp>
#include <PMEvent.hpp>

pm::Operation::~Operation()
{
}

pm::Operation::Operation(OperationCallback operationCallback) : operationCallback(operationCallback)
{
}
