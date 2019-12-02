#include"hash_table.h"

//
//
//This file is the implementation for the hash table that stores users
//constructors
table::table()
{
	this->size= 100;
	this->d_base= new user*[size];

	for(int i= 0; i <size; ++i)
	{
		d_base[i]= NULL;
	}
}
//specified size of table by client 
table::table(int new_size)
{
	this->size= new_size;
	this->d_base= new user*[size];

	for(int i= 0; i <size; ++i)
	{
		d_base[i]= NULL;
	}
}


//insets a user into the 

