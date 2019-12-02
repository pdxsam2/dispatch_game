#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

//Samuel Parker, 10/2019
//Personal Project
//To - do
	//try - catch for exception handling in display function?
	//change insertion algorithm to add at the end !

//constants
const char SIZE= 21;
const char MAX= 100;
const char newl= '\n';

//this object contains a user's name, coordinates, and recent moves 
class user
{
	public: 
	user();
	user(char *);
	void print();
	int new_move(char);
	int new_move(int);
	void display();
	//~user();

	//functions for coordinate alteration
	typedef void (user::*functype)(void);
	functype fdt[4]= {&user::up,&user::down,&user::left,&user::right};
	int func_check(user::functype*);

	//static functype fdt[4];	//this line was me messing with different ways to create the array, see lines in constructors as well for statements related
	void up();
	void down();
	void left();
	void right();
	

	private: 
	//user status/info
	class list * moves;
	char * id;
	int x;
	int y;
	
};

//this is a list used to store previous movements performed by a user
class list
{
	public:
	list();
	//~list();
	void insert(user::functype * );
	void display();

	private:
	struct node
	{
		user::functype * data;
		node * next;
	} *head, *tail;

	void display(node *, user *);
};


///GLOBAL PROTOTYPES
void move_sel(char&);
