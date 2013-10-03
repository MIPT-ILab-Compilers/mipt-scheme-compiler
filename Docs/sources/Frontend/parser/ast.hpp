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

typedef std::string IdentIdType;

using std::string;

enum Type { NIL, CONS, NUMBER, STRING, CHAR, VECTOR, IDENT, NEXT };

template <class T>
class Visitor;
class Nodep;

/* General abstract class */
class Node
{
public:
    virtual int type() const = 0;
    virtual void acceptVoid( Visitor<void> *visitor, Nodep me) = 0;
    virtual Nodep acceptNodep( Visitor<Nodep> *visitor, Nodep me) = 0;
};

class Nodep : public boost::shared_ptr<Node>
{
public:
    Nodep( Node* ptr) : boost::shared_ptr<Node>(ptr) {};
    Nodep() : boost::shared_ptr<Node>() {};
    void acceptVoid( Visitor<void> *visitor);
    Nodep acceptNodep( Visitor<Nodep> *visitor);
};

class Ident : public Node
{
    IdentIdType _id;
public:
    Ident( IdentIdType id);
    void putId( IdentIdType id);
    IdentIdType getId();
    void acceptVoid( Visitor<void> *visitor, Nodep me);
    Nodep acceptNodep( Visitor<Nodep> *visitor, Nodep me);
    virtual int type() const;
    static int staticType();
    virtual ~Ident();
};

class Nil : public Node
{
public:
    Nil();
    void acceptVoid( Visitor<void> *visitor, Nodep me);
    Nodep acceptNodep( Visitor<Nodep> *visitor, Nodep me);
    virtual int type() const;
    static int staticType();

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
    static int staticType();

    /* Getters and setters */
    virtual Nodep car();
    virtual const Node* car() const;
    virtual Nodep cdr();
    virtual const Node* cdr() const;
    virtual void setCar( Nodep car_value);
    virtual void setCdr( Nodep cdr_value);
    void acceptVoid( Visitor<void> *visitor, Nodep me);
    Nodep acceptNodep( Visitor<Nodep> *visitor, Nodep me);
    virtual ~Cons();
};

class Number : public Node
{
    long double _value;
public:
    Number( const Number& src);
    Number( long double src);

    virtual int type() const;
    static int staticType();

    virtual long double value() const;
    virtual void setValue( long double number_value);
    void acceptVoid( Visitor<void> *visitor, Nodep me);
    Nodep acceptNodep( Visitor<Nodep> *visitor, Nodep me);
    virtual ~Number();
};

class String : public Node
{
    std::string _value;
public:
    String( const String& src);
    String( const std::string& src);

    virtual int type() const;
    static int staticType();

    /* You can change the value by this getter */
    virtual std::string& value();
    virtual const std::string& value() const;
    virtual void setValue( const std::string& string_value);
    void acceptVoid( Visitor<void> *visitor, Nodep me);
    Nodep acceptNodep( Visitor<Nodep> *visitor, Nodep me);

    virtual ~String();
};

class Char : public Node
{
    char _value;
public:
    Char( const Char& src);
    Char( char src);

    virtual int type() const;
    static int staticType();

    virtual char value() const;
    virtual void setValue( char char_value);
    void acceptVoid( Visitor<void> *visitor, Nodep me);
    Nodep acceptNodep( Visitor<Nodep> *visitor, Nodep me);
    virtual ~Char();
};

class Vector : public Node
{
    std::vector<Nodep> _value;
public:
    Vector( const Vector& src);
    Vector( const std::vector<Nodep>& vector_value);

    virtual int type() const;
    static int staticType();

    virtual std::vector<Nodep>& value();
    virtual const std::vector<Nodep>& value() const;
    virtual void setValue( const std::vector<Nodep>& vector_value);
    void acceptVoid( Visitor<void> *visitor, Nodep me);
    Nodep acceptNodep( Visitor<Nodep> *visitor, Nodep me);

    virtual ~Vector();
};

template <class T>
class Visitor
{
public:
    virtual T visitNil( Nodep _nil) = 0;
    virtual T visitCons( Nodep _cons) = 0;
    virtual T visitNumber( Nodep _number) = 0;
    virtual T visitString( Nodep _string) = 0;
    virtual T visitChar( Nodep _char) = 0;
    virtual T visitVector( Nodep _vector) = 0;
    virtual T visitIdent( Nodep _ident) = 0;
};

class DumpVisitor : public Visitor<void>
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
    if ( ptr->type() == T::staticType())
        return dynamic_cast<T*>( ptr.get());
    else
        throw std::bad_cast();
}
}
}
