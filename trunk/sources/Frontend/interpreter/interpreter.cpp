/*
* @file:interpreter.cpp
* Implementation of interpretr`s methods.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#include "interpreter.hpp"

namespace interpreter
{
using parser::ast::as;
using parser::ast::Ident;
using parser::ast::Cons;

Nodep findIdent( ActPtr activation_p, Nodep ident)
{
    /*
     * First it looks in current activation,
     * then checks in it`s parent activation
     * (provided that it exists). If ident
     * is not in current activation and
     * the activation doesn`t have a parent,
     * the function throws exception.
     */
    if ( activation_p->count( as<Ident>( ident)->getId()))
    {
        return (*activation_p)[as<Ident>( ident)->getId()];
    } else if ( activation_p->hasParent())
    {
        return findIdent( activation_p->getParentPtr(), ident);
    }

    throw InterpreterException( "Ident was not defined!");
}

Interpreter::Interpreter( ActPtr ptr) : _activation( ptr)
{

}

Nodep Interpreter::visitNil( Nodep _nil)
{
    return _nil;
}

Nodep Interpreter::visitCons( Nodep _cons)
{
    Cons * cons_ptr = as<Cons>( _cons);
    if ( cons_ptr->car()->type() == parser::ast::IDENT)
    {
        Nodep var = cons_ptr->car().acceptNodep( this);
        if ( var->type() == est::FUNCTION)
        {
            est::Function* f = as<est::Function>( var);
            this->pushActivation();
            Nodep result = f->call( cons_ptr->cdr(), *this);
            this->popActivation();
            return result;
        } else if ( var->type() == est::SPECIAL_FORM)
        {
            est::SpecialForm* sf = as<est::SpecialForm>( var);
            return sf->apply( cons_ptr->cdr(), *this);
        } else
        {
            Nodep cdr = cons_ptr->car().acceptNodep( this);
            return Nodep( new Cons( var, cdr));
        }
    }else
    {
        Nodep car = cons_ptr->car().acceptNodep( this);
        Nodep cdr = cons_ptr->cdr().acceptNodep( this);
        return Nodep( new Cons(car, cdr));
    }
}

Nodep Interpreter::visitNumber( Nodep _number)
{
    return _number;
}

Nodep Interpreter::visitString( Nodep _string)
{
    return _string;
}
 
Nodep Interpreter::visitIdent( Nodep _ident)
{
    return findIdent( _activation, _ident);
}

Nodep Interpreter::visitChar( Nodep _char)
{
    throw InterpreterException( "plug");
}
    
Nodep Interpreter::visitVector( Nodep _vector)
{
    throw InterpreterException( "plug");
}

ActPtr Interpreter::getActPtr()
{
    return _activation;
}

void Interpreter::pushActivation()
{
    _activation = ActPtr( new Activation( _activation));
}

void Interpreter::popActivation()
{
    if ( _activation->hasParent())
    {
        _activation = _activation->getParentPtr();
    } else throw InterpreterException( "no parent activation");
}
}//namespace interpreter
