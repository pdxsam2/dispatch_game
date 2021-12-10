#include"list.h"
//list of previous moves made by this user
list::list()
{
	head = NULL;
	tail = NULL;
}

//destructor
list::~list()
{
	remove_all(head);
	head = NULL;
	tail = NULL;
}

//inserts a new move into the list
void list::insert(user::functype * new_move)
{
	if(!head)
	{
		head = new node;
		head -> data = new_move;
		head -> next = NULL;
		tail = head;
	}
	else
	{
		tail -> next = new node;
		tail = tail -> next;
		tail -> data = new_move;
		tail -> next = NULL;
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

	//this section checks which function is inside the node and then calls it on the dummy
	if(!current) return;
	user::functype * func = current -> data;
	int index = ct_dummy -> func_check(func);
	if(index < 0) return;

	//calls the necessary function, prints the new coordinates
	ct_dummy -> new_move(index);
	ct_dummy -> print();

	if(!current -> next) return;	
	display(current -> next, ct_dummy);
}

//removes all the nodes, used by the destructor
void list::remove_all(node * current)
{
	if(!current) return;
	remove_all(current -> next);
	delete current;
}
