/**
 * @file: predecls.hpp
 * Predeclarations for interface of IR library
 */
/**
 * Copyright (C) 2013  MIPT Scheme Compiler team
 */

#pragma once

#include "../Utils/utils_iface.h"
#include "utils.hpp"

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

class Operation;

}
