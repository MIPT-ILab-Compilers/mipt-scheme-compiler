
#include "module.hpp"

Function::Function(std::string &name)
{
	function_name = name;
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

void Module::addSymbol(std::string symbol_name, Object &data)
{
	*(table.object_table[symbol_name]) = data;
	all_global_objects.push_back(&data);
}

void Module::addSymbol(std::string symbol_name, Function &data)
{
	*(table.function_table[symbol_name]) = data;
	all_functions.push_back(&data);
}

inline void Module::getSymbolData(std::string symbol_name, Function &A)
{	
	A = *(table.function_table[symbol_name]);
}

inline void Module::getSymbolData(std::string symbol_name, Object &A)
{	
	A = *(table.object_table[symbol_name]);
}

inline const std::vector<Function *> &Module::getAllFunctions()
{
	return all_functions;
}

inline const std::vector<Object *> &Module::getAllGlobalObjects()
{
	return all_global_objects;
}