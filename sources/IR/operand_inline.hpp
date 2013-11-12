/**
 * @file:operand_inline.cpp
 * Implementation of operand
 * Core component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

namespace ir
{

/** Return Operand type */
inline const OperandType& Operand::type() const
{
    return this->type_;
}

/** Return constant value */
inline Int64 Operand::constValue() const
{
    IR_ASSERTD( type() == OP_TYPE_IMM);
    return this->data.imm;
}

/** Return object */
inline Object* Operand::object() const
{
    IR_ASSERTD( type() == OP_TYPE_OBJ);
    return this->data.obj;
}

/** Return target operation */
inline Operation* Operand::target() const
{
    IR_ASSERTD( type() == OP_TYPE_TRG);
    return this->data.target;
}

/** Set constant value */
inline void Operand::setConstValue( Int64 immediate)
{
    this->data.imm = immediate;
}

/** Set object */
inline void Operand::setObject( Object& obj)
{
    
    this->data.obj = &obj;
}

/** Set target operation */
inline void Operand::setTarget( Operation& target)
{
    this->data.target = &target;
}

/** Set operand type */
inline void Operand::setType( const OperandType& type)
{
    IR_ASSERTD( type < OP_TYPES_NUM);
    type_ = type;
}

inline ostream& operator<<( ostream& s, const Operand& opnd)
{
    opnd.opndToStream( s);
    return s;
}

}//namespace ir
