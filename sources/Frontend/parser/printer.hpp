
/**
* @file:ast.cpp
* Specification of class Printer.
* Header file for class Printer.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#pragma once

#include "ast.hpp"
#include <sstream>
        
class Printer 
{   
    public:
        Printer() {}
       	void dump(parser::ast::Nodep root);
};
