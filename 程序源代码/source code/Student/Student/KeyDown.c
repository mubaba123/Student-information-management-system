#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "MyList.h"

//夏彤负责
void KeyDown()
{
	int choice = 0;
	scanf("%d", &choice);//在键盘上输入数据，1，2，3，4......
	switch (choice)//判断
	{
	case 0:
		printf("正常退出\n");
		system("pause");//暂停页面
		exit(0);//退出系统，正常退出
		break;
	case 1:
		printf("\n");
		system("cls");//清屏
		printf("*************************************************\n");
		printf("       欢迎进入录入学生信息界面        \n");
		printf("*************************************************\n");
		InputStudent();//录入学生信息的函数
		break;
	case 2:
		printf("           打印学生信息                \n");
		PrintStudent();//打印学生信息的函数
		break;
	case 3:
		system("cls");
		printf("*************************************************\n");
		printf("           保存学生信息                \n");
		printf("*************************************************\n");
		Save_Student();//保存学生信息的函数
		break;
	case 4:
		system("cls");
		printf("*************************************************\n");
		printf("           读取学生信息                \n");
		printf("*************************************************\n");
		ReadStudent();//读取学生信息的函数
		break;
	case 5:
		system("cls");
		printf("*********************************************************************************\n");
		printf("           统计所有学生人数为%d                \n", CountStudent());//因为CountStudent返回的是int类型的数据	
		printf("*********************************************************************************\n");
		system("pause"); system("cls");
		break;
	case 6:
		system("cls");
		printf("*************************************************************\n");
		printf("               查找学生信息（根据学号或着姓名）                \n");
		printf("*************************************************************\n");
		FindStudent();//查找学生信息的函数
		break;
	
	case 7:
		system("cls");
		printf("*************************************************************\n");
		printf("           修改学生信息               \n");
		printf("*************************************************************\n");
		ModifyStudent();//修改学生信息的函数
		break;
	case 8:
		system("cls");
		printf("*************************************************************\n");
		printf("           删除学生信息                \n\n");
		printf("*************************************************************\n");
		DeleteStudent();//删除学生信息的函数
		break;
	case 9:
		system("cls");
		printf("\t\t\t                  欢迎使用系统帮助！\t\t\t           \n\n");
		help();//提示信息函数
		system("pause"); system("cls");
		break;
	default:
		printf("           选择错误，请重新输入                \n\n");
		system("pause");
		break;
	}
}