#include"list.h"
//default constructor
user::user()
{
	this -> id = NULL;
	this -> x = 0;
	this -> y = 0;
	this -> moves = NULL;
}

//constructor
user::user(char * name)
{
	this -> id = new char[strlen(name) + 1];
	strcpy(id,name);
	this -> x = 0;
	this -> y = 0;
	this -> moves = NULL;
}

//destructor 
user::~user()
{
	delete[] this -> id;
	delete this -> moves;
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
		if(!this -> moves) this -> moves = new list;
		this -> moves -> insert(&fdt[0]);
		(this ->*fdt[0])();
		return 1;
	}
	if(move == 's')
	{
		if(!this -> moves) this -> moves = new list;
		this -> moves -> insert(&fdt[1]);
		(this ->* fdt[1])();
		return 1;
	}
	if(move == 'a')
	{
		if(!this -> moves) this -> moves = new list;
		this -> moves -> insert(&fdt[2]);
		(this ->* fdt[2])();
		return 1;
	}
	if(move == 'd')
	{
		if(!this -> moves) this -> moves = new list;
		this -> moves -> insert(&fdt[3]);
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
	store = new char[strlen(this -> id)+1];
	strcpy(store, this -> id);
}

//checks which function has been called (used to call a function pointer in a node)
int user::func_check(user::functype * to_check)
{
	if(*to_check == this -> fdt[0])
		return 0;
	if(*to_check == this -> fdt[1])
		return 1;
	if(*to_check == this -> fdt[2])
		return 2;
	if(*to_check == this -> fdt[3])
		return 3;
	else return -1;
}

//displays the recent moves, really just a level of abstraction between the user and the list
void user::display()
{
	cout<<"User " << this->id << "'s recent moves\n";
	this -> moves -> display();
}

//moves to change the coordinates of the user
void user::up()
{
	++ this -> y;
}

void user::down() 
{
	-- this -> y;
}

void user::left() 
{
	-- this -> x;
}

void user::right() 
{
	++ this -> x;
}