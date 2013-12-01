/**
 * @file: predecls.hpp
 * Predeclarations for interface of IR library
 */
/**
 * Copyright (C) 2013  MIPT Scheme Compiler team
 */

#pragma once

#include "../Utils/utils_iface.h"

/**
 * Debug assert for IR library
 **/
#if !defined(IR_ASSERTD)
#    define IR_ASSERTD(cond) ASSERT_XD(cond, "IR", "")
#endif

/**
 * Debug assert for IR library
 **/
#if !defined(IR_ASSERTXD)
#    define IR_ASSERTXD(cond, what) ASSERT_XD(cond, "IR", what)
#endif

namespace ir
{

/** Operand type */
enum OperandType
{
    OP_TYPE_OBJ,
    OP_TYPE_IMM,
    OP_TYPE_TRG,
    OP_TYPES_NUM
};

/** Oper ID type */
typedef UInt32 OperUid;

/** Oper ID type */
typedef UInt32 ObjId;

/** Basic block ID type */
typedef UInt32 BasicBlockUid;

class Operation;

}
