#include "dbg_trace.hpp"

void PrintTest()
{
  dbg_trace::Error("Example1");
  dbg_trace::Warning("Example2");
  dbg_trace::Info("Example3");
  dbg_trace::Debug("Example4");
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
