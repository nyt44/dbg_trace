#pragma once

#include <cstring>
#include <utility>
#include <unordered_map>
#include <string>

#include <fmt/format.h>

#include "verbosity.hpp"

#define FILE_NAME \
  (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_ERROR(...) \
  dbg_trace::Print(dbg_trace::Level::kError, FILE_NAME, __LINE__, __VA_ARGS__)
#define LOG_WARNING(...) \
  dbg_trace::Print(dbg_trace::Level::kWarning, FILE_NAME, __LINE__, __VA_ARGS__)
#define LOG_INFO(...) \
  dbg_trace::Print(dbg_trace::Level::kInfo, FILE_NAME, __LINE__, __VA_ARGS__)
#define LOG_DEBUG(...) \
  dbg_trace::Print(dbg_trace::Level::kDebug, FILE_NAME, __LINE__, __VA_ARGS__)

namespace dbg_trace
{

const std::unordered_map<Level, std::string> verbosity_level_string =
{
  {Level::kError, "ERROR"},
  {Level::kWarning, "WARNING"},
  {Level::kInfo, "INFO"},
  {Level::kDebug, "DEBUG"}
};

template <typename... Args>
void Print(Level verbosity_level, const char* file_name, int line_number, Args... args)
{
  if (ShouldBeLogged(verbosity_level))
  {
    fmt::print("[{}] {}:{}  ", verbosity_level_string.at(verbosity_level), file_name, line_number);
    fmt::print(std::forward<Args>(args)...);
    fmt::print("\n");
  }
}

} // namespace dbg_trace
