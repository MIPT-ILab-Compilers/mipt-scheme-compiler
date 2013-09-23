/**
 * @file:object.hpp
 * Interface of object
 * Core component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#pragma once

#include "Utils/types.h"

namespace ir
{

enum TypeOfObject
{
    OBJ_REGISTER,
    OBJ_TYPE_NUM
};

class Object
{

public:
    Object( UInt64 id_object, TypeOfObject type, bool is_virtual);
    
    inline UInt64 getId() const;
    
    inline void setId( UInt64 id_object);

    inline bool isVirtual() const;
    
    inline void setVirtual( bool is_virtual);
    
    inline TypeOfObject getType( TypeOfObject type) const;
    
private:
    bool is_virtual;
    TypeOfObject type;
    UInt64 id_object;
}; 

}//namespace ir

#include "object_inline.hpp"
