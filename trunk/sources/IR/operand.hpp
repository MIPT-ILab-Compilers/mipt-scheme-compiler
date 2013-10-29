/**
 * @file:operand.hpp
 * Interface of operand
 * Core component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#pragma once
#include "Utils/types.h"

namespace ir
{

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
    Operand(); // default constructor
    Operand( const Operand&); // copy constructor

#if 0 /* disabled DataFlowEdge*/
    Operand( Int64 value, DataFlowEdge* df);
    Operand( Object& obj, DataFlowEdge* df);
    Operand( Operation& target, DataFlowEdge* df);
#endif
    
    inline bool isImmediate() const;
    inline bool isObject() const;
    inline bool isTarget() const;
    
    inline TypeOfOperand getType() const;
    
    inline Int64 getImmediate() const;
    inline Object* getObject() const;
    inline Operation* getOperation() const;
    
    inline void setImmediate( Int64 immediate);
    inline void setObject( Object& obj);
    inline void setTarget( Operation& target);

#if 0 /* disabled DataFlowEdge*/
    inline DataFlowEdge* getDF() const;
    inline void setDF( DataFlowEdge* df);
#endif
private:
    union OperandData
    {
    Int64 immediate;
    Object *obj;
    Operation *target;
    } data;

    TypeOfOperand current;
    
#if 0 /* disabled DataFlowEdge*/
    DataFlowEdge* df;
#endif
};

}//namespace ir

