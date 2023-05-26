cmake_minimum_required(VERSION 3.14)

project(example LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

SET(ARROW_BUILD_SHARED True)
SET(ARROW_DEPENDENCY_SOURCE "SYSTEM")
SET(ARROW_SIMD_LEVEL NONE)

# Get Arrow
include(FetchContent)

FetchContent_Declare(Arrow
  GIT_REPOSITORY https://github.com/apache/arrow.git
  GIT_TAG        main
  GIT_SHALLOW    TRUE SOURCE_SUBDIR cpp
  OVERRIDE_FIND_PACKAGE
)

FetchContent_MakeAvailable(Arrow)

# NOTE: I had to add this to make headers available which I find weird
target_include_directories(
  arrow_shared
  INTERFACE "$<BUILD_INTERFACE:${arrow_SOURCE_DIR}/cpp/src>"
)

# main
add_executable(example example.cc)

target_link_libraries(example PRIVATE arrow_shared)
