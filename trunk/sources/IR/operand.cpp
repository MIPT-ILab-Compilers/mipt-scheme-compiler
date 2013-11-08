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

ostream& operator << (ostream& s, const Operand& opnd)
{
    switch( opnd.type() )
    {
        case OP_TYPE_IMM:
            s << opnd.constValue();
            break;
        case OP_TYPE_OBJ:
            s << opnd.object();
            break;
        case OP_TYPE_TRG:
            s << opnd.target();
            break;
        default:
            IR_ASSERTD( 0);
    }
    return s;
}

}//namespace ir

