 /**
* @file:constant.hpp
* Header of class Constant.
*/
/**
* Copyright 2012 MIPT-COMPILER team
*/

#pragma once

#include <boost/variant/get.hpp>
#include <boost/variant/variant.hpp>
#include <string>

/*
 type of stored constant may be int, float, double, std::string, char *
 only this type can be given as a template of method getValue of class Constant. 
*/

namespace ir
{

class Constant
{
	public:
		Constant(const std::string &str) : value(str) {}
		Constant(int val) : value(val) {}
		Constant(double val) : value(val) {}

		bool isDouble();
		bool isInt();
		bool isString();

		template <typename T>
		T getValue() {
			return boost::get<T>(value);
		}

	private:
		boost::variant<float, double, int, std::string> value;
};

}//namespace ir
