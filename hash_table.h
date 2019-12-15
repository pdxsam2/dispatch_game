#include"user.h"

//Samuel Parker, 10/2019

//this is the hash table data structure used for the following: 	
	//stores users based on an ID that is set by the user

class table
{
	public: 
	table();
	table(int);
	//~table();
	void insert(user &);
	void display();


	private:
	int hash(char *);	

	int size;
	struct node
	{
		user * data;
		node * next;
	};
	node ** d_base;
	

};

