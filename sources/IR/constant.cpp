 /**
* @file:module.cpp
* Implementation of class Constant.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#include "constant.hpp"
#include <string>

namespace ir
{

bool Constant::isInt()
{
	if (value.which() == 2)
		return true;
	else 
		return false;
}

bool Constant::isDouble()
{
	if (value.which() == 0 or value.which() == 1)
		return true;
	else 
		return false;
}

bool Constant::isString()
{
	if (value.which() == 3)
		return true;
	else 
		return false;
}

}//namespace ir
