#include <iostream>
#include "lua.hpp"
#include <LuaBridge/LuaBridge.h>
#include <string>
#include <filesystem>


using namespace luabridge;
namespace fs = std::filesystem;

class Player {
private:
	int value;
public:
	int pValue;

	Player() {
		value = 0;
		pValue = 100;
	}	
	void sumValue(int _value) {
		value = value + _value;
	}
	int getValue() {
		return value;
	}
};

//part2

void printMessage(const std::string& s) {
	std::cout << "cpp: " << s << std::endl;
}

int main(int argc, char* argv[]) {
	
/*	fs::path path;
	if (argc > 1) {
		path = std::string(argv[argc - 1]);
	} else {
		path = fs::current_path();
	}
	
	for (const auto& entry : fs::directory_iterator(path)) {
		std::cout << entry.path() << std::endl;
	}*/	

	//lua_State* L = luaL_newstate();
	//luaL_openlibs(L);

	//getGlobalNamespace(L)
	//	.beginNamespace("evolutio")		
	//	.endNamespace();

	//getGlobalNamespace(L)
	//	.beginNamespace("functions")
	//		.addFunction("printMessage", printMessage)
	//	.endNamespace();

	//getGlobalNamespace(L)
	//	.beginClass<Player>("Player")
	//		.addConstructor <void (*) (void)>()
	//		.addProperty("pValue", &Player::pValue)
	//		.addFunction("sumValue", &Player::sumValue)
	//		.addFunction("getValue", &Player::getValue)
	//	.endClass();

	//luaL_loadfile(L, "function.lua");
	//lua_pcall(L, 0, 0, 0);

	//luaL_loadfile(L, "pt2.lua");
	//lua_pcall(L, 0, 0, 0);
	//LuaRef print1 = getGlobal(L, "printMsg");

	//try {		
	//	LuaRef asd = getGlobal(L, "evolutio.test");
	//	if (!asd) {
	//		std::cout << "not found" << std::endl;
	//	} else {
	//		//asd();
	//	}
	//	
	//} catch (const std::exception & e) {
	//	std::cout << e.what() << std::endl;
	//}
	//
	//
	//LuaRef sum = getGlobal(L, "sum");

	//Player player;	

	//try {
	//	sum(&player);
	//} catch (const std::exception & e) {
	//	std::cout << e.what() << std::endl;
	//}

	// std::cout << "from c: " << player.getValue() << std::endl;

	

	/*luaL_loadfile(L, "pt2-1.lua");
	lua_pcall(L, 0, 0, 0);
	LuaRef print2 = getGlobal(L, "printMsg");


	print1();
	print2();
	print1();
	print2();*/

	//changing

	/*std::string nada;
	std::cin >> nada;
	

	luaL_loadfile(L, "pt2.lua");
	lua_pcall(L, 0, 0, 0);

	print1 = getGlobal(L, "printMsg");
	print1();*/
}




/*
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
*/