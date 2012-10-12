/**
 * @file:object.hpp
 * Interface of object
 * Core component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#pragma once

#include "../Utils/types.h"


enum TypeOfObject
{
    REGISTER,
    ANOTHER,
    TYPE_NUM
};

class Object
{

public:
    Object( UInt16 id_object, TypeOfObject type, bool is_virtual);
    
    inline UInt16 getId() const;
    
    inline void setId( UInt16 id_object);

    inline bool isPseudo() const;
    
    inline void setPseudo( bool is_virtual);
    
    inline TypeOfObject getType( TypeOfObject type) const;
    
private:
    bool is_virtual;
    TypeOfObject type;
    UInt16 id_object;
}; 

#endif /* OBJECT_HPP */  
