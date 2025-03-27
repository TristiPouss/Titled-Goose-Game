cmake_minimum_required(VERSION 3.10)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra ")

# Set compiler to clang
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

# Set the project name
project(TitledGooseGame)

add_subdirectory(Src/tests)

# Add the executable

file(GLOB_RECURSE GAME_SOURCES Src/*.cpp)
add_executable(test ${GAME_SOURCES})

# Include directory for libPNG headers (si nécessaire)
include_directories(${CMAKE_SOURCE_DIR}/Include/)

# Link the necessary libraries
target_link_libraries(test GL GLU glut ${CMAKE_SOURCE_DIR}/Lib/libPNG.so)