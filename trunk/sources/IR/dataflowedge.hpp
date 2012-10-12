/**
 * @file:dataflowedge.hpp
 * Interface of DataFlowEdge
 * Templarary component
 */
/**
 * Copyright (C) 2012 MIPT Sheme Compiler team
 */

#ifndef DATAFLOWEDGE_HPP
#define DATAFLOWEDGE_HPP

#pragma once

#include "../Utils/types.h"
#include "operand.hpp"
#include "operation.hpp"

class DataFlowEdge
{

public:
    DataFlowEdge( UInt16 pred_oper, UInt16 succ_oper, UInt16 succ_operand);
    
    inline void setPredOper( UInt16 pred_oper);
    inline UInt16 getPredOper() const;

    inline void setSuccOper( UInt16 succ_oper);
    inline UInt16 getSuccOper() const;

    inline void setSuccOperand( UInt16 succ_operand);
    inline UInt16 getSuccOperand() const; 

private:
    
    UInt16 pred_oper; // id operation that determines the result
    
    UInt16 succ_oper; // id operation that uses the result
    
    UInt16 succ_operand; // id operand that uses the result, this operand
                         // is contained in succ_oper 
                          
};

#endif /* DATAFLOWEDGE_HPP */
