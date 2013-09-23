/**
 * @file:dataflowedge_inline.cpp
 * Implemention of DataFlowEdge
 * Temporary component
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */


inline void DataFlowEdge::setPredOper( Operation *pred_oper)
{
    this->pred_oper = pred_oper;
}

inline Operation* DataFlowEdge::getPredOper() const
{
    return this->pred_oper;
}

inline void DataFlowEdge::setSuccOper( Operation *succ_oper)
{
    this->succ_oper = succ_oper;
}

inline Operation* DataFlowEdge::getSuccOper() const
{
    return this->succ_oper;
}

inline void DataFlowEdge::setSuccOperand( Operand *succ_operand)
{
    this->succ_operand = succ_operand;
}

inline Operand* DataFlowEdge::getSuccOperand() const
{
    return this->succ_operand;
}


