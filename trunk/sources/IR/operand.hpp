/**
 * @file:operand.hpp
 * Interface of operand
 * Core component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#pragma once

namespace ir
{

/**
 * @class Operand
 * Representation of Operand
 */
class Operand
{

public:

    /** Constructor */
    Operand();

    /** Destructor */
    ~Operand();

    /** Return operand type */
    inline const OperandType& type() const;

    /** Set operand type */
    inline void setType( const OperandType& type);
    
    /** Return constant value */
    inline Int64 constValue() const;
    /** Return object */
    inline Object* object() const;
    /** Return target */
    inline Operation* target() const;
    
    /** Set constant value */
    inline void setConstValue( Int64 immediate);
    /** Set object */
    inline void setObject( Object& obj);
    /** Set target */
    inline void setTarget( Operation& target);

private:

    /** Operand type */
    OperandType type_;

    /** Operand data */
    union OperandData
    {
        Int64 imm;
        Object *obj;
        Operation *target;
    } data;
    
};

}//namespace ir

