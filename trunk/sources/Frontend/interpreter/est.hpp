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
    class Interpreter;

    namespace est
    {
        enum Type { FUNCTION = parser::ast::NEXT, MACROS, SPECIAL_FORM, PORT, EOF_OBJECT };

        class Visitor;

        class estNode : public parser::ast::Node
        {
        public:
            virtual void acceptVoid( parser::ast::Visitor<void> * visitor, Nodep me){}
            virtual Nodep acceptNodep( parser::ast::Visitor<Nodep> * visitor, Nodep me );
            virtual Nodep acceptNodep( Visitor * visitor, Nodep me) = 0;
        };

        class Function : public estNode
        {
            boost::function<Nodep (Nodep args, interpreter::Interpreter& interp)> _value;
        public:
            Function ( Nodep ( *ptr) ( Nodep args, Interpreter& interp));
            virtual int type() const;
            static int staticType();

            Nodep call ( Nodep args, Interpreter& interp);
            Nodep acceptNodep( Visitor * visitor, Nodep me);
 
            virtual ~Function();
        };

        class Macros : public estNode
        {
            boost::function<Nodep ( Nodep args)> _value;
        public:
            Macros ( Nodep ( *ptr) ( Nodep args));
            virtual int type() const;
            static int staticType();

            Nodep apply ( Nodep args);
            Nodep acceptNodep( Visitor * visitor, Nodep me);

            virtual ~Macros();
        };

        class SpecialForm : public estNode
        {
            boost::function<Nodep ( Nodep args, Interpreter& interp)> _value;
        public:
            SpecialForm ( Nodep ( *ptr) ( Nodep args, Interpreter& interp));
            virtual int type() const;
            static int staticType();

            Nodep apply ( Nodep args, Interpreter& interp);
            Nodep acceptNodep( Visitor * visitor, Nodep me);

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

            Nodep acceptNodep( Visitor * visitor, Nodep me);

            virtual ~Port();
        };

        class EOFobject : public estNode
        {
        public:
            EOFobject();

            virtual int type() const;
            static int staticType();

            Nodep acceptNodep( Visitor * visitor, Nodep me);

            virtual ~EOFobject();
        };

        class Visitor : parser::ast::Visitor<Nodep>
        {
        public:
            virtual Nodep visitMacros( Nodep _macros) = 0;
            virtual Nodep visitFunction( Nodep _function) = 0;
            virtual Nodep visitSpecialForm( Nodep _specialForm) = 0;
            virtual Nodep visitPort( Nodep _port) = 0;
            virtual Nodep visitEOFobject( Nodep _eofObject) = 0;
        };
    }
}
