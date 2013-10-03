/**
* @file:main.cpp
* Bodies of functions from library.hpp
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#include "library.hpp"

Nodep plus( Nodep terms, Interpreter& interpreter)
{
    if ( terms->type() == parser::ast::NIL)
        return Nodep( new Number( 0));
    Cons* ptr = as<Cons>( terms);
    long double result = 0;
    Nodep car = ptr->car();
    Nodep cdr = ptr->cdr();
    while ( 1)
    {
        Nodep evaluated = car.acceptNodep( &interpreter);
        Number* term = as<Number>( evaluated);
        result += term->value();
        if ( cdr->type() == parser::ast::CONS)
        {
            Cons* ptr2 = as<Cons>( cdr);
            car = ptr2->car();
            cdr = ptr2->cdr();
        } else break;
    }
    return Nodep( new Number( result));
}

Nodep minus( Nodep terms, Interpreter& interpreter)
{
    Cons* ptr = as<Cons>( terms);
    long double result = 0;
    Nodep car = ptr->car();
    Nodep cdr = ptr->cdr();
    bool first = 1;
    while ( 1)
    {
        Nodep evaluated = car.acceptNodep( &interpreter);
        Number* term = as<Number>( evaluated);
        if ( first && cdr->type() != parser::ast::NIL)
        {
            result += term->value();
            first = 0;
        } else result -= term->value();
        if ( cdr->type() == parser::ast::CONS)
        {
            Cons* ptr2 = as<Cons>( cdr);
            car = ptr2->car();
            cdr = ptr2->cdr();
        } else break;
    }
    return Nodep( new Number( result));
}

Nodep def( Nodep args, Interpreter& interpreter)
{
    Cons* cons_ptr = as<Cons>( args);
    Ident* ident = as<Ident>( cons_ptr->car());
    Nodep ptr = cons_ptr->cdr().acceptNodep( &interpreter);
    Nodep ptr2 = as<Cons>( ptr)->car();
    interpreter.getActPtr()->add( *ident, ptr2);
    return Nodep( new Nil());
}
