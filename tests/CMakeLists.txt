cmake_minimum_required(VERSION 3.10)

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

add_executable(testGooseGameModel
  hello_test.cc
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