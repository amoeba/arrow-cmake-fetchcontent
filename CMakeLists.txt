# set minimum cmake version
cmake_minimum_required(VERSION 3.14)

# project name and language
project(example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Get Arrow
include(FetchContent)

FetchContent_Declare(ARROW
  GIT_REPOSITORY https://github.com/apache/arrow.git
  GIT_TAG        master
)

FetchContent_GetProperties(arrow)

if(NOT arrow_POPULATED)
  FetchContent_Populate(arrow)

  # This shouldn't be needed, come back to this and see what's up
  SET(ARROW_DEPENDENCY_SOURCE "SYSTEM")

  # Normal stuff goes here. This is based on a normal flight-debug preset
  SET(CMAKE_BUILD_TYPE Debug)
  SET(ARROW_BUILD_INTEGRATION False)
  SET(ARROW_BUILD_STATIC False)
  SET(ARROW_BUILD_TESTS False)
  SET(ARROW_COMPUTE True)
  SET(ARROW_CSV True)
  SET(ARROW_DATASET True)
  SET(ARROW_PARQUET True)
  SET(ARROW_EXTRA_ERROR_CONTEXT True)
  SET(ARROW_FILESYSTEM True)
  SET(ARROW_FLIGHT True)
  SET(ARROW_JSON True)
  SET(ARROW_WITH_RE2 False)
  SET(ARROW_WITH_UTF8PROC False)

  message(STATUS "${arrow_SOURCE_DIR}")
  add_subdirectory(${arrow_SOURCE_DIR}/cpp)
endif()

add_executable(main main.cc)
target_link_libraries(main PRIVATE Arrow::arrow_shared)
