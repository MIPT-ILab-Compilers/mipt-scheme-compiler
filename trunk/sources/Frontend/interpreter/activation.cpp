/**
 * @file:activation.cpp
 * Implementation of Activation class methods.
 */
/**
 * Copyright 2012 MIPT-COMPILER team
 */

#include "activation.hpp"

namespace interpreter
{
    Activation::Activation( Activation* parent) : parent_activation_ptr( parent)
    {

    }

    Nodep Activation::get( SymbolIdType symbol_id)
    {
        return ( *this)[symbol_id];
    }

    void Activation::add( Symbol& symbol, Nodep& ptr)
    {
        ( *this)[symbol.getId()] = ptr;
    }

    Activation* Activation::getParentPtr()
    {
        return parent_activation_ptr.get();
    }

    Activation::~Activation()
    {

    }
}
