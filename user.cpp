#include"list.h"
//default constructor
user::user()
{
	id = NULL;
	x = 0;
	y = 0;
	moves = NULL;
}

//constructor
user::user(char * name)
{
	id = new char[strlen(name) + 1];
	strcpy(id,name);
	x = 0;
	y = 0;
	moves = NULL;
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
		if(!moves) moves = new list;
		moves -> insert(&fdt[0]);
		(this ->*fdt[0])();
		return 1;
	}
	if(move == 's')
	{
		if(!moves) moves = new list;
		moves -> insert(&fdt[1]);
		(this ->* fdt[1])();
		return 1;
	}
	if(move == 'a')
	{
		if(!moves) moves = new list;
		moves -> insert(&fdt[2]);
		(this ->* fdt[2])();
		return 1;
	}
	if(move == 'd')
	{
		if(!moves) moves = new list;
		moves -> insert(&fdt[3]);
		(this ->* fdt[3])();
		return 1;
	}

	else return 0;
}

//calls a move function on "this"
int user::new_move(int move)
{
	if(move > - 1 || move < 4)
	{
		(this ->* fdt[move])();
		return 1;
	}
	return 0;
}

//stores the id of the current user into a string (expected to be used by the hash table)
void user::get_id(char * & store)
{
	delete [] store;
	store = new char[strlen(id)+1];
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
	moves -> display();
}

//moves to change the coordinates of the user
void user::up()
{
	++ y;
}

void user::down() 
{
	-- y;
}

void user::left() 
{
	-- x;
}

void user::right() 
{
	++ x;
}