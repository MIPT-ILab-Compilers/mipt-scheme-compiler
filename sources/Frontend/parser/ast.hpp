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

        typedef std::string SymbolIdType;

        using std::string;

        enum Type { NIL, CONS, NUMBER, STRING, CHAR, VECTOR, IDENT, NEXT };

        class Visitor;
        class Nodep;

        /* General abstract class */
        class Node
        {
        public:
            virtual int type() const = 0;
            virtual void accept( Visitor *visitor, Nodep me) = 0;
        };

        class Nodep : public boost::shared_ptr<Node>
        {
        public:
            Nodep( Node* ptr) : boost::shared_ptr<Node>(ptr) {};
            Nodep() : boost::shared_ptr<Node>() {};
            void accept( Visitor *visitor);
        };

        class Symbol
        {
            SymbolIdType symbol_id;
        public:
            Symbol( SymbolIdType id);
            SymbolIdType getId();
            ~Symbol();
        };

        class Ident : public Node
        {
            string _id;
        public:
            Ident(string id);
            void putId(string id);
            string getId();
            void accept( Visitor *visitor, Nodep me);
            virtual int type() const;
            virtual ~Ident();
        };

        class Nil : public Node
        {
        public:
            Nil();
            void accept( Visitor *visitor, Nodep me);
            virtual int type() const;
            static int static_type();

            virtual ~Nil();
        };

        class Cons : public Node
        {
            Nodep _car;
            Nodep _cdr;
        public:
            Cons( const Cons& src);
            Cons( Nodep car_value, Nodep cdr_value);

            virtual int type() const;
            static int static_type();

            /* Getters and setters */
            virtual Nodep car();
            virtual const Node* car() const;
            virtual Nodep cdr();
            virtual const Node* cdr() const;
            virtual void setCar( Nodep car_value);
            virtual void setCdr( Nodep cdr_value);
            void accept( Visitor *visitor, Nodep me);
            virtual ~Cons();
        };

        class Number : public Node
        {
            long double _value;
        public:
            Number( const Number& src);
            Number( long double src);

            virtual int type() const;
            static int static_type();

            virtual long double value() const;
            virtual void setValue( long double number_value);
            void accept( Visitor *visitor, Nodep me);
            virtual ~Number();
        };

        class String : public Node
        {
            std::string _value;
        public:
            String( const String& src);
            String( const std::string& src);

            virtual int type() const;
            static int static_type();

            /* You can change the value by this getter */
            virtual std::string& value();
            virtual const std::string& value() const;
            virtual void setValue( const std::string& string_value);
            void accept( Visitor *visitor, Nodep me);

            virtual ~String();
        };

        class Char : public Node
        {
            char _value;
        public:
            Char( const Char& src);
            Char( char src);

            virtual int type() const;
            static int static_type();

            virtual char value() const;
            virtual void setValue( char char_value);
            void accept( Visitor *visitor, Nodep me);
            virtual ~Char();
        };

        class Vector : public Node
        {
            std::vector<Nodep> _value;
        public:
            Vector( const Vector& src);
            Vector( const std::vector<Nodep>& vector_value);

            virtual int type() const;
            static int static_type();

            virtual std::vector<Nodep>& value();
            virtual const std::vector<Nodep>& value() const;
            virtual void setValue( const std::vector<Nodep>& vector_value);
            void accept( Visitor *visitor, Nodep me);

            virtual ~Vector();
        };

        class Visitor
        {
        public:
            virtual void visitNil( Nodep _nil) = 0;
            virtual void visitCons( Nodep _cons) = 0;
            virtual void visitNumber( Nodep _number) = 0;
            virtual void visitString( Nodep _string) = 0;
            virtual void visitChar( Nodep _char) = 0;
            virtual void visitVector( Nodep _vector) = 0;
            virtual void visitIdent( Nodep _ident) = 0;
        };

        class DumpVisitor : public Visitor
        {
        public:
            virtual void visitNil( Nodep _nil);
            virtual void visitCons( Nodep _cons);
            virtual void visitNumber( Nodep _number);
            virtual void visitString( Nodep _string);
            virtual void visitChar( Nodep _char);
            virtual void visitVector( Nodep _vector);
            virtual void visitIdent( Nodep _ident) {};
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
