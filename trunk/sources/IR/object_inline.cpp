/**
 * @file: object_inline.cpp
 * Implementation of operation
 * Core component of Operations and Objects  
 */
/**
 * Copyright (C) 2012 MIPT Sheme Compiler team
 */

#include "object.hpp"

Object::Object( UInt16 id_object, TypeOfObject type, bool is_virtual)
{
    this->id_object = id_object;
    this->type = type;
    this->is_virtual = is_virtual;
}

inline UInt16 Object::getId() const
{
    return this->id_object;
}

inline void Object::setId( UInt16 id_object)
{
    this->id_object = id_object;
}

inline bool Object::isPseudo() const
{
    return this->is_virtual;
}

inline void Object::setPseudo( bool is_virtual)
{
    this->is_virtual = is_virtual;
}

inline TypeOfObject Object::getType( TypeOfObject type) const
{
    return this->type;
}
