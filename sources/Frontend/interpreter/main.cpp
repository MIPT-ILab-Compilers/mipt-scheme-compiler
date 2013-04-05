/**
* @file:main.cpp
* The main precedure for interpreter component. It utilizes alle interpreter,
* parser, lexer facilities, builds up interpreter object, tunes it and launches.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#include <iostream>
#include "est.hpp"
#include "activation.hpp"
#include "../parser/ast.hpp"
#include "../parser/dump_reader.hpp"
#include "interpreter.hpp"
#include <fstream>

using namespace interpreter;
using std::cout;
using std::endl;
using parser::ast::Nodep;
using parser::ast::as;
using parser::ast::Cons;
using parser::ast::Number;

Nodep add( Nodep terms)
{
    Cons* ptr = as<Cons>( terms);
    Number* term1 = as<Number>( ptr->car());
    Cons* ptr2 = as<Cons>( ptr->cdr());
    Number* term2 = as<Number>( ptr2->car());
    return Nodep( new Number( term1->value() + term2->value()));
}

Nodep subtr( Nodep terms)
{
    Cons* ptr = as<Cons>( terms);
    Number* term1 = as<Number>( ptr->car());
    Cons* ptr2 = as<Cons>( ptr->cdr());
    Number* term2 = as<Number>( ptr2->car());
    return Nodep( new Number( term1->value() - term2->value()));
}

int main( int argc, char **argv)
{
    if ( argc != 2)
    {
        cout << "Usage: $./a.out expression_file.txt"
            << endl;
        return 0;
    }
    std::ifstream expr( argv[1], std::ifstream::in);
    ActPtr bottom( new Activation());
    Nodep add_nodep( new est::Function( add));
    Nodep subtr_nodep( new est::Function( subtr));
    (*bottom)["+"] = add_nodep;
    (*bottom)["-"] = subtr_nodep;
    parser::DumpReader dump_reader( expr);
    Nodep root = dump_reader.read();
    Nodep result = root.acceptNodep( new Interpreter( bottom));
    cout << "> ";
    result.acceptVoid( new parser::ast::DumpVisitor());
    cout << endl;
    return 0;
}
