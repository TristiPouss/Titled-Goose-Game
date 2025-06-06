cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(Testing_GooseGame
  LANGUAGES CXX
)

find_package(Threads)

# Auto download googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        f8d7d77c06936315286eb55f8de22cd23c188571 # release-1.14.0
)
FetchContent_MakeAvailable(googletest)

file(GLOB MODEL_SOURCES "../model/*.cc")
file(GLOB MODEL_HEADERS "../model/*.h")

add_executable(testGooseGameModel
  unit_test.cc
  ${MODEL_SOURCES}
  ${MODEL_HEADERS}
)

target_include_directories(testGooseGameModel
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

target_compile_options(testGooseGameModel
  PRIVATE
  "-Wall" "-Wextra" "-g" "-O0" "-fsanitize=address,undefined"
)

target_compile_features(testGooseGameModel
  PUBLIC
    cxx_std_17
)

set_target_properties(testGooseGameModel
  PROPERTIES
    CXX_EXTENSIONS OFF
    LINK_FLAGS "-fsanitize=address,undefined"
)

target_link_libraries(testGooseGameModel
  PRIVATE
    GTest::gtest_main
    Threads::Threads
)

include(GoogleTest)
gtest_discover_tests(testGooseGameModel)