#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

//Samuel Parker, 10/2019
//Personal Project

//constants
const char SIZE= 21;

//this array stores the available functions for a user 
typedef void (*functype)();

//this object contains a user's name and coordinates
class user
{
	public: 
	user();
	user(char *);
	void listen();
	//~user();

	private: 
	//functions for coordinate alteration
	void up();
	void down();
	void left();
	void right();
	static functype fdt[]= {&up, &down, &left, &right};

	//user status/info
	char * id;
	int x;
	int y;
	
};
