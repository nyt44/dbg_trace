#pragma once

namespace dbg_trace
{

enum class Level
{
  kNone,
  kError,
  kWarning,
  kInfo,
  kDebug
};

void SetVerbosity(Level level);
bool ShouldBeLogged(Level level);

} // namespace dbg_trace
