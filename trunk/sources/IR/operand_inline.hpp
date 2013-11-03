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

inline const OperandType& Operand::type() const
{
    return this->type_;
}

inline Int64 Operand::constValue() const
{
    IR_ASSERTD( type() == OP_TYPE_IMM);
    return this->data.imm;
}

inline Object* Operand::object() const
{
    IR_ASSERTD( type() == OP_TYPE_OBJ);
    return this->data.obj;
}

inline Operation* Operand::target() const
{
    IR_ASSERTD( type() == OP_TYPE_TRG);
    return this->data.target;
}

inline void Operand::setConstValue( Int64 immediate)
{
    IR_ASSERTD( type() == OP_TYPE_IMM);
    this->data.imm = immediate;
}

inline void Operand::setObject( Object& obj)
{
    IR_ASSERTD( type() == OP_TYPE_OBJ);
    this->data.obj = &obj;
}

inline void Operand::setTarget( Operation& target)
{
    IR_ASSERTD( type() == OP_TYPE_TRG);
    this->data.target = &target;
}

}//namespace ir
