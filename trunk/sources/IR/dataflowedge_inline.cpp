/**
 * @file:dataflowedge_inline.cpp
 * Implemention of DataFlowEdge
 * Templarary component
 */
/**
 * Copyright (C) 2012 MIPT Sheme Compiler team
 */

#include "dataflowedge.hpp"

DataFlowEdge::DataFlowEdge( UInt16 pred_oper,
                            UInt16 succ_oper,
                            UInt16 succ_operand)
{
    this->pred_oper = pred_oper;
    this->succ_oper = succ_oper;
    this->succ_operand = succ_operand;
}

inline void DataFlowEdge::setPredOper( UInt16 pred_oper)
{
    this->pred_oper = pred_oper;
}

inline UInt16 DataFlowEdge::getPredOper() const
{
    return this->pred_oper;
}

inline void DataFlowEdge::setSuccOper( UInt16 succ_oper)
{
    this->succ_oper = succ_oper;
}

inline UInt16 DataFlowEdge::getSuccOper() const
{
    return this->succ_oper;
}

inline void DataFlowEdge::setSuccOperand( UInt16 succ_operand)
{
    this->succ_operand = succ_operand;
}

inline UInt16 DataFlowEdge::getSuccOperand() const
{
    return this->succ_operand;
}


