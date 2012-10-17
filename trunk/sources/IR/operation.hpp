/**
 * @file:operation.hpp
 * Interface of operation
 * Temporary component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#pragma once

#include "../Utils/types.h"
#include "ir_iface.hpp"
#include "operand.hpp"
#include "dataflowedge.hpp"

#define RESULTS_NUM 1
#define ARGUMENTS_NUM 2


enum OperName
{
    OPER_ADD, OPER_SUB,
    OPER_DIV, OPER_MUL,
    OPER_NUM
};


class Operation
{

public:
    Operation( UInt64 id_oper, OperName name, 
               Operand  *arguments, Operand *result);
    ~Operation();
    
    inline UInt64 GetId() const;

    inline OperName GetName() const;

    inline Operand getResult() const; // returns result[ 0]
    inline Operand getResult( UInt8 num) const; // returns result[ num]
    inline void setResult( Operand operand); // result[ 0] = operand 
    inline void setResult( Operand operand, UInt8 num); // result[ num] = operand
    
    inline Operand getArgument( UInt8 num) const;
    inline void setArgument( Operand operand, UInt8 num);


private:
    OperName name;
    Operand *arguments;
    Operand *result;
    UInt64 id_oper;
};
