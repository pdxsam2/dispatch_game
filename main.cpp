#include"hash_table.h"

int main()
{
	table data_base(7);
	char id[SIZE];
	char func_index= '0';
	char check= 'y';
	user * test;

	while(check == 'y')
	{
		cout<<"Enter an ID for your user: \n";
		cin>> id;
		cin.ignore(100, newl);
		
		test= new user(id);
		data_base.insert(*test);
		move_sel(func_index);
		
		while(func_index != '0')
		{
			if(!test->new_move(func_index)) cout<<"Error: you did not enter a valid input\n";
			test->print();
			move_sel(func_index);
		}
		cout<<"\nWould you like to add another user?(y/n)\n";
		cin>> check;
		cin.ignore();
		test= NULL;
	}

	data_base.display();

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



