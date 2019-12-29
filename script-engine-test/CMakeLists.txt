# CMakeList.txt : CMake project for script-engine-test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (script-engine-test main.cpp)

find_package(Lua)

#target_include_directories(script-engine-test PUBLIC ${LUAJIT_DIR}/includes)
#target_link_libraries(script-engine-test ${LUAJIT_DIR}/lib/lua51.lib)

target_include_directories(script-engine-test PUBLIC ${LUA_DIR}/include)
target_link_libraries(script-engine-test ${LUA_DIR}/lib/lua.lib)

target_include_directories(script-engine-test PUBLIC ${LUA_BRIDGE_DIR})
target_include_directories(script-engine-test PUBLIC ${LUA_BRIDGE_DIR}/detail)


