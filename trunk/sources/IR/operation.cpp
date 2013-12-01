/**
 * @file:operation.cpp
 * Implementation of operation
 * Temporary component of Operations and Objects
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

#include "ir_iface.hpp"

namespace ir
{

Operation::Operation( OperUid id): id_( id), name_( OPERS_NUM)
{
}

Operation::~Operation()
{
}

}//namespace ir
