#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "string.h"
#include "windows.h"
//�������
char reg_name[30] = "", reg_pwd[10] = "";
char on_name[30], on_pwd[10];


//�û�ע��ϵͳ
void regist()
{
    //����
    system("pause");
    system("cls");
    printf("\n\n\t\t\t��ӭʹ��ע��ϵͳ\n\n");
    while (1)
    {
        //�����û���
        printf("\t\t�������û���[���ܴ���10���ַ�]��");
        scanf("%s", reg_name);

        //�ж��û���
        if (strlen(reg_name) <= 10)
        {
            while (1)
            {
                //��������
                printf("\n\t\t����������[���볤��Ϊ��λ]��");
                scanf("%s", reg_pwd);
                //strlen�����ַ����ĳ��ȣ�ֱ���ս����ַ������������ս����ַ���
                //�ж�����
                if (strlen(reg_pwd) == 8)
                {
                    printf("\n\n\t\tע��ɹ��������û�����%s,������%s\n\n", reg_name, reg_pwd);
                    break;
                }
                else
                {
                    printf("\n\t\t����ĳ���Ϊ%d������������\n", strlen(reg_pwd));
                }
            }
            break;
        }
        else
        {
            printf("\n\t\t�û����ĳ���Ϊ%d������������\n\n", strlen(reg_name));
        }
    }
}

//�ж��Ƿ�ע��
int judge()
{
    //strcmp�����ڱȽ������ַ���
    if (strcmp(reg_name, "") == 0 && strcmp(reg_pwd, "") == 0)
    {
        printf("\n\n\t\t����δע�ᣬ����ע�ᣡ\n\n");
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
    printf("*\t��ӭʹ��ѧ����Ϣ����ϵͳV2.1\t\t*\n");
    printf("*\t\t��ѡ����\t\t\t*\n");
    printf("*************************************************\n");
    printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
    printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t4.��ȡѧ����Ϣ\t\t\t*\n");
    printf("*\t\t5.ͳ������ѧ������\t\t*\n");
    printf("*\t\t6.����ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t7.�޸�ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t8.ɾ��ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t9.ϵͳʹ�÷����Լ�ע������\t*\t\t\n");
    printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
    printf("*************************************************\n");
    printf("*\t\t����0~9��ѡ����\t\t*\t\n");
    printf("*************************************************\n");
}

//�û���¼
void dl()
{
    int i;
    system("pause");
    system("cls");

    printf("\n\n\t\t\t��ӭʹ��ѧ����Ϣ��¼ϵͳ\n\n");
    //���ε�¼��֤
    for (i = 1; i <= 3; i++)
    {
        printf("\t\t�������û���:");
        scanf("%s", on_name);
        printf("\n\t\t����������:");
        scanf("%s", on_pwd);
        //strcmp�����ڱȽ������ַ���
        if (strcmp(reg_name, on_name) == 0 && strcmp(reg_pwd, on_pwd) == 0)
        {
         /*   Menu();*/
            break;
        }
        else
        {
            printf("\n\n\t\t��¼ʧ�ܣ������µ�¼��������%d�λ���\n\n", 3 - i);
        }

    }

}

void aaa()//ѧ����Ϣע���½ϵͳ
{
    //�������
        int id;
        //�������
        printf("\n\n\t\t\tѧ����Ϣ����ϵͳ\n\n");

        printf("\t\t\t��1��ע��\n");
        printf("\t\t\t��2����¼\n");
        printf("\t\t\t��0���˳�\n\n");

        //���빦�ܱ��
        printf("\t\t��ѡ���ܱ�ţ�");
        scanf("%d", &id);

        //�ж�
        switch (id)
        {
        case 1:regist();//�û�ע��ϵͳ
            break;
        case 2:
            if (judge() == 1)//�ж��Ƿ�ע��
            {
                dl();//�û���¼
            }
            break;
        case 0:exit(1);//�˳�ϵͳ���������˳�
            break;
        default:
            printf("\n\t\t������Ĺ��ܱ���������������룡\n");
       }
}

