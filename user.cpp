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
}


