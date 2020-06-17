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
	PType vertexs[MAX];   //��������
	ArcType arcs[MAX][MAX];  //�ڽӾ���
	int vexnum, arcnum;   //������������
}GraphType;
//�ڽӱ�
typedef struct arc
{
	int adjvex;   //�ڽӵ���
	int weight;   //Ȩֵ��
	struct arc *next;  //ָ����һ�ڽӵ�
}ArcType1;
typedef struct
{
	int data;
	ArcType1 *firstarc;
}VertexType;     //�����ڵ�
typedef struct
{
	VertexType vextexs[MAX];
	int vexnum, arcnum;
}AdjList;   //�ڽӱ�

GraphType *create(GraphType *G);
AdjList *list(GraphType *G, AdjList *g);  //�ڽӾ���ת��Ϊ�ڽӱ�

void inquiry(GraphType *G);   //��ѯ������Ϣ
void in_quiry(GraphType *G);
void getallpath(GraphType *G, AdjList *g);
//void shortest(GraphType *G, int P[][MAX], int D[][MAX]); //���·��
void floyd(GraphType *G);   //��������
void map();

#endif //__SUBWAY_H__