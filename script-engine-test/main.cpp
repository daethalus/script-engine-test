#include <iostream>
#include "lua.hpp"

int main() {

	//init lua state
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);	
	

	//create table
	lua_newtable(L);
	int tab_idx = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_rawgeti(L, LUA_REGISTRYINDEX, tab_idx);

	//load file 1 
	luaL_loadfile(L, "test1.lua");
	lua_pcall(L, 0, 0, 0);		  

	//get method from file
	lua_getglobal(L, "update");
	//store the method
	int update1 = luaL_ref(L, -2);

	//get another method from file 1
	lua_getglobal(L, "draw");
	if (lua_isfunction(L, -1)) {
		int draw1 = luaL_ref(L, -2);
	} else {
		lua_pop(L, 1);
		std::cout << "cant find draw in file 1" << std::endl;
	}
	//store
	


	//load file 2
	luaL_loadfile(L, "test2.lua");
	lua_pcall(L, 0, 0, 0);

	//get method from file2
	lua_getglobal(L, "update");
	int update2;
	if (lua_isfunction(L, -1)) {
		update2 = luaL_ref(L, -2);
	}
	//store
	

	//get another method from file 2
	lua_getglobal(L, "draw");
	//store
	int draw2 = luaL_ref(L, -2);

	
	lua_pop(L, 1);


	lua_rawgeti(L, LUA_REGISTRYINDEX, tab_idx); // retrieve function table
	lua_rawgeti(L, -1, update1);
	lua_pcall(L, 0, 0, 0);

	lua_rawgeti(L, -1, update2);
	lua_pcall(L, 0, 0, 0);

	lua_rawgeti(L, -1, draw2);
	lua_pcall(L, 0, 0, 0);

	lua_rawgeti(L, -1, update1);
	lua_pcall(L, 0, 0, 0);

	lua_rawgeti(L, -1, draw2);
	lua_pcall(L, 0, 0, 0);

	lua_rawgeti(L, -1, update1);
	lua_pcall(L, 0, 0, 0);

	lua_pop(L, 1);


	lua_close(L);

	std::cout << "hellow word" << std::endl;
	return 0;
}