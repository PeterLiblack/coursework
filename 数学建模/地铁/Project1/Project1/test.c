#define _CRT_SECURE_NO_WARNINGS 1

#include "Subway.h"

void menu()
{
	printf("������������������ӭ����������������������������\n");
	printf("1����ѯ��·��Ϣ\n");
	printf("2����ѯ�˳�����\n");
	printf("3����ѯ����·��\n"); 
	printf("4����ѯվ�����\n");
	printf("0���˳�\n");
	printf("��ѡ��-> ");
}

void test()
{
	map();
	int input = 0;
	GraphType *G;
	AdjList *g;
	G = (GraphType *)malloc(sizeof(GraphType));
	g = (AdjList *)malloc(sizeof(AdjList));
	G = create(G);
	g = list(G, g);
	do
	{
		menu();
		scanf("%d", &input);
		
		switch (input)
		{
		case 1:
			inquiry(G);
			break;
		case 2:
			floyd(G);
			break;
		case 3:
			getallpath(G, g);
			break;
		case 4:
			in_quiry(G);
			break;
		case 0:
			printf("ף����;��죡\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

void main()
{
	test();
	//map();
}