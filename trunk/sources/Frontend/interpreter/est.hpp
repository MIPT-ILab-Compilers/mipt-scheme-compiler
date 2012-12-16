/**
 * @file:est.hpp
 * Header file of EST nodes
 * Header of EST (interpretator)
 */
/**
 * Copyright 2012 MIPT-COMPILER team
 */

#pragma once

#include "../parser/ast.hpp"
#include <boost/function.hpp>
#include <iostream>
#include <fstream>
using parser::ast::Nodep;

namespace interpreter
{
    namespace est
    {
        enum Type { FUNCTION = parser::ast::NEXT, MACROS, SPECIAL_FORM, PORT };

        class Visitor;

        class estNode : parser::ast::Node
        {
        public:
            virtual void accept( parser::ast::Visitor * visitor, Nodep me );
            virtual void accept( Visitor * visitor, Nodep me) = 0;
        };

        class Function : public estNode
        {
            boost::function<Nodep (Nodep args)> _value;
        public:
            virtual int type() const;
            static int staticType();

            void accept( Visitor * visitor, Nodep me);
 
            virtual ~Function();
        };

        class Macros : public estNode
        {
        public:
            virtual int type() const;
            static int staticType();

            void accept( Visitor * visitor, Nodep me);

            virtual ~Macros();
        };

        class SpecialForm : public estNode
        {
        public:
            virtual int type() const;
            static int staticType();

            void accept( Visitor * visitor, Nodep me);

            virtual ~SpecialForm();
        };

        class Port : public estNode
        {
            std::iostream _value;
            std::filebuf fb;
            bool input;
            bool output;
        public:
            Port( std::ostream & os);
            Port( std::istream & is);
            Port( bool in, bool out, const char * filename );

            virtual int type() const;
            static int staticType();

            char readChar();
            void writeChar( char c );

            void closePort();
            bool eof() const;

            void accept( Visitor * visitor, Nodep me);

            virtual ~Port();
        };

        class Visitor : parser::ast::Visitor
        {
        public:
            virtual void visitMacros( Nodep _macros) = 0;
            virtual void visitFunction( Nodep _function) = 0;
            virtual void visitSpecialForm( Nodep _spacialForm) = 0;
            virtual void visitPort( Nodep _port) = 0;
        };
    }
}
