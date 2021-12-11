#include"list.h"
//list of previous moves made by this user
list::list()
{
	this -> head = NULL;
	this -> tail = NULL;
}

//destructor
list::~list()
{
	this -> remove_all(head);
	this -> head = NULL;
	this -> tail = NULL;
}

//inserts a new move into the list
void list::insert(user::function_type * new_move)
{
	if(!this -> head)
	{
		this -> head = new node;
		this -> head -> data = new_move;
		this -> head -> next = NULL;
		this -> tail = head;
	}
	else
	{
		this -> tail -> next = new node;
		this -> tail = this -> tail -> next;
		this -> tail -> data = new_move;
		this -> tail -> next = NULL;
	}
}

//displays the moves that have been made
void list::display()
{
	if(!this -> head) return;
	char * moves= "Moves: ";
	user * ct_dummy= new user(moves);
	this -> display(head, ct_dummy);
	delete ct_dummy;
}

void list::display(list::node * current, user * ct_dummy)
{

	//this section checks which function is inside the node and then calls it on the dummy
	if(!current) return;

	user::function_type * func = current -> data;
	int index = ct_dummy -> function_check(func);

	//calls the necessary function, prints the new coordinates
	ct_dummy -> new_move(index);
	ct_dummy -> print_coordinate();

	if(!current -> next) return;	
	this -> display(current -> next, ct_dummy);
}

//removes all the nodes, used by the destructor
void list::remove_all(node * current)
{
	if(!current) return;
	this -> remove_all(current -> next);
	delete current;
}