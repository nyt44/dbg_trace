#include <string>

#include "dbg_trace.hpp"

int main()
{
  dbg_trace::SetVerbosity(dbg_trace::Level::kDebug);
  dbg_trace::Debug("Example C String");

  std::string str{"Example C++ String"};
  dbg_trace::Debug(str);

  dbg_trace::Debug("int: {}", 1);
  dbg_trace::Debug("float: {}", 3.14);
  dbg_trace::Debug("bool: {}", true);
  dbg_trace::Debug("Multiple data types: {}, {}, {}, {}", 23, "qwerty", 2.3, false);
}
