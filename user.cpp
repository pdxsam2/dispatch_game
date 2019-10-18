#include"user.h"

user::user()
{
	id= NULL;
	x= 0;
	y= 0;
	fdt[0]= &user::up;
}
user::user(char * name)
{
	id= new char[strlen(name)+1];
	strcpy(name,id);
	x= 0;
	y= 0;
	//fdt[]= {up,down,left,right};
}
void up(user & player)
{
}
void down(user & player) {}
void left(user & player) {}
void right(user & player) {}

