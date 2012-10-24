/**
 *@file:lowering_exception.hpp
 *Exceptions of lowering
 */
 /*
  * Copyright(C) 2012 MIPT Scheme compiler team
  */
#include<string>
#include"frontend_exception.hpp"

namespace lowering
{
    class Exception : public FrontendException
    {
    public:
        std::string prettyMessage();
    };
}

