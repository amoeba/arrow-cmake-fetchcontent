cmake_minimum_required(VERSION 3.14)

project(example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# Get Arrow
include(FetchContent)

FetchContent_Declare(Arrow
  GIT_REPOSITORY https://github.com/apache/arrow.git
  GIT_TAG        main
  GIT_SHALLOW    TRUE SOURCE_SUBDIR cpp
)

FetchContent_GetProperties(arrow)

# TODO: See if I can simplify this next block
if(NOT arrow_POPULATED)
  FetchContent_Populate(arrow)

  # TODO: This shouldn't be needed, come back to this and see what's up
  SET(ARROW_DEPENDENCY_SOURCE "SYSTEM")

  # Normal stuff goes here. This is based on a normal flight-debug preset
  SET(ARROW_BUILD_INTEGRATION False)

  # TODO: I needed to set this for some reason, otherwise I get this cryptic
  # error CMake Error at build/_deps/arrow-src/cpp/src/arrow/CMakeLists.txt:682
  # (add_dependencies): add_dependencies called with incorrect number of
  #   arguments
  # 
  # which is because ARROW_SIMD_LEVEL isn't set. Before the error, CMake
  # actually warns about this
  #
  # -- Arrow build warning level: CHECKIN CMake Warning at
  # build/_deps/arrow-src/cpp/cmake_modules/SetupCxxFlags.cmake:514 (message):
  # ARROW_SIMD_LEVEL= not supported by Arm. Call Stack (most recent call first):
  # build/_deps/arrow-src/cpp/CMakeLists.txt:417 (include)
  SET(ARROW_SIMD_LEVEL NONE)

  SET(ARROW_BUILD_STATIC False)

  # TODO: I appear to also have to set this?
  SET(ARROW_BUILD_SHARED True)

  SET(ARROW_BUILD_TESTS False)
  SET(ARROW_ACERO True)
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

  add_subdirectory(${arrow_SOURCE_DIR}/cpp)
endif()

add_executable(main main.cc)

# TODO: I found out I had to add this to ensure headers get copied into the
# Arrow build
target_include_directories(
  arrow_shared
  INTERFACE "$<BUILD_INTERFACE:${arrow_SOURCE_DIR}/cpp/src>"
            "$<BUILD_INTERFACE:${arrow_SOURCE_DIR}/cpp/src/generated>"
            "$<BUILD_INTERFACE:${arrow_SOURCE_DIR}/cpp/thirdparty/hadoop/include>"
            "$<BUILD_INTERFACE:${arrow_SOURCE_DIR}/cpp/thirdparty/flatbuffers/include>"
)

target_link_libraries(main PRIVATE arrow_shared)
