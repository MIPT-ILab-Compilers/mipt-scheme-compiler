/**
 * @file: object_inline.cpp
 * Implementation of operation
 * Core component of Operations and Objects  
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */


#include "object.hpp"


Object::Object( UInt64 id_object, TypeOfObject type, bool is_virtual)
{
    this->id_object = id_object;
    this->type = type;
    this->is_virtual = is_virtual;
}
