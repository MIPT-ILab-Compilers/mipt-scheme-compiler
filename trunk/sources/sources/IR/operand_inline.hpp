/**
 * @file:operand_inline.cpp
 * Implementation of operand
 * Core component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */
#include "utils.hpp"

namespace ir
{

inline bool Operand::isImmediate() const
{
    return ( this->current == OPERAND_IMMEDIATE);
}

inline bool Operand::isObject() const
{
    return ( this->current == OPERAND_OBJECT);
}

inline bool Operand::isTarget() const
{
    return (this->current == OPERAND_TARGET);
}

inline TypeOfOperand Operand::getType() const
{
    return this->current;
}

inline Int64 Operand::getImmediate() const
{
    IR_ASSERTD( this->current == OPERAND_IMMEDIATE);
    return this->data.immediate;
}

inline Object* Operand::getObject() const
{
    IR_ASSERTD( this->current == OPERAND_OBJECT);
    return this->data.obj;
}

inline Operation* Operand::getOperation() const
{
    IR_ASSERTD( this->current == OPERAND_TARGET);
    return this->data.target;
}

inline void Operand::setImmediate( Int64 immediate)
{
    this->data.immediate = immediate;
    this->current = OPERAND_IMMEDIATE;
}

inline void Operand::setObject( Object& obj)
{
    this->data.obj = &obj;
    this->current = OPERAND_OBJECT;
}

inline void Operand::setTarget( Operation& target)
{
    this->data.target = &target;
    this->current = OPERAND_TARGET;
}

inline DataFlowEdge* Operand::getDF() const
{
    return this->df;
}

inline void Operand::setDF( DataFlowEdge* df)
{
    this->df = df;
}

}//namespace ir
