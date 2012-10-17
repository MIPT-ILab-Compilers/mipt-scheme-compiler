/**
 * @file:operation.cpp
 * Implementation of operation
 * Temporary component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

#include "operation.hpp"

Operation::Operation( UInt64 id_oper, OperName name,
                      Operand *arguments, Operand *result)
{
    this->id_oper = id_oper;
    this->name = name;
    this->arguments = new Operand[ ARGUMENTS_NUM];
    this->result = new Operand[ RESULTS_NUM];

    
    for ( UInt8 i = 0; i < ARGUMENTS_NUM; i++)
    {
        this->arguments[ i] = arguments[ i];
    }

    for ( UInt8 i = 0; i < RESULTS_NUM; i++)
    {
        this->result[ i] = result[ i];
    }
}

Operation::~Operation()
{
    delete this->result;
    delete this->arguments;
}

inline UInt64 Operation::GetId() const
{
    return this->id_oper;
}

inline OperName Operation::GetName() const
{
    return this->name;
}

inline Operand Operation::getResult() const
{
    return this->result[ 0];
}

inline Operand Operation::getResult( UInt8 num) const
{
    return this->result[ num];
}

inline void Operation::setResult( Operand operand)
{
    result[ 0] = operand;
}

inline void Operation::setResult( Operand operand, UInt8 num)
{
    result[ 0] = operand;
}

inline Operand Operation::getArgument( UInt8 num) const
{
    return this->arguments[ num];
}

inline void Operation::setArgument (Operand operand, UInt8 num)
{
    this->arguments[ num] = operand;
}
