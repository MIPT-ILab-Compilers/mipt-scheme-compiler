/**
* @file:ast.cpp
* Implementation of class Printer.
* Source code for Printer.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#include "printer.hpp"
#include <iostream>

using namespace parser;
using namespace ast;

void print_non_empty_list(Cons *, bool openbr, std::ostringstream &oss);
void rec_dump(Nodep root, std::ostringstream &oss);

void Printer::dump(Nodep root) 
{   
    std::ostringstream oss;
    rec_dump(root, oss);
    std::cout << oss.str() << std::endl;
}

void print_non_empty_list(Cons *L, bool openbr, std::ostringstream &oss)
{
    if (openbr)
        oss << '(';
    rec_dump(L->car(), oss);

    if (L->cdr()->type() == NIL)
        oss << ')';
    else {
        oss << ' ';
        print_non_empty_list(as<Cons>(L->cdr()), false, oss);
    }
}

void rec_dump(Nodep root, std::ostringstream &oss)
{
    Number *A;
    String *B;
    Char *C;
    Cons *D;

    switch (root->type()) {
        case NIL:
            oss << "()";
            return;
        case NUMBER:
            A = as<Number>(root);
            oss << A->value();
            return;
        case STRING:
            B = as<String>(root);
            oss << B->value();
            return;
        case CHAR:
            C = as<Char>(root);
            oss << C->value() << ' ';
            return;
        case CONS:
            print_non_empty_list(as<Cons>(root), true, oss);
            return;
    }
}
