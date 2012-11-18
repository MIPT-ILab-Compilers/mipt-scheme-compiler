/**
* @file:ast.hpp
* The header file of AST Nodes. Also it contains a template function for type conversion
* Header of AST (parser)
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

namespace parser
{
    namespace ast
    {
        enum Type { NIL, CONS, NUMBER, STRING, CHAR, VECTOR };

        /* General abstract class */
        class Node
        {
        public:
            virtual Type type() const = 0;
        };

        typedef boost::shared_ptr<Node> Nodep;
        
        class Nil : public Node
        {
        public:
            Nil();

            virtual Type type() const;
            static Type static_type();
            
            virtual ~Nil();
        };

        class Cons : public Node
        {
            Nodep _car;
            Nodep _cdr;
        public:
            Cons( const Cons& src);
            Cons( Nodep car_value, Nodep cdr_value);

            virtual Type type() const;
            static Type static_type();

            /* Getters and setters */
            virtual Nodep car();
            virtual const Node* car() const;
            virtual Nodep cdr();
            virtual const Node* cdr() const;
            virtual void setCar( Nodep car_value);
            virtual void setCdr( Nodep cdr_value);
            
            virtual ~Cons();
        };
        
        class Number : public Node
        {
            long double _value;
        public:
            Number( const Number& src);
            Number( long double src);

            virtual Type type() const;
            static Type static_type();

            virtual long double value() const;
            virtual void setValue( long double number_value);

            virtual ~Number();
        };
        
        class String : public Node
        {
            std::string _value;
        public:
            String( const String& src);
            String( const std::string& src);

            virtual Type type() const;
            static Type static_type();

            /* You can change the value by this getter */
            virtual std::string& value();
            virtual const std::string& value() const;
            virtual void setValue( const std::string& string_value);

            virtual ~String();
        };

        class Char : public Node
        {
            char _value;
        public:
            Char( const Char& src);
            Char( char src);

            virtual Type type() const;
            static Type static_type();

            virtual char value() const;
            virtual void setValue( char char_value);

            virtual ~Char();
        };
        
        class Vector : public Node
        {
            std::vector<Nodep> _value;
        public:
            Vector( const Vector& src);
            Vector( const std::vector<Nodep>& vector_value);
            
            virtual Type type() const;
            static Type static_type();

            virtual std::vector<Nodep>& value();
            virtual const std::vector<Nodep>& value() const;
            virtual void setValue( const std::vector<Nodep>& vector_value);

            virtual ~Vector();
        };

        template <typename T>
        T* as( Nodep ptr) /* Throws exception */
        {
            if ( ptr->type() == T::static_type())
                return dynamic_cast<T*>( ptr.get());
            else
                throw std::bad_cast();
        }
    }
}
