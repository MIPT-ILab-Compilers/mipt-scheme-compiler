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

/** The number of arguments (depends on operation) */
const UInt8 ARGS_NUM_MOV = 1;
const UInt8 ARGS_NUM_ADD = 2;
const UInt8 ARGS_NUM_SUB = 2;
const UInt8 ARGS_NUM_MUL = 2;

/** The number of results (depends on operation) */
const UInt8 RESS_NUM_MOV = 1;
const UInt8 RESS_NUM_ADD = 1;
const UInt8 RESS_NUM_SUB = 1;
const UInt8 RESS_NUM_MUL = 1;

/** Object type */
enum ObjName
{
    OBJ_NAME_REG,
    OBJ_NAMES_NUM
};

/** Operation name */
enum OperName
{
    OPER_MOV,
    OPER_ADD, 
    OPER_SUB,
    OPER_MUL,
    OPERS_NUM
};

/** Return the number of arguments */
inline UInt8 numbArgsInOp(OperName name)
{
    switch ( name )
    {
        case OPER_MOV:
            return ARGS_NUM_MOV;
            break;
        case OPER_ADD:
            return ARGS_NUM_ADD;
            break;
        case OPER_SUB:
            return ARGS_NUM_SUB;
            break;
        case OPER_MUL:
            return ARGS_NUM_MUL;
            break;
        default:
            exit(1);
    }
}

/** Return the number of results */
inline UInt8 numbRessInOp(OperName name)
{
    switch( name )
    {
        case OPER_MOV:
            return RESS_NUM_MOV;
            break;
        case OPER_ADD:
            return RESS_NUM_ADD;
            break;
        case OPER_SUB:
            return RESS_NUM_SUB;
            break;
        case OPER_MUL:
            return RESS_NUM_MUL;
            break;
        default:
            exit(2);
    }
}

inline string getOperNameString(OperName name)
{
    switch( name )
    {
        case OPER_MOV:
            return "MOV";
            break;
        case OPER_ADD:
            return "ADD";
            break;
        case OPER_SUB:
            return "SUB";
            break;
        case OPER_MUL:
            return "MUL";
            break;
        default:
            exit(3);
    }
}
