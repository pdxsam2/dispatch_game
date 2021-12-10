#include"hash_table.h"

/*
This file is the implementation for the hash table that stores users
constructors
*/
table::table()
{
	this -> size = 100;
	this -> d_base = new node * [size];

	for(int i = 0; i < size; ++ i)
	{
		this -> d_base[i] = NULL;
	}
}

//constructor specified size of table by client 
table::table(int new_size)
{
	this -> size = new_size;
	this-> d_base = new node * [size];

	for(int i = 0; i < size; ++ i)
	{
		this -> d_base[i] = NULL;
	}
}

//destructor 
table::~table()
{
	for(int i = 0; i < this -> size; ++ i)
	{
		this -> remove_list(d_base[i]);
	}
	delete[] this -> d_base;
}

//hash function that uses the average ascii value of the user's ID to create an integer
int table::hash(char * ID)
{
	int sum = 0;
	int i = 0;
	int len = strlen(ID);

	while(i < len)
	{
		sum += ID[i];
		++ i;
	}
	return (sum / i) % this -> size;
	
}

//insets a user into the table
void table::insert(user & new_user)
{
	char * ID = NULL;
	new_user.get_id(ID);
	int index = hash(ID);

	node * temp = new node;
	temp -> data = & new_user;
	temp -> next = NULL;

	if(!this -> d_base[index]) 
	{
		this -> d_base[index] = temp;
	}
	else
	{
		node * current = this -> d_base[index];
		while(current -> next)
		{
			current = current -> next;
		}
		current -> next = temp;
	}
	delete[] ID;
}

//displays all of the table
void table::display()
{
	node * current;
	for(int i= 0;i < this -> size; ++ i)
	{
		current = this -> d_base[i];
		if(current)
		{
			current -> data -> display_moves();
			while(current -> next)
			{
				current -> data -> display_moves();
				current = current -> next;
			}
		}
	}
}

//removes a list of the nodes containing users
void table::remove_list(node * current)
{
	if(!current) return;
	this -> remove_list(current -> next);
	delete current -> data;
	delete current;
}
