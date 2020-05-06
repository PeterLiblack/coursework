#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h> 
#define MAX 100
FILE *fp;
int n;                  /*当前该厂人数*/
struct person                 /*职工信息结构体*/
{
	char name[10];              /*职工姓名*/
	char number[10];            /*职工工号*/
	char department[10];        /*职工部门*/
	char wages[10];             /*职工工资*/
	char position[10];          /*职工职位*/
}worker[MAX];

/*输出模块*/
void output()
{
	int i;
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("   暂时未有任何信息，请按任意键返回主菜单进行信息录入\n");
		getch();
		exit(0);
	}
	printf("   增加职工信息时：\n");
	printf("姓名\t编号\t部门\t工资\t职位 \n");
	for (i = 0; i<n; i++)
	{
		fscanf(fp, "%s %s %s %s %s ", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
		printf("%s\t%s\t%s\t%s\t%s  \n", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
	}
	fclose(fp);
	printf("   输出完毕，按任意键返回主菜单\n");
	getch();
}
/*添加模块*/
void add()
{
	int i, flag = 0; char ch;
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		printf("不能建立！\n");
		exit(0);
	}
	do
	{
		i = n;
		printf("\n   增加职工的信息时：\n");
		printf("     请输入职工姓名：");
		scanf("%s", worker[i].name);
		printf("     请输入职工工号：");
		scanf("%s", worker[i].number);
		printf("     请输入职工部门：");
		scanf("%s", worker[i].department);
		printf("     请输入职工工资：");
		scanf("%s", worker[i].wages);
		printf("     请输入职工职位: ");
		scanf("%s", worker[i].position);
		n++;
		printf("\n是否还要添加？要添加请输入1 不添加请输入0 \n");
		getchar();           /*接收回车*/
		ch = getchar();
		if (ch == '1')
		{
			printf("继续\n");
			flag = 1;
		}
		else flag = 0;
	} while (flag == 1);
	printf("添加完毕，按任意键返回主菜单\n");
	getch();
	for (i = 0; i<n; i++)
		fprintf(fp, "%s  %s  %s  %s  %s  \n", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
	fclose(fp);
}
/*删除模块*/
void  del()
{
	int i, flag;
	char ch, numberkey[10];
	flag = 0;
	printf("开始删除\n");
	do
	{
		printf("请输入要删除员工工号\n");
		scanf("%s", numberkey);
		for (i = 0; i<n; i++)
		if (strcmp(worker[i].number, numberkey) == 0)      /*查找此人*/
		{
			printf("姓名\t工号\t部门\t工资\t职位 \n");
			printf("%s\t%s\t%s\t%s\t%s  \n", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
			printf("是否删除此人(1/0)\n");
			getchar();           /*接收回车*/
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
			printf("此人不存在\n");
		printf("\n是否继续输入(1/0)\n");
		getchar();           /*接收回车*/
		ch = getchar();
		if (ch == '1')
		{
			printf("继续\n");
			flag = 1;
		}
		else flag = 0;
	} while (flag == 1);
	printf("操作完毕，按任意键返回主菜单\n");
	getch();
}

/*按工号查找*/
void number_cha()
{
	int i, j;
	char numberkey[10];
	j = 0;
	printf("        输入要查询的员工工号\n");
	scanf("%s", numberkey);
	for (i = 0; i<n; i++)
	{
		if (strcmp(worker[i].number, numberkey) == 0)      /*查找此人*/
		{
			printf("---------员工信息------\n");
			printf("姓名\t工号\t部门\t工资\t职位 \n");
			printf("%s\t%s\t%s\t%s\t%s  \n", worker[i].name, worker[i].number, worker[i].department, worker[i].wages, worker[i].position);
		}
		else j++;
	}
	if (j == n)
		printf("此人不存在\n");
	printf("按任意键返回主菜单\n");
	getch();
}
/*主函数*/
void main()
{
	int choice;
	do
	{
		system("cls");
		printf("    _____________________________________________________________ \n");
		printf("   |                                                             |\n");
		printf("   |                欢迎进入公司职工信息管理程序                 |\n");
		printf("   |                ----------------------------                 |\n");
		printf("   |请选择您的操作：                                             |\n");
		printf("   |                                                             |\n");
		printf("   |                      按1，增加职工信息                      |\n");
		printf("   |                                                             |\n");
		printf("   |                      按2，查找职工信息                      |\n");
		printf("   |                                                             |\n");
		printf("   |                      按3，显示所有职工信息                  |\n");
		printf("   |                                                             |\n");
		printf("   |                      按4，删除职工信息                      |\n");
		printf("   |                                                             |\n");
		printf("   |                      按0，退出系统                          |\n");
		printf("   |                                                             |\n");
		printf("   |_____________________________________________________________|\n");
		printf("   请选择按键(0-4)\n");
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
