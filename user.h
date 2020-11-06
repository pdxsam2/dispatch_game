#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

//Samuel Parker, 10/2019

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

//this is a list used to store previous movements performed by a user
class list
{
	public:
	list();
	~list();
	void insert(user::functype * );
	void display();

	private:
	struct node
	{
		user::functype * data;
		node * next;
	} *head, *tail;

	void display(node *, user *);
	void remove_all(node *);
};


///GLOBAL PROTOTYPES
void move_sel(char&);
