#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "string.h"
#include "windows.h"
//定义变量
char reg_name[30] = "", reg_pwd[10] = "";
char on_name[30], on_pwd[10];


//用户注册系统
void regist()
{
    //清屏
    system("pause");
    system("cls");
    printf("\n\n\t\t\t欢迎使用注册系统\n\n");
    while (1)
    {
        //输入用户名
        printf("\t\t请输入用户名[不能大于10个字符]：");
        scanf("%s", reg_name);

        //判断用户名
        if (strlen(reg_name) <= 10)
        {
            while (1)
            {
                //输入密码
                printf("\n\t\t请输入密码[密码长度为八位]：");
                scanf("%s", reg_pwd);
                //strlen计算字符串的长度，直到空结束字符，但不包括空结束字符。
                //判断密码
                if (strlen(reg_pwd) == 8)
                {
                    printf("\n\n\t\t注册成功，您的用户名是%s,密码是%s\n\n", reg_name, reg_pwd);
                    break;
                }
                else
                {
                    printf("\n\t\t密码的长度为%d，请重新输入\n", strlen(reg_pwd));
                }
            }
            break;
        }
        else
        {
            printf("\n\t\t用户名的长度为%d，请重新输入\n\n", strlen(reg_name));
        }
    }
}

//判断是否注册
int judge()
{
    //strcmp，用于比较两个字符串
    if (strcmp(reg_name, "") == 0 && strcmp(reg_pwd, "") == 0)
    {
        printf("\n\n\t\t您尚未注册，请先注册！\n\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
void Menu()
{
    printf("*************************************************\n");
    printf("*\t欢迎使用学生信息管理系统V2.1\t\t*\n");
    printf("*\t\t请选择功能\t\t\t*\n");
    printf("*************************************************\n");
    printf("*\t\t1.录入学生信息\t\t\t*\n");
    printf("*\t\t2.打印学生信息\t\t\t*\n");
    printf("*\t\t3.保存学生信息\t\t\t*\n");
    printf("*\t\t4.读取学生信息\t\t\t*\n");
    printf("*\t\t5.统计所有学生人数\t\t*\n");
    printf("*\t\t6.查找学生信息\t\t\t*\n");
    printf("*\t\t7.修改学生信息\t\t\t*\n");
    printf("*\t\t8.删除学生信息\t\t\t*\n");
    printf("*\t\t9.系统使用方法以及注意事项\t*\t\t\n");
    printf("*\t\t0.退出系统\t\t\t*\n");
    printf("*************************************************\n");
    printf("*\t\t请在0~9中选择功能\t\t*\t\n");
    printf("*************************************************\n");
}

//用户登录
void dl()
{
    int i;
    system("pause");
    system("cls");

    printf("\n\n\t\t\t欢迎使用学生信息登录系统\n\n");
    //三次登录验证
    for (i = 1; i <= 3; i++)
    {
        printf("\t\t请输入用户名:");
        scanf("%s", on_name);
        printf("\n\t\t请输入密码:");
        scanf("%s", on_pwd);
        //strcmp，用于比较两个字符串
        if (strcmp(reg_name, on_name) == 0 && strcmp(reg_pwd, on_pwd) == 0)
        {
         /*   Menu();*/
            break;
        }
        else
        {
            printf("\n\n\t\t登录失败，请重新登录，您还有%d次机会\n\n", 3 - i);
        }

    }

}

void aaa()//学生信息注册登陆系统
{
    //定义变量
        int id;
        //输出界面
        printf("\n\n\t\t\t学生信息管理系统\n\n");

        printf("\t\t\t【1】注册\n");
        printf("\t\t\t【2】登录\n");
        printf("\t\t\t【0】退出\n\n");

        //输入功能编号
        printf("\t\t请选择功能编号：");
        scanf("%d", &id);

        //判断
        switch (id)
        {
        case 1:regist();//用户注册系统
            break;
        case 2:
            if (judge() == 1)//判断是否注册
            {
                dl();//用户登录
            }
            break;
        case 0:exit(1);//退出系统，非正常退出
            break;
        default:
            printf("\n\t\t您输入的功能编号有误，请重新输入！\n");
       }
}

