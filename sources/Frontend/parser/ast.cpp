/**
* @file:ast.cpp
* Definition of methods (AST Nodes)
* Source code of AST (parser)
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#include "ast.hpp"
#include <iostream>

namespace parser
{
    namespace ast
    {

        void Nodep::accept( Visitor *visitor)
        {
            ( this->get())->accept( visitor, *this);
        }

        Symbol::Symbol( SymbolIdType id)
        {
            symbol_id = id;
        };

        SymbolIdType Symbol::getId()
        {
            return symbol_id;
        }

        Symbol::~Symbol()
        {

        }

        Ident::Ident(string id)
        {
            _id = id;
        }

        void Ident::putId(string id)
        {
            _id = id;
        }

        string Ident::getId()
        {
            return _id;
        }

        Ident::~Ident()
        {

        }

        void Ident::accept( Visitor *visitor, Nodep me)
        {
            visitor->visitNil( me);
        }

        int Ident::type() const
        {
            return IDENT;
        }

        Nil::Nil()
        {

        }

        Nil::~Nil()
        {

        }

        int Nil::type() const
        {
            return NIL;
        }

        int Nil::static_type()
        {
            return NIL;
        }

        void Nil::accept( Visitor *visitor, Nodep me)
        {
            visitor->visitNil( me);
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

        int Cons::type() const
        {
            return CONS;
        }

        int Cons::static_type()
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

        void Cons::accept( Visitor *visitor, Nodep me)
        {
            visitor->visitCons( me);
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

        int Number::type() const
        {
            return NUMBER;
        }

        int Number::static_type()
        {
            return NUMBER;
        }

        void Number::accept( Visitor *visitor, Nodep me)
        {
            visitor->visitNumber( me);
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

        int String::type() const
        {
            return STRING;
        }

        int String::static_type()
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

        void String::accept( Visitor *visitor, Nodep me)
        {
            visitor->visitString( me);
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

        int Char::type() const
        {
            return CHAR;
        }

        int Char::static_type()
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

        void Char::accept( Visitor *visitor, Nodep me)
        {
            visitor->visitChar( me);
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

        int Vector::type() const
        {
            return VECTOR;
        }

        int Vector::static_type()
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

        void Vector::accept( Visitor *visitor, Nodep me)
        {
            visitor->visitVector( me);
        }

        void DumpVisitor::visitNil( Nodep _nil)
        {
            std::cout << "()";
        }

        void DumpVisitor::visitCons( Nodep _cons)
        {
            Cons *a = as<Cons>(_cons);
            std::cout << '(';
            a->car().accept(this);
            if (a->cdr().get()->type() != NIL) {
                std::cout << " . ";
                a->cdr().accept(this);
            }
            std::cout << ')';
        }

        void DumpVisitor::visitNumber( Nodep _number)
        {   
            Number *a = as<Number>(_number);
            std::cout << a->value();
        }

        void DumpVisitor::visitString( Nodep _string)
        {   
            String *a = as<String>(_string);
            std::cout << '\"' << a->value() << '\"';
        }

        void DumpVisitor::visitChar( Nodep _char)
        {
            Char *a = as<Char>(_char);
            std::cout << '\'' <<  a->value() << '\'';
        }

        void DumpVisitor::visitVector( Nodep _vector)
        {
            Vector *a = as<Vector>(_vector);
            std::cout << '[';
            std::vector<Nodep> v = a->value();
            std::vector<Nodep>::iterator it = v.begin();
            it->accept(this);
            it++;
            for ( ; it < v.end(); it++) {
                std::cout << ", ";
                it->accept(this);
            }
            std::cout << ']';
        }
    }
}
