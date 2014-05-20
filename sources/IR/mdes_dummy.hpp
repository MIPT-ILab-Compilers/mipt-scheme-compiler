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
	OperDes( const char *, int, int);
};
	
class MDES
{
private:
	static OperDes des[OPERS_NUM];
public:
	static OperDes* getOperDes( OperName);
	static int numArgsInOperName( OperName);
	static int numRessInOperName( OperName);
	static char* getOperNameString( OperName);
};

