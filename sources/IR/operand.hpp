/**
 * @file:operand.hpp
 * Interface of operand
 * Core component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#pragma once

#include "operation.hpp"
#include "object.hpp"
#include "../Utils/types.h"
#include <assert.h>
#include <stddef.h>

enum TypeOfOperand
{
    OPERAND_IMMEDIATE,
    OPERAND_OBJECT,
    OPERAND_TARGET,
    TYPE_OPERAND_NUM
};


class Operand
{

public:
    Operand();
    Operand( Int64 value, DataFlowEdge *df);
    Operand( Object *obj, DataFlowEdge *df);
    Operand( Operation *target, DataFlowEdge *df);
    
    inline bool isImmediate() const;
    inline bool isObject() const;
    inline bool isTarget() const;
    
    inline TypeOfOperand getType() const;
    
    inline Int64 getImmediate() const;
    inline Object* getObject() const;
    inline Operation* getOperation() const;
    
    inline void setImmediate( Int64 immediate);
    inline void setObject( Object *obj);
    inline void setTarget( Operation *target);

    inline DataFlowEdge* getDF() const;
    inline void setDF( DataFlowEdge *df);

private:
    union OperandData
    {
    Int64 immediate;
    Object *obj;
    Operation *target;
    } data;

    TypeOfOperand current;
    
    DataFlowEdge *df;
};
