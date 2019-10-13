#include"user.h"

user::user()
{
	id= NULL;
	x= 0;
	y= 0;
}
user::user(char * name)
{
	id= new char[strlen(name)+1];
	strcpy(name,id);
	x= 0;
	y= 0;
}
