#include <iostream>
#include <chrono>
#include "sol/sol.hpp"
#include <Windows.h>
#include <vector>
#include "ecs.h"

struct Wrap {
	sol::table table;
};

int main() {
	
	ECS ecs;

	sol::state lua;

	lua.open_libraries(sol::lib::base, sol::lib::package);

	sol::table cache;

	lua.set_function("createEntity", [&ecs]() {		
		return ecs.create();
	});

	lua.set_function("getComponent", [&ecs](std::string component) {
		return ecs.getComponent(component);
	});

	lua.set_function("view", [&ecs](std::string table, sol::function function) {
		auto comp = ecs.getComponent(table);
		ecs.view([&ecs, &comp, &function](Entity entity) {
			function(entity);			
		}, comp);
	});

	lua.set_function("listview", [&ecs, &lua](std::string table) {
		auto comp = ecs.getComponent(table);
		std::vector<Entity> entities;
		ecs.view([&ecs, &comp, &entities](Entity entity) {
			entities.push_back(entity);
		}, comp);
		return sol::as_table(entities);
	});

	lua.set_function("assign-", [&ecs, &lua](Entity entity, std::string table) {
		auto newTable = lua.create_named_table(table);
		auto comp = ecs.getComponent(table);
		ecs.assign(entity, comp, new Wrap{ newTable });
	});

	lua.set_function("assign", [&ecs, &lua](Entity entity, std::string tableName, sol::table table) {		
		auto comp = ecs.getComponent(tableName);
		ecs.assign(entity, comp, new Wrap{ table });
	});

	lua.set_function("get", [&ecs, &lua](std::string table, Entity entity) {	
		return ecs.get<Wrap>(entity, ecs.getComponent(table))->table;
	});

	lua.set_function("get_with", [&ecs, &lua](Component comp, Entity entity) {
		return ecs.get<Wrap>(entity, comp)->table;
	});

	try {		
		lua.script_file("component.lua");
		lua.script_file("system.lua");
	} catch (std::exception ex) {
		std::cout << "error << " << ex.what() << std::endl;
	}

	auto update = lua["update"];

	auto x = 0;
	while (x < 1) {
		try {
			auto t0 = std::chrono::high_resolution_clock::now();

		//	update();

			auto t1 = std::chrono::high_resolution_clock::now();

			std::cout << "lua took to run: "
				<< std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()				
				<< " \n";

			//std::cout << "-----------------------------" << std::endl;
		} catch (std::exception ex) {
			std::cout << "error << " << ex.what() << std::endl;
		}
		Sleep(1000);
	}
	
	

	std::cout << "asd" << std::endl;
	return 0;
}