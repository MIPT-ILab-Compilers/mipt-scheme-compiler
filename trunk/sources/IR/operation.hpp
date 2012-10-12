/**
 * @file:operation.hpp
 * Interface of operation
 * Templarary component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#ifndef OPERATION_HPP
#define OPERATION_HPP

#pragma once

#include "../Utils/types.h"
#include "operand.hpp"


#define RESULTS_NUM 1
#define ARGUMENTS_NUM 2


enum OperName
{
    ADD, SUB,
    DIV, MUL,
    OPER_NUM
};

enum Direction
{
    ARGUMENT,
    RESULT,
    DIR_NUM
};

class Operation
{

public:
    Operation( UInt16 id_oper, OperName name, 
               Operand  *arguments, Operand *result);
    //~Operation();
    
    inline UInt16 GetId() const;

    inline OperName GetName() const;

    void setOperand( Direction dir, UInt8 num, Operand operand);
    
    inline Operand getOperand( Direction dir, UInt8 num) const;


private:
    OperName name;
    Operand arguments[ ARGUMENTS_NUM];
    Operand result[ RESULTS_NUM];
    UInt16 id_oper;

};




#endif /* OPERATION_HPP */
