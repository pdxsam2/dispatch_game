#include"hash_table.h"

int main()
{
	char id[SIZE];
	char func_index= '0';
	cout<<"Enter an ID for your user: \n";
	cin>> id;
	cin.ignore(100, newl);
	
	user test(id);
	test.print();
	move_sel(func_index);
	
	while(func_index != '0')
	{
		if(!test.new_move(func_index)) cout<<"Error: you did not enter a valid input\n";
		test.print();
		move_sel(func_index);
	}

	test.display();

	return 0;
}

void move_sel(char & index)
{
	cout<<"Which direction would you like your user to move?\n";
	cout<<"Up - w\n";
	cout<<"Down - s\n";
	cout<<"Left- a\n";
	cout<<"Right- d\n";
	cout<<"Quit- 0\n";
	cin>> index;
	cin.ignore(MAX, newl);
}

