#include <string>

#include "dbg_trace.hpp"

int main()
{
  dbg_trace::Log("Example C String");

  std::string str{"Example C++ String"};
  dbg_trace::Log(str);

  dbg_trace::Log("int: {}", 1);
  dbg_trace::Log("float: {}", 3.14);
  dbg_trace::Log("bool: {}", true);
  dbg_trace::Log("Multiple data types: {}, {}, {}, {}", 23, "qwerty", 2.3, false);
}
