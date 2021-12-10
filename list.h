#include"user.h"

//this is a list used to store previous movements performed by a user
class list
{
	public:
	list();
	~list();
	void insert(user::function_type * );
	void display();

	private:
	struct node
	{
		user::function_type * data;
		node * next;
	} * head, * tail;

	void display(node *, user *);
	void remove_all(node *);
};