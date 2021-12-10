#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

/*
Samuel Parker, 10/2019
Personal Project
*/

//constants
const char SIZE = 21;
const char MAX = 100;
const char NEWL = '\n';

//this object contains a user's name, coordinates, and recent moves 
class user
{
	public: 
	user();
	user(char *);
	~user();
	void print();
	int new_move(char);
	int new_move(int);
	void display();
	void get_id(char * &);

	//functions for coordinate alteration
	typedef void (user::*functype)(void);
	functype fdt[4]= {&user::up,&user::down,&user::left,&user::right};
	int func_check(user::functype*);

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

///GLOBAL PROTOTYPES
void MOVE_SEL(char &);
