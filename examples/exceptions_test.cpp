#include "dbg_trace.hpp"

int main()
{
    dbg_trace::SetVerbosity(dbg_trace::Level::kError);

    try
    {
      LOG_AND_THROW("Test: {}", 1);
    }
    catch (const std::runtime_error& ex)
    {
      fmt::print("Exception caught: {}\n", ex.what());
    }

    try
    {
      int* ptr = nullptr;
      LOG_AND_THROW_IF_NULLPTR(ptr, "Test2: {}", 2);
    }
    catch (const std::runtime_error& ex)
    {
      fmt::print("Exception caught: {}\n", ex.what());
    }

    try
    {
      int x;
      int* ptr = &x;
      LOG_AND_THROW_IF_NULLPTR(ptr, "SHOULD NOT BE PRINTED: {}", 3);
    }
    catch (const std::runtime_error& ex)
    {
      fmt::print("Exception caught: {}\n", ex.what());
    }
}
