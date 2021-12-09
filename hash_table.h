#include"user.h"

//Samuel Parker, 10/2019

/*
Hash-table
	- stores users via an ID
*/

class table
{
	public: 
	table();
	table(int);
	~table();
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

	void remove_list(node *);
	

};

