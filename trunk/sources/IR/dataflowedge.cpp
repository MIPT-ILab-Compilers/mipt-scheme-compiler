/**
 * @file:dataflowedge.cpp
 * Implemention of DataFlowEdge
 * Temporary component
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

#include "dataflowedge.hpp"


DataFlowEdge::DataFlowEdge( Operation *pred_oper,
                            Operation *succ_oper,
                            Operand *succ_operand)
{
    this->pred_oper = pred_oper;
    this->succ_oper = succ_oper;
    this->succ_operand = succ_operand;
}
