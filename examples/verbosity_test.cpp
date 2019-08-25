#include "dbg_trace.hpp"

void PrintTest()
{
  LOG_ERROR("Example1");
  LOG_WARNING("Example2");
  LOG_INFO("Example3");
  LOG_DEBUG("Example4");
}

void PrintExpectedCount(int expected_count)
{
  fmt::print("Example should be printed {} times\n", expected_count);
}

int main()
{
  PrintExpectedCount(0);
  PrintTest();

  dbg_trace::SetVerbosity(dbg_trace::Level::kError);
  PrintExpectedCount(1);
  PrintTest();

  dbg_trace::SetVerbosity(dbg_trace::Level::kWarning);
  PrintExpectedCount(2);
  PrintTest();

  dbg_trace::SetVerbosity(dbg_trace::Level::kInfo);
  PrintExpectedCount(3);
  PrintTest();

  dbg_trace::SetVerbosity(dbg_trace::Level::kDebug);
  PrintExpectedCount(4);
  PrintTest();

}
