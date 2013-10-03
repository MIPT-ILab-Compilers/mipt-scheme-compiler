 /**
* @file:module.hpp
* Implementation of classes Module and Function.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#include "module.hpp"

namespace ir
{

Function::~Function()
{
	std::vector<Object *>::iterator it;
	for(it = local_objects.begin(); it != local_objects.end(); it++)
		delete *it;

	for(it = arguments.begin(); it != arguments.end(); it++)
		delete *it;
}

inline void Function::addLocalObject(Object *obj)
{
	local_objects.push_back(obj);
}

inline void Function::addArgument(Object *obj)
{
	arguments.push_back(obj);
}

inline const std::string &Function::getFunctionName()
{
	return function_name;
}

inline const std::vector<Object *> &Function::getLocalObjects()
{
	return arguments;
}

inline const std::vector<Object *> &Function::getArguments()
{
	return local_objects;
}

SymbolTable::~SymbolTable()
{
	std::map<std::string, Object *>::iterator it;
	for (it = object_table.begin(); it != object_table.end(); it++)
		delete it->second;

	std::map<std::string, Function *>::iterator it1;
	for (it1 = function_table.begin(); it1 != function_table.end(); it1++)
		delete it1->second;
}

Module::~Module()
{
	std::vector<Object *>::iterator it;
	for (it = all_global_objects.begin(); it != all_global_objects.end(); it++)
		delete *it;

	std::vector<Function *>::iterator it1;
	for (it1 = all_functions.begin(); it1 != all_functions.end(); it1++)
		delete *it1;
}

void Module::addSymbol(const std::string &symbol_name, Object *data)
{
	table.object_table[symbol_name] = data;
	all_global_objects.push_back(data);
}

void Module::addSymbol(const std::string &symbol_name, Function *data)
{
	table.function_table[symbol_name] = data;
	all_functions.push_back(data);
}

inline Function *Module::getSymbolFunction(const std::string &symbol_name)
{	
	return table.function_table[symbol_name];
}

inline Object *Module::getSymbolObject(const std::string &symbol_name)
{	
	return table.object_table[symbol_name];
}

inline const std::vector<Function *> &Module::getAllFunctions()
{
	return all_functions;
}

inline const std::vector<Object *> &Module::getAllGlobalObjects()
{
	return all_global_objects;
}

}//namespace ir
