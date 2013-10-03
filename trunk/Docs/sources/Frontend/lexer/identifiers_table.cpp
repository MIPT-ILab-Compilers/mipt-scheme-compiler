/**
 * @file:identifiersTable.cpp
 * Implementation of identifiersTable
 */
/**
 * Copyright 2012 MIPT-COMPILER team
 */

#include "identifiers_table.hpp"

namespace parser
{
int IdentifiersTable::insert( const std::string& identifier)
{
    map_table_priv[top_priv] = identifier;
    return top_priv++;
}

std::string IdentifiersTable::getIdentifier( int name) const
{
    return map_table_priv.find(name)->second;
}
}
