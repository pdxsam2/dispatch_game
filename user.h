#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

//Samuel Parker, 10/2019
//Personal Project

//constants
const char SIZE= 21;

//this object contains a user's name and coordinates	//ADJUST THIS
class user
{
	public: 
	user();
	user(char *);
	void listen();
	//~user();

	//functions for coordinate alteration
	typedef (user::*functype)(void);
	void up();
	void down();
	void left();
	void right();
	functype fdt[4]= {&user::up,&user::down,&user::left,&user::right};

	private: 
	//user status/info
	class list moves;
	char * id;
	int x;
	int y;
	
};

//this is a list used to store previous movements performed by a user
class list
{
	public:
	private:

};
