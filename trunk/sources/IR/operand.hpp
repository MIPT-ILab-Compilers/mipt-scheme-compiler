/**
 * @file:operand.hpp
 * Interface of operand
 * Temporary file. Class Operand has to be updated
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#ifndef OPERAND_HPP
#define OPERAND_HPP

#pragma once

#include "object.hpp"
#include "dataflowedge.hpp"
#include "../Utils/types.h"

enum TypeOfOperand
{
    IMMEDIATE,
    OBJECT,
    TYPE_OPERAND_NUM
};


class Operand
{

/*public:
    Operand( Double value, DataFlowEdge *df, bool is_arg);
    Operand( Object *obj, DataFlowEdge *df, bool is_arg);
    


private:
    Double immediate;
    Object *obj;
    DataFlowEdge *df;
    bool is_argument;
*/
}; 


#endif /* OPERAND_HPP */
