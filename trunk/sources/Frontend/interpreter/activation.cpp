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

    Nodep Activation::get( IdentIdType _id)
    {
        return ( *this)[_id];
    }

    void Activation::add( Ident& ident, Nodep& ptr)
    {
        ( *this)[ident.getId()] = ptr;
    }

    Activation* Activation::getParentPtr()
    {
        return parent_activation_ptr.get();
    }

    Activation::~Activation()
    {

    }
}
