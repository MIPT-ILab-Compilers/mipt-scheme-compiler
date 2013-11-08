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

inline string Operation::getNameOpInString() const
{
    return getOperNameString( name_);
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
inline void Operation::setArgObj( UInt8 arg_num, Object& obj)
{
    IR_ASSERTD( arg_num < numArgs());
    args[ arg_num].setObject( obj);
}

/** Set argument immediate */
inline void Operation::setArgImm( UInt8 arg_num, Int64 imm)
{
    IR_ASSERTD( arg_num < numArgs());
    args[ arg_num].setConstValue( imm);
}

/** Set argument target */
inline void Operation::setArgTrg( UInt8 arg_num, Operation& trg)
{
    IR_ASSERTD( arg_num < numArgs());
    args[ arg_num].setTarget( trg);
}

/** Set result object */
inline void Operation::setResObj( UInt8 arg_num, Object& obj)
{
    IR_ASSERTD( arg_num < numRess());
    ress[ arg_num].setObject( obj);
}

/** Set result target */
inline void Operation::setResTrg( UInt8 arg_num, Operation& trg)
{
   IR_ASSERTD( arg_num < numRess());
   ress[ arg_num].setTarget( trg);
}

}//namespace ir
