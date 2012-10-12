/**
 * @file:operation.cpp
 * Implementation of operation
 * Templarary component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Sheme Compiler team
 */

#include "operation.hpp"

Operation::Operation( UInt16 id_oper, OperName name,
                      Operand *arguments, Operand *result)
{
    this->id_oper = id_oper;
    this->name = name;
    
    for ( UInt8 i = 0; i < ARGUMENTS_NUM; i++)
    {
        this->arguments[ i] = arguments[ i];
    }

    for ( UInt8 i = 0; i < RESULTS_NUM; i++)
    {
        this->result[ i] = result[ i];
    }
}


inline UInt16 Operation::GetId() const
{
    return this->id_oper;
}

inline OperName Operation::GetName() const
{
    return this->name;
}

void Operation::setOperand( Direction dir, UInt8 num, Operand operand)
{
    if ( dir == ARGUMENT)
    {
        this->arguments[ num] = operand;
    } else
    {
        this->result[ num] = operand;
    }
}

inline Operand Operation::getOperand( Direction dir, UInt8 num) const
{
    return ( dir == ARGUMENT)
            ? this->arguments[ num] 
            : this->result[ num];
}
