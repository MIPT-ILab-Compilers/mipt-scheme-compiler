/**
 * @file:operation_inline.cpp
 * Implementation of operation
 * Temporary component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

#include "Utils/types.h"

class Operand;

inline UInt64 Operation::GetId() const
{
    return this->id_oper;
}

inline OperName Operation::GetName() const
{
    return this->name;
}

inline const Operand& Operation::getResult() const
{
    return this->result[ 0];
}

inline const Operand& Operation::getResult( UInt8 num) const
{
    IR_ASSERTD( num < RESULTS_NUM && num >= 0);
    return this->result[ num];
}

inline void Operation::setResult( const Operand& operand)
{
    result[ 0] = operand;
}

inline void Operation::setResult( const Operand& operand, UInt8 num)
{   
    IR_ASSERTD( num >= 0 && num < RESULTS_NUM);
    result[ 0] = operand;
}

inline const Operand& Operation::getArgument( UInt8 num) const
{
    IR_ASSERTD( num >= 0 && num < ARGUMENTS_NUM);
    return this->arguments[ num];
}

inline void Operation::setArgument (const Operand& operand, UInt8 num)
{
    IR_ASSERTD( num >= 0 && num < ARGUMENTS_NUM);
    this->arguments[ num] = operand;
}
