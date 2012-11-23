/**
* @file:ast.cpp
* Difinition of methods (AST Nodes)
* Source code of AST (parser)
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#include "ast.hpp"

namespace parser
{
    namespace ast
    {
        void Nodep::accept(Visitor *visitor)
        {
            (this->get())->accept(visitor, *this);
        }

        Nil::Nil()
        {

        }

        Nil::~Nil()
        {

        }

        Type Nil::type() const
        {
            return NIL;
        }

        Type Nil::static_type()
        {
            return NIL;
        }

        void Nil::accept(Visitor *visitor, Nodep me)
        {
            visitor->visitNil(me);
        }

        Cons::Cons( const Cons& src) : _car(src._car), _cdr(src._cdr)
        {

        }

        Cons::Cons( Nodep car_value, Nodep cdr_value) : _car(car_value), _cdr(cdr_value)
        {

        }

        Cons::~Cons()
        {

        }

        Type Cons::type() const
        {
            return CONS;
        }

        Type Cons::static_type()
        {
            return CONS;
        }

        Nodep Cons::car()
        {
            return _car;
        }

        const Node* Cons::car() const
        {
            return _car.get();
        }

        Nodep Cons::cdr()
        {
            return _cdr;
        }

        const Node* Cons::cdr() const
        {
            return _cdr.get();
        }

        void Cons::setCar( Nodep car_value)
        {
            _car = car_value;
        }

        void Cons::setCdr( Nodep cdr_value)
        {
            _cdr = cdr_value;
        }

        void Cons::accept(Visitor *visitor, Nodep me)
        {
            visitor->visitCons(me);
        }

        Number::Number( const Number& src) : _value(src._value)
        {

        }

        Number::Number( long double src) : _value(src)
        {

        }

        long double Number::value() const
        {
            return _value;
        }

        void Number::setValue( long double number_value)
        {
            _value = number_value;
        }

        Number::~Number()
        {

        }

        Type Number::type() const
        {
            return NUMBER;
        }

        Type Number::static_type()
        {
            return NUMBER;
        }

        void Number::accept(Visitor *visitor, Nodep me)
        {
            visitor->visitNumber(me);
        }

        String::String( const String& src) : _value(src._value)
        {

        }

        String::String( const std::string& src) : _value(src)
        {

        }

        String::~String()
        {

        }

        Type String::type() const
        {
            return STRING;
        }

        Type String::static_type()
        {
            return STRING;
        }

        std::string& String::value()
        {
            return _value;
        }

        const std::string& String::value() const
        {
            return _value;
        }

        void String::setValue( const std::string& string_value)
        {
            _value = string_value;
        }

        void String::accept(Visitor *visitor, Nodep me)
        {
            visitor->visitString(me);
        }

        Char::Char( const Char& src) : _value(src._value)
        {

        }

        Char::Char( char src) : _value(src)
        {

        }

        Char::~Char()
        {

        }

        Type Char::type() const
        {
            return CHAR;
        }

        Type Char::static_type()
        {
            return CHAR;
        }

        char Char::value() const
        {
            return _value;
        }

        void Char::setValue( char char_value)
        {
            _value = char_value;
        }

        void Char::accept(Visitor *visitor, Nodep me)
        {
            visitor->visitChar(me);
        }

        Vector::Vector( const Vector& src) : _value(src._value)
        {

        }

        Vector::Vector( const std::vector<Nodep>& vector_value) : _value(vector_value)
        {

        }

        Vector::~Vector()
        {

        }

        Type Vector::type() const
        {
            return VECTOR;
        }

        Type Vector::static_type()
        {
            return VECTOR;
        }

        std::vector<Nodep>& Vector::value()
        {
            return _value;
        }

        const std::vector<Nodep>& Vector::value() const
        {
            return _value;
        }

        void Vector::setValue( const std::vector<Nodep>& vector_value)
        {
            _value = vector_value;
        }

        void Vector::accept(Visitor *visitor, Nodep me)
        {
            visitor->visitVector(me);
        }
    }
}

