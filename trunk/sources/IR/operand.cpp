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

void Operand::opndToStream( ostream &s) const
{
    switch( type() )
    {
        case OP_TYPE_IMM:
            s << constValue();
            break;
        case OP_TYPE_OBJ:
            s << object()->objPrintName();
            break;
        case OP_TYPE_TRG:
            s << '[' << target()->id() << ']';
            break;
        default:
            IR_ASSERTD( 0);
    }
}

}//namespace ir

