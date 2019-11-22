#include"user.h"
//default constructor
user::user()
{
	id= NULL;
	//fdt[4]= {&user::up,&user::down,&user::left,&user::right};
	x= 0;
	y= 0;
	moves= new list;
}

//constructor
user::user(char * name)
{
	id= new char[strlen(name)+1];
	strcpy(id,name);
	//fdt[4]= {&user::up,&user::down,&user::left,&user::right};
	x= 0;
	y= 0;
	moves= new list;
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
		moves->insert(&fdt[0]);
		(this->*fdt[0])();
		return 1;
	}
	if(move == 's')
	{
		moves->insert(&fdt[1]);
		(this->*fdt[1])();
		return 1;
	}
	if(move == 'a')
	{
		moves->insert(&fdt[2]);
		(this->*fdt[2])();
		return 1;
	}
	if(move == 'd')
	{
		moves->insert(&fdt[3]);
		(this->*fdt[3])();
		return 1;
	}

	else return 0;
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

//inserts a new move into the list
void list::insert(user::functype * new_move)
{
	if(!head)
	{
		head= new node;
		head->data= new_move;
		tail= head;
	}
	else if(!head->next)
	{
		head->next= new node;
		tail->data= new_move;
		tail= head->next;
	}
	else
	{
		tail->next= new node;
		tail= tail->next;
		tail->data= new_move;
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
	user::functype * func= current->data;
	int index = 0;

	for(int i= 0; i < 4; ++i)
	{
		if(&*func == &ct_dummy->fdt[i])
		{
			index= i;
		}
	}

	//calls the necessary function, prints the new coordinates
	(ct_dummy->*fdt[index])();
	ct_dummy->print();

	if(!current->next) return;	
	display(current->next, ct_dummy);
}
