
#pragma once

#include <vector>
#include <string> 
#include "object.hpp"

enum SymbolType 
{
	OBJECT,
	FUNCTION
};

class Function
{
	public:
		Function(std::string &function_name, std::vector<Object> &local_objects, std::vector<Object> &arguments);
		~Function();

		inline bool addArgument();
		inline bool addLocalVar();

		inline std::vector<Object> &getLocalObjects();
		inline std::vector<Object> &getArguments();
		inline std::string &getFunctionName();

	private:
		std::string function_name;
		std::vector<Object> local_objects;
		std::vector<Object> arguments;
};

class Symbol
{
	public:
		Symbol(std::string name, SymbolType type, Object *object = NULL, Function *function = NULL);
		~Symbol();

		inline SymbolType getType();
		inline std::string getName();
		inline Object *getObject();
		inline Function *getFunction();

		inline void setType(SymbolType);
		inline void setObject(Object *);
		inline void setFunction(Function *);

	private:
		std::string name;
		SymbolType type;
		Object *object;
		Function *function;
};

class Module 
{
	public:
		Module(std::vector<Symbol> &Symbols);
		~Module();

		inline void addSymbol();

		inline std::vector<Symbol> &getSymbolTable();

	private:
		std::vector<Symbol> SymbolTable;
};