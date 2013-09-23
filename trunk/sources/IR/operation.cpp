/**
 * @file:operation_inline.cpp
 * Implementation of operation
 * Temporary component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

#include "operation.hpp"

namespace ir
{

Operation::Operation( UInt64 id_oper, OperName name,
                      const Operand *arguments, 
                      const Operand *result)
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

Operation::~Operation()
{
}

}//namespace ir
