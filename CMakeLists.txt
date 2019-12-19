# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("script-engine-test")

set(LUAJIT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/luajit)

# Include sub-projects.
add_subdirectory ("script-engine-test")