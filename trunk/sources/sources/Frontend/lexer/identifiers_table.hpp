/**
 * @file:identifiersTable.hpp
 */
/**
  * Copyright 2012 MIPT-COMPILER team
  */

#pragma once

#include <map>
#include <string>

namespace parser
{
class IdentifiersTable
{
private :
    std::map<int, std::string> map_table_priv;
    int top_priv;

public:
    IdentifiersTable()
        : map_table_priv()
        , top_priv( 1)
    {}

    int insert( const std::string& identifier);

    std::string getIdentifier( int name) const;
};
}
