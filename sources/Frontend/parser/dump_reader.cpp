/**
 * @file dump_reader.cpp
 * @author Denis Anisimov
 * Dump reader class implementation.
 * Reads AST text representation from input stream.
 */
/**
 * Copyright 2013 MIPT Scheme compiler team
 */

#include "dump_reader.hpp"
#include "../frontend_exception.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_bind.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <vector>
#include <string>
#include <istream>

/**
 * This dump reader is actually parser built upon Boost Spirit.Qi
 * Below are short descriptions of packages used:
 * qi      - parsing tool
 * phoenix - functional programming in C++
 * fusion  - working with tuples
 * variant - variant data types
 * 
 * More detailed information about implementation is in code comments.
 */

namespace parser
{
    /**
     * NOTE: code below is written using boost code style
     * Just to avoid style mess
     */
    namespace qi_parser
    {
        namespace qi = boost::spirit::qi;
        namespace ascii = boost::spirit::ascii;
        namespace phx = boost::phoenix;
        
        /**
         * Node constructors
         * @param val
         * @return shared pointer to created node
         */
        Nodep num_constr( double val)
        {
            return Nodep( (Node*)(new Number(val)));
        }

        Nodep str_constr( std::vector<char> val)
        {
            std::string str( val.begin(), val.end());
            return Nodep( (Node*)(new String(str)));
        }

        Nodep id_constr( std::vector<char> val)
        {
            std::string str( val.begin(), val.end());
            return Nodep( (Node*)(new Ident(str)));
        }
        
        Nodep nil_constr( )
        {
            return Nodep( (Node*)(new Nil( )));
        }
        
        Nodep cons_constr( Nodep car, Nodep cdr)
        {
            return Nodep( (Node*)(new Cons( car, cdr)));
        }

        
        /**
         * Spirit.Qi grammar.
         * Create grammar with given Iterator type, return value Nodep
         * and default ASCII spaces skipping.
         */
        template <typename Iterator>
        struct dump_grammar : qi::grammar<Iterator, Nodep(), ascii::space_type>
        {            
            dump_grammar() : dump_grammar::base_type( expr) // init base type
            {
                using qi::lit;    // literal
                using qi::lexeme; // lexeme, inhibits space skipping
                using qi::double_;
                using qi::long_;
                using ascii::char_;
                using ascii::string;
                using namespace qi::labels; // labels, like _a, _1, etc
                
                /**
                 * Rules.
                 * Expression in square brackets denotes semantic action.
                 * _val is a placeholder for rule value, _1,_2... are placeholders
                 * for rule expressions return values 
                 * 
                 * Note on binding construction:
                 *   bind( &func, arg) is equal to func(arg)
                 */
                number = ( "n[" >> double_ >> ']' )
                        [
                        _val = phx::bind( &num_constr, _1)
                        ];
                        
                str = lexeme['"' >> +(char_ -'"') >> '"'] 
                      [
                      _val = phx::bind( &str_constr, _1)
                      ];
                        
                ident = ( "id[" >> +(char_ -']') >> ']' )
                         [
                         _val = phx::bind( &id_constr, _1)
                         ];
                
                nil = "()" >> qi::eps
                        [
                        _val = phx::bind( &nil_constr)
                        ];

                atom = ( number | str | ident | nil );
                
                cons = ( '(' >> expr >> '.' >> expr >> ')' )
                        [
                        _val = phx::bind( &cons_constr, _1, _2)
                        ];
                
                expr = ( cons | atom );                        
            }
            
            /**
             * Separate rules declaration
             * Template parameters:
             *  1) Iterator
             *  2) return type
             *  3) space skipper
             */
            qi::rule<Iterator, Nodep(), ascii::space_type> expr, cons, number, str, ident, nil, atom;
        };
    };
    
    DumpReader::DumpReader( istream& is): inp_stream( is) {};
    
    Nodep DumpReader::read()
    {
        qi_parser::dump_grammar< std::string::const_iterator > dump_gr; // Our grammar
        Nodep expr; // Our tree

        /* Spacer */
        using boost::spirit::ascii::space;
        
        /* Init input */
        std::istreambuf_iterator<char> eos;
        std::istreambuf_iterator<char> begin(inp_stream);
        std::string str( begin, eos);
        std::string::const_iterator iter = str.begin();
        std::string::const_iterator end = str.end();
        
        /* Parse */
        bool r = boost::spirit::qi::phrase_parse(iter, end, dump_gr, space, expr);
        
        if ( r && ( iter == end ) )
        {
            return expr;
        } else
        {
            throw FrontendException( "Error while reading dump" );
        }
    }
}; // namespace parser
