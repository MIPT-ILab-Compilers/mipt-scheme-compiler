/**
 * @file:operation_inline.cpp
 * Implementation of operation
 * Temporary component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

namespace ir
{

/** se */    
inline OperUid Operation::id() const
{
    return this->id_;
}

/** se */
inline OperName Operation::name() const
{
    return this->name_;
}

/** Get number of arguments */
inline UInt8 Operation::numArgs() const
{
    return numbArgsInOp( name_);
}

/** Get number of results */
inline UInt8 Operation::numRess() const
{
    return numbRessInOp( name_);
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
inline void Operation::setName( OperName name)
{
    IR_ASSERTD( name < OPERS_NUM);
    name_ = name;
}

/** Set argument object */
inline void Operation::setArgObj( UInt8 obj_numb, const Operand& obj)
{
    IR_ASSERTD( obj.type() == OP_TYPE_OBJ);
    IR_ASSERTD( obj_numb < numArgs());
    args[ obj_numb] = obj;
}

/** Set argument immediate */
inline void Operation::setArgImm( UInt8 imm_numb, const Operand& imm)
{
    IR_ASSERTD( imm.type() == OP_TYPE_IMM);
    IR_ASSERTD( imm_numb < numArgs());
    args[ imm_numb] = imm;
}

/** Set argument target */
inline void Operation::setArgTrg( UInt8 trg_numb, const Operand& trg)
{
    IR_ASSERTD( trg.type() == OP_TYPE_TRG);
    IR_ASSERTD( trg_numb < numArgs());
    args[ trg_numb] = trg;
}

}//namespace ir
