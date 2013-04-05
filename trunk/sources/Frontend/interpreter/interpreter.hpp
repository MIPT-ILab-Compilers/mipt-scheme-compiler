/**
* @file:interpreter.hpp
* Header file for interpreter.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#pragma once

#include "../parser/ast.hpp"
#include "est.hpp"
#include "activation.hpp"
#include "interpreter_exception.hpp"
#include <iostream>

namespace interpreter
{
    class Interpreter : public parser::ast::Visitor<Nodep>
    {
    public:
        Interpreter( ActPtr ptr);

        Nodep visitNil( Nodep _nil);
        Nodep visitCons( Nodep _cons);
        Nodep visitNumber( Nodep _number);
        Nodep visitString( Nodep _string);
        Nodep visitIdent( Nodep _ident);
        Nodep visitChar( Nodep _char);
        Nodep visitVector( Nodep _vector);
   private:
        ActPtr _activation;
    };
}
