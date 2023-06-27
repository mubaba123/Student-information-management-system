#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "string.h"
#include "windows.h"
#include "Menu.h"
#include "KeyDown.h"
#include "MyList.h"

int main()
{	
	aaa();
	regist();
	dl();
	system("cls");
	while(1)
	{
		Menu();
		KeyDown();
		//system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}

