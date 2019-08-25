#include <string>

#include "dbg_trace.hpp"

int main()
{
  dbg_trace::SetVerbosity(dbg_trace::Level::kDebug);
  LOG_DEBUG("Example C String");

  std::string str{"Example C++ String"};
  LOG_DEBUG(str);

  LOG_DEBUG("int: {}", 1);
  LOG_DEBUG("float: {}", 3.14);
  LOG_DEBUG("bool: {}", true);
  LOG_DEBUG("Multiple data types: {}, {}, {}, {}", 23, "qwerty", 2.3, false);

  LOG_DEBUG("Error code 0x{:x}", 23);
}
