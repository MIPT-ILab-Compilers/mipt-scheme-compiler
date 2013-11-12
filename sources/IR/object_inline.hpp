/**
 * @file: object_inline.cpp
 * Implementation of operation
 * Core component of Operations and Objects  
 */
/**
 * Copyright (C) 2012 MIPT Scheme Compiler team
 */

namespace ir
{

/** Return object id */
inline ObjId Object::id() const
{
    return this->id_;
}

/** Set object id */
inline void Object::setId( ObjId id)
{
    this->id_ = id;
}

/** Set type */
inline void Object::setType( ObjName type)
{
    IR_ASSERTD( type < OBJ_NAMES_NUM);
    type_ = type;
}

/** Return whether object is virtual */
inline bool Object::isVirtual() const
{
    return this->is_virtual;
}

/** Set virtual flag */
inline void Object::setVirtual( bool is_virtual)
{
    this->is_virtual = is_virtual;
}

/** Return object type */
inline ObjName Object::type() const
{
    return this->type_;
}

/** Print name of object */
inline string Object::objPrintName() const
{
    string name;
    ostringstream number;
    number << id();
    if ( ( type() == OBJ_NAME_REG) && ( !isVirtual()) )
        name = "r";
    else if ( ( type() == OBJ_NAME_REG) && ( isVirtual()) )
        name = "v";
    name += number.str();
    return name;
}

}
