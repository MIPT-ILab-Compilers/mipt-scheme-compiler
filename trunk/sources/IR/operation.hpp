/**
 * @file:operation.hpp
 * Interface of operation
 * Temporary component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#pragma once

#include <iostream>

namespace ir
{

/**
 * @class Operation
 * Representation of Operation
 */
class Operation
{

public:

    /** Constructor */
    Operation( OperUid id);

    /** Destructor */
    virtual ~Operation();
   
    /** Return oper unique id */
    inline OperUid id() const;

    /** Return oper name */
    inline OperName name() const;

    /** Get number of arguments */
    inline UInt8 numArgs() const;

    /** Get number of results */
    inline UInt8 numRess() const;

    /** Get argument */
    inline const Operand& arg( UInt8 arg_num) const;

    /** Get result */
    inline const Operand& res( UInt8 res_num) const;

    /** Set name of operation */
    inline void setName( OperName name);

    /** Set argument object */
    inline void setArgObj( UInt8 arg_num, Object& obj);
    
    /** Set argument immediate */
    inline void setArgImm( UInt8 arg_num, Int64 imm);

    /** Set argument target */
    inline void setArgTrg( UInt8 arg_num, Operation& trg);
    
    /** Set result object */
    inline void setResObj( UInt8 arg_num, Object& obj);

    /** Set type of argument */
    inline void setArgType( UInt8 arg_num, const OperandType& argt);

    /** Set type of result */
    inline void setResType( UInt8 arg_num, const OperandType& rest);
   
    /** Add the operation in the output stream s */
    inline void toStream( ostream& s) const;
 
private:

    /** Operation unique id */
    OperUid id_;

    /** Operation name */
    OperName name_;

    /** Arrays of operands */
    Operand args[ MAX_ARGS_NUM];
    Operand ress[ MAX_RESS_NUM];
    
    // Not implemented yet
    /** Pointer to parent Basic Block */
    // BasicBlock* parentBasicBlock;
};

inline ostream& operator<<( ostream& s, const Operation& op);

}//namespace ir
