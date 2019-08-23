file(GLOB SOURCE_FILES "*.hpp" "*.cpp")


add_library(dbg_trace SHARED ${SOURCE_FILES})
target_link_libraries(dbg_trace fmt)

target_include_directories(dbg_trace PUBLIC .)
