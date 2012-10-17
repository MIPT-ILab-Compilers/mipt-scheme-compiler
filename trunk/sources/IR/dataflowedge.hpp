/**
 * @file:dataflowedge.hpp
 * Interface of DataFlowEdge
 * Temporary component
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

#pragma once

#include "../Utils/types.h"
#include "operation.hpp"


class DataFlowEdge
{

public:
    DataFlowEdge( Operation *pred_oper, Operation *succ_oper, Operand *succ_operand);
    
    inline void setPredOper( Operation *pred_oper);
    inline Operation* getPredOper() const;

    inline void setSuccOper( Operation *succ_oper);
    inline Operation* getSuccOper() const;

    inline void setSuccOperand( Operand *succ_operand);
    inline Operand* getSuccOperand() const; 

private:
    
    Operation *pred_oper; // operation that determines the result
    
    Operation *succ_oper; // operation that uses the result
    
    Operand *succ_operand; // operand that uses the result, this operand
                           // is contained in succ_oper 
                          
};
