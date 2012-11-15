/**
 * @file:tokens.hpp
 * Implementation of tokens-table
 */
/**
 * Copyright 2012 MIPT-COMPILER team
 */

#pragma once

namespace parser
{
    namespace tokens
    {
        enum Token
        {
            ENDOFFILE,
            BOOLEAN,
            IDENTIFIER,
            STRING,
            NUMBER,
            QUOTE,
            DOT,
            CHARACTER,
            OPENVBRACKET,
            OPENBITVBRACKET,
            OPENBRACKET,
            CLOSEBRACKET
        };
    }
}
