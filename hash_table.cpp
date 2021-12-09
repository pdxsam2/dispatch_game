#include"hash_table.h"

/*
This file is the implementation for the hash table that stores users
constructors
*/
table::table()
{
	this->size= 100;
	this->d_base= new node*[size];

	for(int i= 0; i <size; ++i)
	{
		d_base[i]= NULL;
	}
}
//constructor specified size of table by client 
table::table(int new_size)
{
	this->size= new_size;
	this->d_base= new node*[size];

	for(int i= 0; i <size; ++i)
	{
		d_base[i]= NULL;
	}
}

//destructor 
table::~table()
{
	for(int i= 0; i < size; ++i)
	{
		remove_list(d_base[i]);
	}
	delete[] d_base;
}

//hash function that uses the average ascii value of the user's ID to create an integer
int table::hash(char * ID)
{
	int sum= 0;
	int i= 0;
	int len= strlen(ID);

	while(i < len)
	{
		sum += ID[i];
		++i;
	}
	return (sum/i) % size;
	
}

//insets a user into the 
void table::insert(user & new_user)
{
	char * ID= NULL;
	new_user.get_id(ID);
	int index= hash(ID);

	node * temp= new node;
	temp->data= &new_user;
	temp->next= NULL;

	if(!d_base[index]) 
	{
		d_base[index]= temp;
	}
	else
	{
		node * current= d_base[index];
		while(current->next)
		{
			current= current->next;
		}
		current->next= temp;
	}
	delete[] ID;
}
//displays all of the table
void table::display()
{
	node * current;
	for(int i= 0;i <size; ++i)
	{
		current= d_base[i];
		if(current)
		{
			current->data->display();
			while(current->next)
			{
				current->data->display();
				current= current->next;
			}
		}
	}
}

//removes a list of the nodes containing users
void table::remove_list(node * current)
{
	if(!current) return;
	remove_list(current->next);
	delete current->data;
	delete current;
}
