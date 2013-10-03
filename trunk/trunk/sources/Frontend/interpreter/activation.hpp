/**
 * @file:activation.hpp
 * Activation class.
 */
/**
 * Copyright 2012 MIPT-COMPILER team
 */

#pragma once

#include "../parser/ast.hpp"
#include <map>
#include <boost/shared_ptr.hpp>

namespace interpreter
{
using parser::ast::Nodep;
using parser::ast::Ident;
using parser::ast::IdentIdType;
    
class Activation;
typedef boost::shared_ptr<Activation> ActPtr;

class Activation : public std::map<IdentIdType, Nodep>
{
public:
    Activation( ActPtr parent);
    Activation();
    Nodep get( IdentIdType _id);
    void add( Ident& ident, Nodep& ptr);
    ActPtr getParentPtr();
    bool hasParent();
        
    ~Activation();

private:
    ActPtr parent_activation_ptr;
};
}
