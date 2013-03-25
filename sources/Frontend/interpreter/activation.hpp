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

    class Activation : public std::map<IdentIdType, Nodep>
    {
    public:
        Activation( Activation* parent);
        Nodep get( IdentIdType _id);
        void add( Ident& ident, Nodep& ptr);
        Activation* getParentPtr();
        
        ~Activation();

    private:
        boost::shared_ptr<Activation> parent_activation_ptr;
    };
}
