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
void user::print_coordinate()
{
	cout<< "(x,y)= \t" << "(" << x << "," << y << ")\n";
}

//gets and applys the new move
void user::new_move(char move)
{
	int move_index = get_move_index(move);
	apply_move(move_index);
}

//returns the index of the move char in an array
int user::get_move_index(char move)
{
	char move_list[4] = {'w', 's', 'a', 'd'};
	
	for (int i = 0; i < 4; i++)
	{
		if(move_list[i] == move)
		{
			return i;
		}
	}
	throw INVALID_FUNC;
}

//sends the address of the function into list
void user::apply_move(int move_index)
{
	if(!this -> moves) this -> moves = new list;
		this -> moves -> insert(&fdt[move_index]);
		(this ->*fdt[move_index])();
}

//calls a move function on "this"
void user::new_move(int move)
{
	if(move < 0 || move > 3) throw INVALID_FUNC;
	(this ->* fdt[move])();
}

//stores the id of the current user into a string (expected to be used by the hash table)
void user::get_id(char * & store)
{
	delete [] store;
	store = new char[strlen(this -> id)+1];
	strcpy(store, this -> id);
}

//checks which function has been called (used to call a function pointer in a node)
int user::function_check(user::function_type * to_check)
{
	if(*to_check == this -> fdt[0])
		return 0;
	if(*to_check == this -> fdt[1])
		return 1;
	if(*to_check == this -> fdt[2])
		return 2;
	if(*to_check == this -> fdt[3])
		return 3;
	throw INVALID_FUNC; 
}

//displays the recent moves, really just a level of abstraction between the user and the list
void user::display_moves()
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