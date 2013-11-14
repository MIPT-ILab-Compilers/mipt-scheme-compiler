/**
 * @file:object.hpp
 * Interface of object
 * Core component of Operations and Objects
 */
/**
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */

#pragma once

namespace ir
{

/**
 * @class Object
 * Representation of object 
 */
class Object
{

public:

    /** Constructor */
    Object();

    /** Destructor */
    ~Object();
   
    /** Return id */
    inline ObjId id() const;
   
    /** Set id */ 
    inline void setId( ObjId id);

    /** Return whether object is virtual */
    inline bool isVirtual() const;
   
    /** Set virtual flag */ 
    inline void setVirtual( bool is_virtual);
    
    /** Return type of object */
    inline ObjName type() const;

    /** Set object type */
    inline void setType( ObjName type);

    /** Add the object in the output stream s */
    inline void toStream(ostream& s) const;
    
private:

    /** Object id */
    ObjId id_;
    /** Object type */
    ObjName type_;
    /** Whether object is virtual */
    bool is_virtual;
}; 

}//namespace ir

