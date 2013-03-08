/**
 * @file dump_reader.hpp
 * @author Denis Anisimov
 * The header file for dump reader class.
 * Reads AST text representation from input stream.
 */
/**
 * Copyright 2013 MIPT Scheme compiler team
 */

#pragma once

#include <istream>
#include "ast.hpp"

namespace parser
{
    using std::istream;
    using namespace ast;
    
    /**
     * Dump reader class. Reads AST text dump from input stream.
     * AST dump must be in following format:
     *   DUMP -> EXPR
     *   EXPR -> ( EXPR. EXPR) | ATOM
     *   ATOM -> n[<value>] | "<string>" | sym[<id>] | ()
     * Example:
     *   ( sym[0]. ( ( n[1]. ( n[2]. ( "abcd". ()))). ()))
     */
    class DumpReader
    {
    public:
        /**
         * Construct reader with given input stream.
         * @param is - input stream
         */
        DumpReader( istream& is);
        
        /**
         * Read dump from input stream.
         * @return pointer to AST root node
         */
        Nodep read();
    private:
        /**
         * Stream to read from
         */
        istream& inp_stream;
    };
} // namespace parser
