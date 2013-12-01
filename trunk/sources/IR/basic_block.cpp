/**
  * @file:basic_block.cpp
  * Implementation of basic block
  */
/**
 * Copyright (C) 2013 MIPT Scheme Compiler team
 */

#include "ir_iface.hpp"

namespace ir
{

BasicBlock::BasicBlock( BasicBlockUid id): id_( id), prev_( NULL), next_( NULL)
{
}

BasicBlock::~BasicBlock()
{
}

}//namespace ir
