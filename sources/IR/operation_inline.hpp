/**
 * @file:operation_inline.hpp
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
    return numArgsInOperName( name_);
}

/** Get number of results */
inline UInt8 Operation::numRess() const
{
    return numRessInOperName( name_);
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

/** Get parent Basic Block */
inline const BasicBlock* Operation::getBasicBlock() const
{
    return this->basicBlock_;
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
inline void Operation::setResObj( UInt8 res_num, Object& obj)
{
    IR_ASSERTD( res_num < numRess());
    ress[ res_num].setObject( obj);
}

/** Set type of argument */
inline void Operation::setArgType( UInt8 arg_num, const OperandType& argt)
{
    IR_ASSERTD( arg_num < numArgs());
    IR_ASSERTD( argt <= OP_TYPES_NUM);
    args[ arg_num].setType( argt);
}

/** Set type of result */
inline void Operation::setResType( UInt8 res_num, const OperandType& rest)
{
    IR_ASSERTD( res_num < numRess());
    IR_ASSERTD( rest <= OP_TYPES_NUM);
    ress[ res_num].setType( rest);
}

/** Set parent Basic Block */
inline void Operation::setBasicBlock( BasicBlock& pBB)
{
    basicBlock_ = &pBB;
}

/** Add the operation in the output stream s */
inline void Operation::toStream( ostream& s) const
{
    s << "[" << id() << "] " << getOperNameString( name()) << " ";
    for ( UInt8 i = 0; i < numArgs(); i++ )
    {
        if ( i == 0 ) 
            s << arg( i); 
        else
            s << ", " << arg( i); 
    }
    if ( name() != OPERS_NUM)
        s << " -> ";
    for ( UInt8 i = 0; i < numRess(); i++ )
    {   
        if ( i == 0 ) 
            s << res( i); 
        else
            s << ", " << res( i); 
    }
}

inline ostream& operator<<( ostream& s, const Operation& op)
{
    op.toStream( s);
    return s;
}

}//namespace ir
