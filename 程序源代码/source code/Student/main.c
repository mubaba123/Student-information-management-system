#include<stdio.h>
#include<stdlib.h>
#include "Menu.h" 
#include "KeyDown.h" 

	

int main()
{	
	while(1)
	{
		menu();
		KeyDown();
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
