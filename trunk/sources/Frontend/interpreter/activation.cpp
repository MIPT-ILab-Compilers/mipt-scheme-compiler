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
Activation::Activation() : parent_activation_ptr()
{

}

Activation::Activation( ActPtr parent) : parent_activation_ptr( parent)
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

ActPtr Activation::getParentPtr()
{
    return parent_activation_ptr;
}

bool Activation::hasParent()
{
    return parent_activation_ptr.use_count();
}

Activation::~Activation()
{

}
}
