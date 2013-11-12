/**
 * @file:operation_inline.cpp
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

void Operation::opToStream( ostream& s) const
{
    s << "[" << id() << "] " << getOperNameString( name()) << " ";
    for ( UInt8 i = 0; i < numArgs(); i++ )
    {   
        if ( i == 0 )
            s << arg( i); 
        else
            s << ", " << arg( i);
    }
    s << " -> ";
    for ( UInt8 i = 0; i < numRess(); i++ )
    {   
        if ( i == 0 )
            s << res( i);
        else
            s << ", " << res( i);
    }
}

}//namespace ir
