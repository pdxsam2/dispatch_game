#include"user.h"
//default constructor
user::user()
{
	id= NULL;
	x= 0;
	y= 0;
}

//constructor
user::user(char * name)
{
	id= new char[strlen(name)+1];
	strcpy(name,id);
	x= 0;
	y= 0;
}

//listen function that will call the functions from the function dispatch table 
void user::listen()
{
}

//prints the coordinates of the user
void user::print()
{
	cout<< "(x,y)= \t" << "(" << x << "," << y << ")\n";
}

//moves to change the coordinates of the user
void user::up()
{
	++y;
}
void user::down() 
{
	--y;
}	
void user::left() 
{
	--x;
}
void user::right() 
{
	++x;
}

//
//
//list of previous moves made by this user
list::list()
{
	head= NULL;
	tail= NULL;
}

//inserts a new move into the list
void list::insert(user::functype * new_move)
{
	if(!head)
	{
		head= new node;
		head->data= new_move;
		tail= head;
	}
	else if(!head->next)
	{
		head->next= new node;
		tail->data= new_move;
		tail= head->next;
	}
	else
	{
		tail->next= new node;
		tail= tail->next;
		tail->data= new_move;
	}
}

//displays the moves that have been made
void list::display()
{
	if(!head) return;
	char * moves= "Moves: ";
	user * ct_dummy= new user(moves);
	display(head, ct_dummy);
	delete ct_dummy;
}

void list::display(list::node * current, user * ct_dummy)
{
	if(!current) return;	//this line doesn't work yet because you're not passsing the node by reference anymore

	//this section checks which function is inside the node and then calls it on the dummy
	user::functype * func= current->data;
	int index = 0;

	for(int i= 0; i < 4; ++i)
	{
		if(&*func == &ct_dummy->fdt[i])
		{
			index= i;
		}
	}
	
	ct_dummy->fdt[index];
	ct_dummy->print();
}





