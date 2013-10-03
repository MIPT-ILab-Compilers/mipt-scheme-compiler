/**
* @file:library.cpp
* Functions and special forms of Scheme.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#pragma once

#include "est.hpp"
#include "activation.hpp"
#include "../parser/ast.hpp"
#include "interpreter.hpp"

using namespace interpreter;
using parser::ast::Nodep;
using parser::ast::as;
using parser::ast::Cons;
using parser::ast::Number;
using parser::ast::Nil;

Nodep plus( Nodep terms, Interpreter& interpreter);
Nodep minus( Nodep terms, Interpreter& interpreter);
Nodep def( Nodep args, Interpreter& interpreter);
