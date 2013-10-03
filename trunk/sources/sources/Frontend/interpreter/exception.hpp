/**
 * @file:interpreter_exception.hpp
 * An exception representation of interpreter special situations.
 */
 /*
  * Copyright(C) 2012 MIPT Scheme compiler team
  */

#pragma once

#include <string>
#include "frontend_exception.hpp"

namespace interpreter
{

class Exception :public FrontendException
{
public:
    Exception( std::string msg)
        :FrontendException( msg) {}
    ~Exception() throw() {}
};

}
