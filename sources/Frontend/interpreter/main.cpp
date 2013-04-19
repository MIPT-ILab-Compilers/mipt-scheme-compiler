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
#include <sstream>
#include <string>
#include "library.hpp"

using namespace interpreter;
using std::cout;
using std::endl;
using parser::ast::Nodep;
using parser::ast::as;
using parser::ast::Cons;
using parser::ast::Number;
using parser::ast::Nil;

void fill ( std::string& str)
{
    char c;
    std::cin >> std::noskipws >> c;
    while ( c != '\n')
    {
        str += c;
        std::cin >> std::noskipws >> c;
    }
}

int main( int argc, char **argv)
{
    if ( argc == 2){
        std::ifstream expr( argv[1], std::ifstream::in);
        ActPtr bottom( new Activation());
        Nodep plus_nodep( new est::Function( plus));
        Nodep minus_nodep( new est::Function( minus));
        Nodep def_nodep( new est::SpecialForm( def));
        (*bottom)["+"] = plus_nodep;
        (*bottom)["-"] = minus_nodep;
        parser::DumpReader dump_reader( expr);
        Nodep root = dump_reader.read();
        Nodep result = root.acceptNodep( new Interpreter( bottom));
        cout << "> ";
        result.acceptVoid( new parser::ast::DumpVisitor());
        cout << endl;
    } else if ( argc == 1)
    {
        ActPtr bottom( new Activation());
        Nodep plus_nodep( new est::Function( plus));
        Nodep minus_nodep( new est::Function( minus));
        Nodep def_nodep( new est::SpecialForm( def));
        (*bottom)["+"] = plus_nodep;
        (*bottom)["-"] = minus_nodep;
        (*bottom)["define"] = def_nodep;
        while ( 1)
        {
            std::string str;
            fill( str);
            std::istringstream expr( str);
            parser::DumpReader dump_reader( expr);
            Nodep root = dump_reader.read();
            Nodep result = root.acceptNodep( new Interpreter( bottom));
            cout << "> ";
            result.acceptVoid( new parser::ast::DumpVisitor());
            cout << endl;
        }
    } else
    {
        cout << "Usage:" << endl
            << "$./a.out expression_file.txt" << endl
            << "  - reading from a file"<< endl
            << "$./a.out" << endl
            << "  - reply mode" << endl;
    }
    return 0;
}
