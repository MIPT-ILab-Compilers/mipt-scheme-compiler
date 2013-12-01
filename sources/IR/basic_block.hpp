/**
  * @file:basic_block.hpp
  * Interface of basic block
  */
/**
 * Copyright (C) 2013 MIPT Scheme Compiler team
 */

#pragma once

#include <iostream>

namespace ir
{

/**
 * @class BacicBlock
 * Representation of Basic Block
 */
class BasicBlock
{

public:

    /** Constructor */
    BasicBlock( BasicBlockUid id);

    /** Destructor */
    virtual ~BasicBlock();

    /** Return basic block id */
    inline BasicBlockUid id() const;

    /** Get prev basic block */
    inline const BasicBlock* prev() const;

    /** Get next basic block */
    inline const BasicBlock* next() const;

    /** Get the last added operation */
    inline const Operation lastOperation();

    /** Set prev basic block */
    inline void setPrevBlock( BasicBlock& prev);

    /** Set next basic block */
    inline void setNextBlock( BasicBlock& next);

    /** Add an operation in basic block */
    inline void addOperation( const Operation& op);

    /** Add the basic block in the output stream s */
    inline void toStream( ostream& s) const;

private:

    /** id of Basic Block */
    BasicBlockUid id_;

    /** Prev basic block */
    BasicBlock* prev_;

    /** Next basic block */
    BasicBlock* next_;

    /** List of operations */
    list<Operation> operations_;

    // Not implemented yet
    /** Parent function */
    // Function* parentFunction;
};

inline ostream& operator<<( ostream& s, const BasicBlock& bb);

}//namespace ir
