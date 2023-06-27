#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <conio.h>//getch�õ�
#include <stdlib.h>
#include <string.h>

//����һ��ѧ��
typedef struct _Student
{
	char name[20];//����	
	int  age;//����
	int stuNum;//ѧ��
	int score;//�ɼ�
}Student;
//Student stu= { .name[20] = "mjm",.age = 0,.stuNum=0,.score=0};



//�ڵ�,����Ϣ
typedef struct _Node
{
	Student stu;//ѧ��,����data��
	struct _Node* pNext;//ָ����һ���ڵ��ָ��
}Node;


Node* g_pHead = NULL;     //����һ��ͷ���

//¼��ѧ����Ϣ
void InputStudent()
{
	//����һ���½ڵ�
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext =NULL;
	//ͷ�巨
	if (g_pHead == NULL)
	{
		g_pHead = pNewNode;
	}
	else
	{
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}
	
	printf("������ѧ��������\n");
	scanf("%s", pNewNode->stu.name);
	printf("������ѧ�������䣺\n");
	scanf("%d", &pNewNode->stu.age);
	printf("������ѧ����ѧ�ţ�\n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("������ѧ���ĳɼ���\n");
	scanf("%d", &pNewNode->stu.score);
	printf("ѧ����Ϣ¼��ɹ�������\n");
	system("pause");
	system("cls");
}
//��ӡѧ����Ϣ
void PrintStudent()
{
	system("cls");
	printf("*********************************************************************************\n");
	printf("*\t\t\t��ӭʹ�ô�ӡѧ����Ϣ����\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("*\tѧ��\t*\t����\t*\t����\t*\t�ɼ�\t\t*\n");
	printf("*********************************************************************************\n");
	//��������
	Node* p = g_pHead;
	while (p != NULL)
	{
		printf("*\t%d\t*\t%s\t*\t%d\t*\t%d\t\t*\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
		printf("*********************************************************************************\n");
		p = p->pNext;
	}
	system("pause");
}

//����ѧ����Ϣ
void Save_Student()
{
	//�ȴ��ļ�
	FILE* fp=fopen("text.txt","w");//��һ���ı��ļ�������д�룬���û�У��ʹ���һ��
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	//��������
	Node* p = g_pHead;
	while (p != NULL)
	{
		
		//fwrite(&p->stu,sizeof(Student), 1 , fp);//ÿ��дһ���ֽڣ��ܹ�дStuent�����С��дfp��
		fprintf(fp, "%s %d %d %d\n", p->stu.name, p->stu.stuNum, p->stu.age, p->stu.score);
		p = p->pNext;
	}
	//�ر��ļ�
	fclose(fp);
	printf("           *****************************      \n");
	printf("                   ���ݱ���ɹ�                  \n");
	printf("*************************************************\n");
	system("pause");
	system("cls");
}


//��ȡѧ����Ϣ
void ReadStudent()
{
	//���ļ�
	FILE *fp=fopen("text.txt", "r");
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		system("pause");
		return;
	}
	//���ļ�
	Student stu[200];
	while (fread(&stu, 1, sizeof(Student), fp))//�ж����Ƿ�����ļ�ĩβ
	{
		//����һ���½ڵ�
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;
		memcpy(pNewNode, &stu, sizeof(Student));//����һ��Stuednt��С�ģ����Ƶ���stu��Ķ���
		//ͷ�巨
		if (g_pHead == NULL)
		{
			g_pHead = pNewNode;
		}
		else
		{
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;
		}
	//�ر��ļ�
		fclose(fp);
		printf("           *****************************      \n");
		printf("                  ��ȡ���ݳɹ�                    \n");
		printf("*************************************************\n");
		system("pause");
		system("cls");
	}
}
//ͳ������ѧ������
int CountStudent()
{
	int nCount = 0;//ѧ������

	//����
	Node* p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;
	}
	return nCount;
}

//����ѧ��
void FindStudent()
{
	int nStuNum;
	char szName[20];
	printf("*************************************************************\n");
	printf("              ������Ҫ���ҵ�ѧ����ѧ�ţ�                 ");
	scanf("%d", &nStuNum);
	printf("*************************************************************\n");
	printf("*************************************************************\n");
	printf("              ������Ҫ���ҵ�ѧ����������                 ");
	scanf("%s", &szName);
	printf("*************************************************************\n");
	
	//˳�����
	Node* p = g_pHead;
	while (p != NULL)
	{	//strcmp�ַ����ȽϺ���
		if (p->stu.stuNum == nStuNum || strcmp(p->stu.name, szName)==0)
		{
			printf("*************************************************\n");
			printf("                     ���ҳɹ�                          \n");
			printf("*************************************************\n");
			printf("ѧ��:%d ����:%s ����:%d �ɼ�:%d\n", p->stu.stuNum, p->stu.name, p->stu.age, p->stu.score);
			printf("*************************************************\n");
		p = p->pNext;
		}
		else
			printf("û���ҵ���ѧ����Ϣ\n"); system("pause"); return;
	}	
		system("cls");
}

//�޸�ѧ����Ϣ
void ModifyStudent()
{
	int nStuNum;
	printf("\n");
	printf("             ��������Ҫ�޸ĵ�ѧ����Ϣ��ѧ�ţ�   ");
	scanf("%d", &nStuNum);
	printf("*************************************************************\n");
	

	Node* p = g_pHead;
	while (p != NULL)
	{
		////strcmp�ַ����ȽϺ���
		if (p->stu.stuNum == nStuNum)
		{
			printf("������Ҫ�޸ĵ�ѧ����    ����,    ����,    �ɼ���\n");
			scanf("%s %d %d", p->stu.name, &p->stu.age, &p->stu.score);
			printf("*************************************************************\n");
			printf("                   �޸ĳɹ�                                   \n");
			printf("*************************************************************\n");
			break;
		}
		p = p->pNext;
	}
	if (p == NULL)
	{
		printf("û���ҵ���ѧ����Ϣ��\n");
	}
	system("pause");//��ͣ
	system("cls");//����
}
//ɾ��ѧ����Ϣ
void DeleteStudent()
{
	int nStuNum;
	printf("*************************************************************\n");
	printf("               ������Ҫɾ����ѧ����ѧ�ţ�");
	scanf("%d",&nStuNum);
	printf("*************************************************************\n");
	Node* p1,*p2;
	//�ж��ǲ���ͷ�ڵ�
	if (g_pHead->stu.stuNum == nStuNum)
	{
		p1=g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		printf("               �ѳɹ�ɾ����ѧ����Ϣ               \n");
		system("pause");//��ͣ
		system("cls");//����
		return;
	}
	//����ͷ�ڵ�
	Node* p = g_pHead;
	while (p->pNext != NULL)
	{
		if (p->pNext->stu.stuNum == nStuNum)
		{
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			free(p2);
			printf("�ѳɹ�ɾ����ѧ����Ϣ\n");
			system("pause");//��ͣ
			system("cls");//����
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
		printf("û���ҵ���ѧԱ��\n");
	}
	system("pause");//��ͣ
	system("cls");//����
}
//����ϵͳ
void help()
{
		printf("\t�q �] % �r  �q �] % �r  *\t\t1.��ӭʹ��ϵͳ������\t\t\t              *  �q ```�r    �q ```�r\n\n");
		printf("\t (@^o^@)   (@^o^@)  *\t\t2.���ν���ϵͳ��,����ѡ��¼��ѧ����Ϣ\t\t\t      *  (��:��)   (��:��)\n");
		printf("\t (~):(~)   (~):(~)  *\t\t3.���ղ˵���ʾ�������ִ���\t\t\t              *  (~)v(~)   (~)v(~)\n");
		printf("\t (~):(~)   (~):(~)  *\t\t4.����ѧ����Ϣ��,�мǱ���\t\t\t               *  (~)v(~)   (~)v(~)\n");
		printf("\t (~):(~)   (~):(~)  *\t\t5.лл����ʹ�ã�\t\t\t               *  (~)v(~)   (~)v(~)\n");
}