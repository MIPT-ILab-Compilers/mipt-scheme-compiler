/**
 * @file:operation_inline.cpp
 * Implementation of operation
 * Temporary component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

#include "Utils/types.h"

namespace ir
{

/** se */    
inline const OperUid& Operation::id() const
{
    return this->id_;
}

/** se */
inline const OperName& Operation::name() const
{
    return this->name_;
}

/** Get number of arguments */
inline UInt8 Operation::numArgs() const
{
    IR_ASSERTXD( false, "Not implemented!");
    return 0;
}

/** Get number of results */
inline UInt8 Operation::numRess() const
{
    IR_ASSERTXD( false, "Not implemented!");
    return 0;
}

/** se */
inline const Operand& Operation::arg( UInt8 arg_num) const
{
    IR_ASSERTD( arg_num < MAX_ARGS_NUM);
    return this->args[ arg_num];
}

/** se */
inline const Operand& Operation::res( UInt8 res_num) const
{
    IR_ASSERTD( res_num < MAX_RESS_NUM);
    return this->ress[ res_num];
}


/** Set name of operation */
inline void setName( OperName name)
{
    IR_ASSERTXD( false, "Not implemented!");
}

}//namespace ir
