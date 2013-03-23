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
    using parser::ast::Symbol;
    using parser::ast::SymbolIdType;

    class Activation : public std::map<SymbolIdType, Nodep>
    {
    public:
        Activation( Activation* parent);
        Nodep get( SymbolIdType symbol_id);
        void add( Symbol& symbol, Nodep& ptr);
        Activation* getParentPtr();
        
        ~Activation();

    private:
        boost::shared_ptr<Activation> parent_activation_ptr;
    };
}
