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

Operand::Operand()
{
    this->current = OPERAND_IMMEDIATE;
    this->data.immediate = 0;
}

Operand::Operand( const Operand& operand)
{
    this->current = operand.current;
//    this->df = operand.df;
    switch ( this->current)
    {
        case OPERAND_IMMEDIATE:
            this->data.immediate = operand.data.immediate;
            break;
        case OPERAND_OBJECT:
            this->data.obj = operand.data.obj;
            break;
        case OPERAND_TARGET:
            this->data.target = operand.data.target;
    }
}

#if 0 /* dasabled DataFlowEdge */
Operand::Operand( Int64 value, DataFlowEdge* df)
{
    this->data.immediate = value;
    this->current = OPERAND_IMMEDIATE;
    this->df = df;
}

Operand::Operand( Object& obj, DataFlowEdge* df)
{
    this->data.obj = &obj;
    this->current = OPERAND_OBJECT;
    this->df = df;
}

Operand::Operand( Operation& target, DataFlowEdge* df)
{
    this->data.target = &target;
    this->current = OPERAND_TARGET;
    this->df = df;
}
#endif 

}//namespace ir

