/**
 * @file: IR/mdes_dummy.hpp
 * Declaration of the machine description structure (dummy version)
 */
/*
 * Copyright 2013 MIPT-COMPILER team
 */

#pragma once

const UInt8 MAX_RESS_NUM = 1;
const UInt8 MAX_ARGS_NUM = 2;


enum OperName
{
    OPER_MOV,
    OPER_ADD, 
    OPER_SUB,
    OPER_MUL,
    OPERS_NUM
};
