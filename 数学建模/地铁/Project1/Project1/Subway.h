#ifndef __SUBWAY_H__
#define __SUBWAY_H__

#include<stdio.h>
#include<conio.h>  //getch()
#include<stdlib.h> //exit()
#include<string.h>
#include<limits.h>
#include<malloc.h>
#include<windows.h>

#define MAX 500
//#define INT_MAX 99999
//
FILE *fp;
int visited[500];
//int ok;
//int stop = 1;
char name[50], pass[50];
char textstring[100];
//
typedef struct
{
	int adj;
}ArcType;
typedef struct
{
	int num;
	char name[MAX];
	char introduction[MAX];
}PType;

typedef struct
{
	PType vertexs[MAX];   //顶点数组
	ArcType arcs[MAX][MAX];  //邻接矩阵
	int vexnum, arcnum;   //顶点数，边数
}GraphType;
//邻接表
typedef struct arc
{
	int adjvex;   //邻接点域
	int weight;   //权值域
	struct arc *next;  //指向下一邻接点
}ArcType1;
typedef struct
{
	int data;
	ArcType1 *firstarc;
}VertexType;     //顶点表节点
typedef struct
{
	VertexType vextexs[MAX];
	int vexnum, arcnum;
}AdjList;   //邻接表

GraphType *create(GraphType *G);
AdjList *list(GraphType *G, AdjList *g);  //邻接矩阵转化为邻接表

void inquiry(GraphType *G);   //查询景点信息
void in_quiry(GraphType *G);
void getallpath(GraphType *G, AdjList *g);
//void shortest(GraphType *G, int P[][MAX], int D[][MAX]); //最短路径
void floyd(GraphType *G);   //弗洛伊德
void map();

#endif //__SUBWAY_H__