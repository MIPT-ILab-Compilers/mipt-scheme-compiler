/**
 * @file:operation.hpp
 * Interface of operation
 * Temporary component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#pragma once

#include "Utils/types.h"
#include "operand.hpp"

namespace ir
{

const UInt8 RESULTS_NUM = 1;
const UInt8 ARGUMENTS_NUM = 2;

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
               const Operand *arguments, 
               const Operand *result);
    virtual ~Operation();
    
    inline UInt64 GetId() const;

    inline OperName GetName() const;

    inline const Operand& getResult() const; // returns result[ 0]
    inline const Operand& getResult( UInt8 num) const; // returns result[ num]
    inline void setResult( const Operand& operand); // result[ 0] = operand 
    inline void setResult( const Operand& operand, UInt8 num); // result[ num] = operand
    
    inline const Operand& getArgument( UInt8 num) const;
    inline void setArgument(const Operand& operand, UInt8 num);


private:
    OperName name;
    Operand arguments[ ARGUMENTS_NUM];
    Operand result[ RESULTS_NUM];
    UInt64 id_oper;
};

}//namespace ir

#include "operation_inline.hpp"
