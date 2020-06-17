#define _CRT_SECURE_NO_WARNINGS 1

#include "Subway.h"

void menu()
{
	printf("————————欢迎乘坐西安地铁————————\n");
	printf("1、查询线路信息\n");
	printf("2、查询乘车方案\n");
	printf("3、查询最优路线\n"); 
	printf("4、查询站点介绍\n");
	printf("0、退出\n");
	printf("请选择-> ");
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
			printf("祝您旅途愉快！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}

void main()
{
	test();
	//map();
}