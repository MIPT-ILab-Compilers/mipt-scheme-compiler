/**
 * @file: object_inline.cpp
 * Implementation of operation
 * Core component of Operations and Objects  
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */


#include "ir_iface.hpp"

namespace ir
{

/** Constructor */
Object::Object() : id_( (ObjId) -1), type_( OBJ_NAMES_NUM), is_virtual( true) 
{
}

/** Destructor */
Object::~Object()
{
}

}
