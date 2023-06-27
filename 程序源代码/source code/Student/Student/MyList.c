#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <conio.h>//getch用的
#include <stdlib.h>
#include <string.h>

//定义一个学生
typedef struct _Student
{
	char name[20];//姓名	
	int  age;//年龄
	int stuNum;//学号
	int score;//成绩
}Student;
//Student stu= { .name[20] = "mjm",.age = 0,.stuNum=0,.score=0};



//节点,存信息
typedef struct _Node
{
	Student stu;//学生,理解成data域
	struct _Node* pNext;//指向下一个节点的指针
}Node;


Node* g_pHead = NULL;     //定义一个头结点

//录入学生信息
void InputStudent()
{
	//创建一个新节点
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext =NULL;
	//头插法
	if (g_pHead == NULL)
	{
		g_pHead = pNewNode;
	}
	else
	{
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}
	
	printf("请输入学生姓名：\n");
	scanf("%s", pNewNode->stu.name);
	printf("请输入学生的年龄：\n");
	scanf("%d", &pNewNode->stu.age);
	printf("请输入学生的学号：\n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("请输入学生的成绩：\n");
	scanf("%d", &pNewNode->stu.score);
	printf("学生信息录入成功！！！\n");
	system("pause");
	system("cls");
}
//打印学生信息
void PrintStudent()
{
	system("cls");
	printf("*********************************************************************************\n");
	printf("*\t\t\t欢迎使用打印学生信息功能\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("*\t学号\t*\t姓名\t*\t年龄\t*\t成绩\t\t*\n");
	printf("*********************************************************************************\n");
	//遍历链表
	Node* p = g_pHead;
	while (p != NULL)
	{
		printf("*\t%d\t*\t%s\t*\t%d\t*\t%d\t\t*\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
		printf("*********************************************************************************\n");
		p = p->pNext;
	}
	system("pause");
}

//保存学生信息
void Save_Student()
{
	//先打开文件
	FILE* fp=fopen("text.txt","w");//打开一个文本文件，允许写入，如果没有，就创建一个
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	//遍历链表
	Node* p = g_pHead;
	while (p != NULL)
	{
		
		//fwrite(&p->stu,sizeof(Student), 1 , fp);//每次写一个字节，总共写Stuent这个大小，写fp遍
		fprintf(fp, "%s %d %d %d\n", p->stu.name, p->stu.stuNum, p->stu.age, p->stu.score);
		p = p->pNext;
	}
	//关闭文件
	fclose(fp);
	printf("           *****************************      \n");
	printf("                   数据保存成功                  \n");
	printf("*************************************************\n");
	system("pause");
	system("cls");
}


//读取学生信息
void ReadStudent()
{
	//打开文件
	FILE *fp=fopen("text.txt", "r");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		system("pause");
		return;
	}
	//读文件
	Student stu[200];
	while (fread(&stu, 1, sizeof(Student), fp))//判断它是否读到文件末尾
	{
		//创建一个新节点
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;
		memcpy(pNewNode, &stu, sizeof(Student));//复制一个Stuednt大小的，复制的是stu里的东西
		//头插法
		if (g_pHead == NULL)
		{
			g_pHead = pNewNode;
		}
		else
		{
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;
		}
	//关闭文件
		fclose(fp);
		printf("           *****************************      \n");
		printf("                  读取数据成功                    \n");
		printf("*************************************************\n");
		system("pause");
		system("cls");
	}
}
//统计所有学生人数
int CountStudent()
{
	int nCount = 0;//学生总数

	//遍历
	Node* p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;
	}
	return nCount;
}

//查找学生
void FindStudent()
{
	int nStuNum;
	char szName[20];
	printf("*************************************************************\n");
	printf("              请输入要查找的学生的学号：                 ");
	scanf("%d", &nStuNum);
	printf("*************************************************************\n");
	printf("*************************************************************\n");
	printf("              请输入要查找的学生的姓名：                 ");
	scanf("%s", &szName);
	printf("*************************************************************\n");
	
	//顺序查找
	Node* p = g_pHead;
	while (p != NULL)
	{	//strcmp字符串比较函数
		if (p->stu.stuNum == nStuNum || strcmp(p->stu.name, szName)==0)
		{
			printf("*************************************************\n");
			printf("                     查找成功                          \n");
			printf("*************************************************\n");
			printf("学号:%d 姓名:%s 年龄:%d 成绩:%d\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
			printf("*************************************************\n");
		p = p->pNext;
		}
		else
			printf("没有找到该学生信息\n"); system("pause"); return;
	}	
		system("cls");
}

//修改学生信息
void ModifyStudent()
{
	int nStuNum;
	printf("\n");
	printf("             请输入需要修改的学生信息的学号：   ");
	scanf("%d", &nStuNum);
	printf("*************************************************************\n");
	

	Node* p = g_pHead;
	while (p != NULL)
	{
		////strcmp字符串比较函数
		if (p->stu.stuNum == nStuNum)
		{
			printf("请输入要修改的学生的    姓名,    年龄,    成绩：\n");
			scanf("%s %d %d", p->stu.name, &p->stu.age, &p->stu.score);
			printf("*************************************************************\n");
			printf("                   修改成功                                   \n");
			printf("*************************************************************\n");
			break;
		}
		p = p->pNext;
	}
	if (p == NULL)
	{
		printf("没有找到该学生信息。\n");
	}
	system("pause");//暂停
	system("cls");//清屏
}
//删除学生信息
void DeleteStudent()
{
	int nStuNum;
	printf("*************************************************************\n");
	printf("               请输入要删除的学生的学号：");
	scanf("%d",&nStuNum);
	printf("*************************************************************\n");
	Node* p1,*p2;
	//判断是不是头节点
	if (g_pHead->stu.stuNum == nStuNum)
	{
		p1=g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		printf("               已成功删除该学生信息               \n");
		system("pause");//暂停
		system("cls");//清屏
		return;
	}
	//不是头节点
	Node* p = g_pHead;
	while (p->pNext != NULL)
	{
		if (p->pNext->stu.stuNum == nStuNum)
		{
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			free(p2);
			printf("已成功删除该学生信息\n");
			system("pause");//暂停
			system("cls");//清屏
			return;
		}
		p = p->pNext;

		if (p->pNext == NULL)
		{
			break;
		}
	}
	if (p->pNext == NULL)
	{
		printf("没有找到该学员。\n");
	}
	system("pause");//暂停
	system("cls");//清屏
}
//帮助系统
void help()
{
		printf("\t╭ ⺌ % ╮  ╭ ⺌ % ╮  *\t\t1.欢迎使用系统帮助！\t\t\t              *  ╭ ```╮    ╭ ```╮\n\n");
		printf("\t (@^o^@)   (@^o^@)  *\t\t2.初次进入系统后,请先选择录入学生信息\t\t\t      *  (⌒:⌒)   (⌒:⌒)\n");
		printf("\t (~):(~)   (~):(~)  *\t\t3.按照菜单提示键入数字代号\t\t\t              *  (~)v(~)   (~)v(~)\n");
		printf("\t (~):(~)   (~):(~)  *\t\t4.增加学生信息后,切记保存\t\t\t               *  (~)v(~)   (~)v(~)\n");
		printf("\t (~):(~)   (~):(~)  *\t\t5.谢谢您的使用！\t\t\t               *  (~)v(~)   (~)v(~)\n");
}