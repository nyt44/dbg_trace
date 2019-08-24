#include "verbosity.hpp"

#include <mutex>

namespace dbg_trace
{
static Level verbosity_level = Level::kNone;
static std::mutex verbosity_level_mutex;

void SetVerbosity(Level level)
{
  std::lock_guard<std::mutex> _{verbosity_level_mutex};
  verbosity_level = level;
}

bool ShouldBeLogged(Level level)
{
  std::lock_guard<std::mutex> _{verbosity_level_mutex};
  return level <= verbosity_level;
}

} // namespace dbg_trace
