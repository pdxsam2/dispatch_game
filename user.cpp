#include"user.h"
//default constructor
user::user()
{
	id= NULL;
	x= 0;
	y= 0;
	moves= NULL;
}

//constructor
user::user(char * name)
{
	id= new char[strlen(name)+1];
	strcpy(id,name);
	x= 0;
	y= 0;
	moves= NULL;
}
//destructor 
user::~user()
{
	delete[] id;
	delete moves;
}
//prints the coordinates of the user
void user::print()
{
	cout<< "(x,y)= \t" << "(" << x << "," << y << ")\n";
}

//changes a character into an index and then sends the address of the function into list
int user::new_move(char move)
{
	if(move == 'w') 
	{
		if(!moves) moves= new list;
		moves->insert(&fdt[0]);
		(this->*fdt[0])();
		return 1;
	}
	if(move == 's')
	{
		if(!moves) moves= new list;
		moves->insert(&fdt[1]);
		(this->*fdt[1])();
		return 1;
	}
	if(move == 'a')
	{
		if(!moves) moves= new list;
		moves->insert(&fdt[2]);
		(this->*fdt[2])();
		return 1;
	}
	if(move == 'd')
	{
		if(!moves) moves= new list;
		moves->insert(&fdt[3]);
		(this->*fdt[3])();
		return 1;
	}

	else return 0;
}
//calls a move function on "this"
int user::new_move(int move)
{
	if(move > -1 || move < 4)
	{
		(this->*fdt[move])();
		return 1;
	}
	return 0;
}
//stores the id of the current user into a string (expected to be used by the hash table)
void user::get_id(char * & store)
{
	delete [] store;
	store= new char[strlen(id)+1];
	strcpy(store, id);
}
//checks which function has been called (used to call a function pointer in a node)
int user::func_check(user::functype * to_check)
{
	if(*to_check == fdt[0])
		return 0;
	if(*to_check == fdt[1])
		return 1;
	if(*to_check == fdt[2])
		return 2;
	if(*to_check == fdt[3])
		return 3;
	else return -1;
}
//displays the recent moves, really just a level of abstraction between the user and the list
void user::display()
{
	cout<<"User " << this->id << "'s recent moves\n";
	moves->display();
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

//destructor
list::~list()
{
	remove_all(head);
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
		head->next= NULL;
		tail= head;
	}
	else
	{
		tail->next= new node;
		tail= tail->next;
		tail->data= new_move;
		tail->next= NULL;
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
	user::functype * func= current->data;
	int index = ct_dummy->func_check(func);
	if(index < 0) return;


	

	//calls the necessary function, prints the new coordinates
	ct_dummy->new_move(index);
	ct_dummy->print();

	if(!current->next) return;	
	display(current->next, ct_dummy);
}

//removes all the nodes, used by the destructor
void list::remove_all(node * current)
{
	if(!current) return;
	remove_all(current->next);
	delete current;
}
