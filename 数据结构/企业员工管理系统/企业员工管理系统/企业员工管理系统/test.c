#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h> 
#define MAX 100
FILE *fp;
int n;                  /*��ǰ�ó�����*/
struct person                 /*ְ����Ϣ�ṹ��*/
{
	char name[10];              /*ְ������*/
	char number[10];            /*ְ������*/
	char department[10];        /*ְ������*/
	char wages[10];             /*ְ������*/
	char position[10];          /*ְ��ְλ*/
}worker[MAX];

/*���ģ��*/
void output()
{
	int i;
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("   ��ʱδ���κ���Ϣ���밴������������˵�������Ϣ¼��\n");
		getch();
		exit(0);
	}
	printf("   ����ְ����Ϣʱ��\n");
	printf("����\t���\t����\t����\tְλ \n");
	for (i = 0; i<n; i++)
	{
		fscanf(fp, "%s %s %s %s %s ", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
		printf("%s\t%s\t%s\t%s\t%s  \n", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
	}
	fclose(fp);
	printf("   �����ϣ���������������˵�\n");
	getch();
}
/*���ģ��*/
void add()
{
	int i, flag = 0; char ch;
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		printf("���ܽ�����\n");
		exit(0);
	}
	do
	{
		i = n;
		printf("\n   ����ְ������Ϣʱ��\n");
		printf("     ������ְ��������");
		scanf("%s", worker[i].name);
		printf("     ������ְ�����ţ�");
		scanf("%s", worker[i].number);
		printf("     ������ְ�����ţ�");
		scanf("%s", worker[i].department);
		printf("     ������ְ�����ʣ�");
		scanf("%s", worker[i].wages);
		printf("     ������ְ��ְλ: ");
		scanf("%s", worker[i].position);
		n++;
		printf("\n�Ƿ�Ҫ��ӣ�Ҫ���������1 �����������0 \n");
		getchar();           /*���ջس�*/
		ch = getchar();
		if (ch == '1')
		{
			printf("����\n");
			flag = 1;
		}
		else flag = 0;
	} while (flag == 1);
	printf("�����ϣ���������������˵�\n");
	getch();
	for (i = 0; i<n; i++)
		fprintf(fp, "%s  %s  %s  %s  %s  \n", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
	fclose(fp);
}
/*ɾ��ģ��*/
void  del()
{
	int i, flag;
	char ch, numberkey[10];
	flag = 0;
	printf("��ʼɾ��\n");
	do
	{
		printf("������Ҫɾ��Ա������\n");
		scanf("%s", numberkey);
		for (i = 0; i<n; i++)
		if (strcmp(worker[i].number, numberkey) == 0)      /*���Ҵ���*/
		{
			printf("����\t����\t����\t����\tְλ \n");
			printf("%s\t%s\t%s\t%s\t%s  \n", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
			printf("�Ƿ�ɾ������(1/0)\n");
			getchar();           /*���ջس�*/
			ch = getchar();
			if (ch == '1')
			{
				for (i = i + 1; i<n; i++)
					worker[i] = worker[i + 1];
				n--;
			}
			else break;
		}
		if (i == n)
			printf("���˲�����\n");
		printf("\n�Ƿ��������(1/0)\n");
		getchar();           /*���ջس�*/
		ch = getchar();
		if (ch == '1')
		{
			printf("����\n");
			flag = 1;
		}
		else flag = 0;
	} while (flag == 1);
	printf("������ϣ���������������˵�\n");
	getch();
}

/*�����Ų���*/
void number_cha()
{
	int i, j;
	char numberkey[10];
	j = 0;
	printf("        ����Ҫ��ѯ��Ա������\n");
	scanf("%s", numberkey);
	for (i = 0; i<n; i++)
	{
		if (strcmp(worker[i].number, numberkey) == 0)      /*���Ҵ���*/
		{
			printf("---------Ա����Ϣ------\n");
			printf("����\t����\t����\t����\tְλ \n");
			printf("%s\t%s\t%s\t%s\t%s  \n", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
		}
		else j++;
	}
	if (j == n)
		printf("���˲�����\n");
	printf("��������������˵�\n");
	getch();
}
/*������*/
void main()
{
	int choice;
	do
	{
		system("cls");
		printf("    _____________________________________________________________ \n");
		printf("   |                                                             |\n");
		printf("   |                ��ӭ���빫˾ְ����Ϣ�������                 |\n");
		printf("   |                ----------------------------                 |\n");
		printf("   |��ѡ�����Ĳ�����                                             |\n");
		printf("   |                                                             |\n");
		printf("   |                      ��1������ְ����Ϣ                      |\n");
		printf("   |                                                             |\n");
		printf("   |                      ��2������ְ����Ϣ                      |\n");
		printf("   |                                                             |\n");
		printf("   |                      ��3����ʾ����ְ����Ϣ                  |\n");
		printf("   |                                                             |\n");
		printf("   |                      ��4��ɾ��ְ����Ϣ                      |\n");
		printf("   |                                                             |\n");
		printf("   |                      ��0���˳�ϵͳ                          |\n");
		printf("   |                                                             |\n");
		printf("   |_____________________________________________________________|\n");
		printf("   ��ѡ�񰴼�(0-4)\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: add(); break;
		case 2: number_cha(); break;
		case 3: output(); break;
		case 4: del(); break;
		case 0: break;
		}
	} while (choice != 0);
}
