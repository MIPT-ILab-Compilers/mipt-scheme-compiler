/**
 * @file: IR/mdes_dummy.hpp
 * Declaration of the machine description structure (dummy version)
 */
/*
 * Copyright 2013 MIPT-COMPILER team
 */

#pragma once
#include <string.h>

const UInt8 MAX_RESS_NUM = 1;
const UInt8 MAX_ARGS_NUM = 2;

/** Object type */
enum ObjName
{
    OBJ_NAME_REG,
    OBJ_NAMES_NUM
};

/** Operation name */
enum OperName
{
    OPER_MOV,
    OPER_ADD, 
    OPER_SUB,
    OPER_MUL,
    OPERS_NUM
};

class OperDes
{
public:	
	char *name;
	int num_args;
	int num_res; 
	//type arg_type[MAX];
	OperDes( const char *, int, int);
};
	
class MDES
{
private:
	static OperDes des[OPERS_NUM];
public:
	static OperDes* getOperDes( OperName);
	static int getOperArgs( OperName);
	static int getOperRes( OperName);
	static char* getOperName( OperName);
		// ....//
};

/** Initialization of the object **/
OperDes::OperDes( const char *name, int num_args, int num_res)
{
	int length;
	length = strlen( name) + 1;
	this->name = new char[length];
	strcpy( this->name, name);
	this->num_args = num_args;
	this->num_res = num_res;
};
 
OperDes* MDES::getOperDes( OperName name)
{
	return &des[name];
};

/** Return the number of arguments */
int MDES::getOperArgs( OperName op)
{
	OperDes *des = MDES::getOperDes( op);
	return des->num_args;
};

/** Return the number of results */
int MDES::getOperRes( OperName op)
{
	OperDes *des = MDES::getOperDes( op);
	return des->num_res;
};

/** Return the name of function */
char* MDES::getOperName( OperName op)
{
	OperDes *des = MDES::getOperDes( op);
	return des->name;
};
	
/** Initialization the array of objects **/
OperDes MDES::des[OPERS_NUM] = { OperDes( "MOV", 2 , 1), OperDes( "ADD", 2, 1), OperDes( "SUB", 2, 1), OperDes( "MUL", 2, 1)}; 
