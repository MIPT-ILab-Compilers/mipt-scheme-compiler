 /**
* @file:module.hpp
* Header of classes Module and Function.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#pragma once

#include <vector>
#include <string> 
#include <map>
#include "object.hpp"

namespace ir
{

class Function
{
	public:
		Function(const std::string &name) : function_name(name) {};
		~Function();
		
		// add one object at the end of apropriate vector.
		void addLocalObject(Object *); 
		void addArgument(Object *); 

		const std::string &getFunctionName();
		const std::vector<Object *> &getLocalObjects();
		const std::vector<Object *> &getArguments();

	private:
		std::string function_name;
		std::vector<Object *> local_objects;
		std::vector<Object *> arguments;
};

class SymbolTable
{
	friend class Module;	

	~SymbolTable();

	std::map<std::string, Object *> object_table;
	std::map<std::string, Function *> function_table;
};

class Module 
{
	public:
		~Module();

		// add data to appropriate map in symbol_table and add it at the end of appropriate vector (all_functions or all_global_objects).
		// If such symbol already exists it will be changed.
		void addSymbol(const std::string &symbol_name, Object *data);
		void addSymbol(const std::string &symbol_name, Function *data);

		// getters
		Object *getSymbolObject(const std::string &symbol_name); 
		Function *getSymbolFunction(const std::string &symbol_name);

		const std::vector<Function *> &getAllFunctions();
		const std::vector<Object *> &getAllGlobalObjects();

	private:
		SymbolTable table;
		std::vector<Object *> all_global_objects;
		std::vector<Function *> all_functions;
};

}//namespace ir
