# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set (CMAKE_CXX_STANDARD 17)

project ("script-engine-test")

set(LUAJIT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/luajit)
set(LUA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/lua)

set(LUA_BRIDGE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/LuaBridge)

# Include sub-projects.
add_subdirectory ("script-engine-test")

include_directories("script-engine-test")