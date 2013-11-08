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

ostream& operator << (ostream& s, const Operation& op)
{
    s << "[" << op.id() << "] " << op.getNameOpInString() << " ";
    for ( UInt8 i = 0; i < op.numArgs(); i++ )
    {
        if ( i == 0 )
            s << op.arg( i);
        else
            s << ", " << op.arg( i);
    }
    s << " -> ";
    for ( UInt8 i = 0; i < op.numRess(); i++ )
    {
        if ( i == 0 )
            s << op.res( i);
        else
            s << ", " << op.res( i);
    }
    s << endl;
    return s;
}

}//namespace ir
