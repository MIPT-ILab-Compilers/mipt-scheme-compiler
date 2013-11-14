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
    IR_ASSERTD( type() == OP_TYPE_IMM);
    this->data.imm = immediate;
}

/** Set object */
inline void Operand::setObject( Object& obj)
{
    IR_ASSERTD( type() == OP_TYPE_OBJ);
    this->data.obj = &obj;
}

/** Set target operation */
inline void Operand::setTarget( Operation& target)
{
    IR_ASSERTD( type() == OP_TYPE_TRG);
    this->data.target = &target;
}

/** Set operand type */
inline void Operand::setType( const OperandType& type)
{
    IR_ASSERTD( type < OP_TYPES_NUM);
    type_ = type;
}

/** Add the operand in the output stream s */ 
inline void Operand::toStream( ostream &s) const
{
    switch( type() )
    {   
        case OP_TYPE_IMM:
            s << constValue();
            break;
        case OP_TYPE_OBJ:
            object()->toStream( s);
            break;
        case OP_TYPE_TRG:
            s << '[' << target()->id() << ']';
            break;
        case OP_TYPES_NUM:
            s << "none";
            break;
        default:
            IR_ASSERTD( 0); 
    }   
}


inline ostream& operator<<( ostream& s, const Operand& opnd)
{
    opnd.toStream( s);
    return s;
}

}//namespace ir
