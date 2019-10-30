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
	void print();
	//~user();

	//functions for coordinate alteration
	typedef void (user::*functype)(void);
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
