#include "ir_iface.hpp"

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
int MDES::numArgsInOperName( OperName op)
{
	OperDes *des = MDES::getOperDes( op);
	return des->num_args;
};

/** Return the number of results */
int MDES::numRessInOperName( OperName op)
{
	OperDes *des = MDES::getOperDes( op);
	return des->num_res;
};

/** Return the name of function */
char* MDES::getOperNameString( OperName op)
{
	OperDes *des = MDES::getOperDes( op);
	return des->name;
};

/** Initialization the array of objects **/
OperDes MDES::des[OPERS_NUM] = { OperDes( "MOV", 1 , 1), OperDes( "ADD", 2, 1), OperDes( "SUB", 2, 1), OperDes( "MUL", 2, 1)}; 
