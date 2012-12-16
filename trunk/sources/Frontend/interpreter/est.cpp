/*
 *@file:est.cpp 
 * Definition of methods for EST
 * Source code of EST (interpretator)
 */
/**
 * Copyright 2012 MIPT-COMPILER team
 */

#include "est.hpp"
#include <fstream>
#include <stdexcept>

namespace interpreter
{
    namespace est
    {

        void estNode::accept( parser::ast::Visitor * visitor, Nodep me )
        {
            Visitor * vptr;
            if( !(vptr = dynamic_cast<Visitor *>( visitor) ) )
            {
                throw std::bad_cast();
            }
            else
            {
                this->accept( vptr, me );
            }
        }

        Function::~Function()
        {

        }

        int Function::type() const
        {
            return FUNCTION;
        }

        int Function::staticType()
        {
            return FUNCTION;
        }

        void Function::accept(Visitor * visitor, Nodep me)
        {
            visitor->visitFunction( me );
        }

        Macros::~Macros()
        {

        }

        int Macros::type() const
        {
            return MACROS;
        }

        int Macros::staticType()
        {
            return MACROS;
        }

        void Macros::accept(Visitor * visitor, Nodep me)
        {
            visitor->visitMacros( me );
        }

        SpecialForm::~SpecialForm()
        {

        }

        int SpecialForm::type() const
        {
            return SPECIAL_FORM;
        }

        int SpecialForm::staticType()
        {
            return SPECIAL_FORM;
        }

        void SpecialForm::accept(Visitor * visitor, Nodep me)
        {
            visitor->visitSpecialForm( me );
        }

        std::streambuf * stdi = std::cin.rdbuf();

        Port::Port( std::ostream & os ) : _value(stdi)
        {
            output = true; input = false;
            _value.rdbuf(os.rdbuf());
        }

        Port::Port( std::istream & is ) : _value(stdi)
        {
            input = true; output = false;
            _value.rdbuf(is.rdbuf());
        }

        Port::Port( bool in, bool out , const char * filename ) : _value(stdi)
        {
            input = in; output = out;

            if( in && out )
            {
                fb.open(filename, std::ios::in | std::ios::out);
            }
            else if( in )
            {
                fb.open(filename, std::ios::in );
            }
            else if( out )
            {
                fb.open(filename, std::ios::out );
            }
            else
            {
                throw "invalid set of flags!";
            }

            _value.rdbuf( &fb );
        }

        void Port::accept(Visitor * visitor, Nodep me)
        {
            visitor->visitPort( me );
        }

        Port::~Port()
        {

        }

        int Port::type() const
        {
            return PORT;
        }

        int Port::staticType()
        {
            return PORT;
        }

        char Port::readChar()
        {
            if( input )
            {
                char c;
                _value >> c;
                return c;
            }
            else
            {
                throw "incorrect type of port!";
            }
        } 

        void Port::writeChar( char c )
        {
            if( output )
            {
                _value << c;
            }
            else
            {
                throw "incorrect type of port!";
            }
        }


        void Port::closePort()
        {
            if( fb.is_open() )
            {
                fb.close();
            }
            else
            {
                throw "port is not open!";
            }
        }

        bool Port::eof() const
        {
            return _value.eof();
        }
    }
}
