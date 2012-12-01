 /**
* @file:module.cpp
* Implementation of class Constant.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#include "constant.hpp"
#include <string>

bool Constant::isInt()
{
	if (value.which() == 1)
		return true;
	else 
		return false;
}

bool Constant::isDouble()
{
	if (value.which() == 0)
		return true;
	else 
		return false;
}

bool Constant::isString()
{
	if (value.which() == 2)
		return true;
	else 
		return false;
}