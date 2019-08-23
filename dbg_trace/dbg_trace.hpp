#pragma once

#include <utility>
#include <fmt/format.h>

#include "verbosity.hpp"

namespace dbg_trace
{

template <typename... Args>
void Log(Args... args)
{
  if (ShouldBeLogged())
  {
    fmt::print(std::forward<Args>(args)...);
    fmt::print("\n");
  }
}

}
