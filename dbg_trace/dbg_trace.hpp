#pragma once

#include <utility>
#include <fmt/format.h>

#include "verbosity.hpp"

namespace dbg_trace
{

template <typename... Args>
void Error(Args... args)
{
  if (ShouldBeLogged(Level::kError))
  {
    fmt::print(std::forward<Args>(args)...);
    fmt::print("\n");
  }
}

template <typename... Args>
void Warning(Args... args)
{
  if (ShouldBeLogged(Level::kWarning))
  {
    fmt::print(std::forward<Args>(args)...);
    fmt::print("\n");
  }
}

template <typename... Args>
void Info(Args... args)
{
  if (ShouldBeLogged(Level::kInfo))
  {
    fmt::print(std::forward<Args>(args)...);
    fmt::print("\n");
  }
}

template <typename... Args>
void Debug(Args... args)
{
  if (ShouldBeLogged(Level::kDebug))
  {
    fmt::print(std::forward<Args>(args)...);
    fmt::print("\n");
  }
}

} // namespace dbg_trace
