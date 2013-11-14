/**
 * @file:operand_inline.cpp
 * Implementation of operand
 * Core component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

#include "ir_iface.hpp"

namespace ir
{

Operand::Operand() : type_( OP_TYPES_NUM)
{
}

Operand::~Operand()
{
}

}//namespace ir

