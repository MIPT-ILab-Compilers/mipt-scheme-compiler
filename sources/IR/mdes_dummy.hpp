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
            return 1;
            break;
        case OPER_ADD:
            return 2;
            break;
        case OPER_SUB:
            return 2;
            break;
        case OPER_MUL:
            return 2;
            break;
        default:
            IR_ASSERTD( 0);
    }
}

/** Return the number of results */
inline UInt8 numbRessInOp(OperName name)
{
    switch ( name )
    {
        case OPER_MOV:
            return 1;
            break;
        case OPER_ADD:
            return 1;
            break;
        case OPER_SUB:
            return 1;
            break;
        case OPER_MUL:
            return 1;
            break;
        default:
            IR_ASSERTD( 0);
    }
}

inline string getOperNameString(OperName name)
{
    switch ( name )
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
            IR_ASSERTD( 0);
    }
}
