#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "MyList.h"

//��ͮ����
void KeyDown()
{
	int choice = 0;
	scanf("%d", &choice);//�ڼ������������ݣ�1��2��3��4......
	switch (choice)//�ж�
	{
	case 0:
		printf("�����˳�\n");
		system("pause");//��ͣҳ��
		exit(0);//�˳�ϵͳ�������˳�
		break;
	case 1:
		printf("\n");
		system("cls");//����
		printf("*************************************************\n");
		printf("       ��ӭ����¼��ѧ����Ϣ����        \n");
		printf("*************************************************\n");
		InputStudent();//¼��ѧ����Ϣ�ĺ���
		break;
	case 2:
		printf("           ��ӡѧ����Ϣ                \n");
		PrintStudent();//��ӡѧ����Ϣ�ĺ���
		break;
	case 3:
		system("cls");
		printf("*************************************************\n");
		printf("           ����ѧ����Ϣ                \n");
		printf("*************************************************\n");
		Save_Student();//����ѧ����Ϣ�ĺ���
		break;
	case 4:
		system("cls");
		printf("*************************************************\n");
		printf("           ��ȡѧ����Ϣ                \n");
		printf("*************************************************\n");
		ReadStudent();//��ȡѧ����Ϣ�ĺ���
		break;
	case 5:
		system("cls");
		printf("*********************************************************************************\n");
		printf("           ͳ������ѧ������Ϊ%d                \n", CountStudent());//��ΪCountStudent���ص���int���͵�����	
		printf("*********************************************************************************\n");
		system("pause"); system("cls");
		break;
	case 6:
		system("cls");
		printf("*************************************************************\n");
		printf("               ����ѧ����Ϣ������ѧ�Ż���������                \n");
		printf("*************************************************************\n");
		FindStudent();//����ѧ����Ϣ�ĺ���
		break;
	
	case 7:
		system("cls");
		printf("*************************************************************\n");
		printf("           �޸�ѧ����Ϣ               \n");
		printf("*************************************************************\n");
		ModifyStudent();//�޸�ѧ����Ϣ�ĺ���
		break;
	case 8:
		system("cls");
		printf("*************************************************************\n");
		printf("           ɾ��ѧ����Ϣ                \n\n");
		printf("*************************************************************\n");
		DeleteStudent();//ɾ��ѧ����Ϣ�ĺ���
		break;
	case 9:
		system("cls");
		printf("\t\t\t                  ��ӭʹ��ϵͳ������\t\t\t           \n\n");
		help();//��ʾ��Ϣ����
		system("pause"); system("cls");
		break;
	default:
		printf("           ѡ���������������                \n\n");
		system("pause");
		break;
	}
}