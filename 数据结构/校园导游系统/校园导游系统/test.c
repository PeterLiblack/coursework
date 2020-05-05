#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>  //getch()
#include<stdlib.h> //exit()
#include<string.h>
//#include<limits.h> //��
#include<windows.h>
#define MAX 100
#define INT_MAX 99999
FILE *fp;
int visited[100];
int ok;
int stop = 1;
char name[50], pass[50];
char textstring[100];
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

GraphType *create(GraphType *G)  //��������ͼ
{
	int i, j;
	if ((fp = fopen("D:\\file.txt", "wt+")) == NULL)
	{
		printf("\nerror on open D:\\file.txt file!");
//		getch();   //��ͣ����
		exit(0);   //���������е����˳�����
	}
	else
	{
		G = (GraphType *)malloc(sizeof(GraphType));
		G->vexnum = 16;
		G->arcnum = 29;
		G->vertexs[1].num = 1;
		strcpy(G->vertexs[1].name, "ѧУ����");
		strcpy(G->vertexs[1].introduction, "�������������¹Ĵ��48�ţ�����ΪȺ�����꣬�о���������ͨ������");
		fprintf(fp, "%d %s %s\n", G->vertexs[1].num, G->vertexs[1].name, G->vertexs[1].introduction);
		G->vertexs[2].num = 2;
		strcpy(G->vertexs[2].name, "��ѧ����");
		strcpy(G->vertexs[2].introduction, "1-3�Ž�ѧ¥��������ʵ��¥��ú̿¥�ȡ�");
		fprintf(fp, "%d %s %s\n", G->vertexs[2].num, G->vertexs[2].name, G->vertexs[2].introduction);
		G->vertexs[3].num = 3;
		strcpy(G->vertexs[3].name, "���");
		strcpy(G->vertexs[3].introduction, "�����Ƽ���ѧ����У����һ�󾰵㣬�������ģ�ˮɫ������");
		fprintf(fp, "%d %s %s\n", G->vertexs[3].num, G->vertexs[3].name, G->vertexs[3].introduction);
		G->vertexs[4].num = 4;
		strcpy(G->vertexs[4].name, "��ѧ����");
		strcpy(G->vertexs[4].introduction, "9-18�Ž�ѧ¥�����������ѧԺ�ʹ���ʵ����صȡ�");
		fprintf(fp, "%d %s %s\n", G->vertexs[4].num, G->vertexs[4].name, G->vertexs[4].introduction);
		G->vertexs[5].num = 5;
		strcpy(G->vertexs[5].name, "3��4��5��ѧ����Ԣ");
		strcpy(G->vertexs[5].introduction, "3��4��5��ѧ����Ԣ����ΪŮ�����ṫԢ¥��");
		fprintf(fp, "%d %s %s\n", G->vertexs[5].num, G->vertexs[5].name, G->vertexs[5].introduction);
		G->vertexs[6].num = 6;
		strcpy(G->vertexs[6].name, "ͼ���");
		strcpy(G->vertexs[6].introduction, "��ʷ�ƾã��Ļ�������ͬѧ����ѧϰ�Ļ�����");
		fprintf(fp, "%d %s %s\n", G->vertexs[6].num, G->vertexs[6].name, G->vertexs[6].introduction);
		G->vertexs[7].num = 7;
		strcpy(G->vertexs[7].name, "����");
		strcpy(G->vertexs[7].introduction, "�������ⰻȻ�����ﻨ�㣬���˷������ĵĺõط���");
		fprintf(fp, "%d %s %s\n", G->vertexs[7].num, G->vertexs[7].name, G->vertexs[7].introduction);
		G->vertexs[8].num = 8;
		strcpy(G->vertexs[8].name, "������");
		strcpy(G->vertexs[8].introduction, "������������ë���Լ�ƹ����ȸ����˶����أ�Ϊ���Ǳ�Уѧ���ṩ�˺ܺõĶ����������ḻ��������");
		fprintf(fp, "%d %s %s\n", G->vertexs[8].num, G->vertexs[8].name, G->vertexs[8].introduction);
		G->vertexs[9].num = 9;
		strcpy(G->vertexs[9].name, "��ܰԷ");
		strcpy(G->vertexs[9].introduction, "���������죬�ľ�����ĵƲʡ�����ͷ׵�ʳ�ģ�����Ϊ�Ǳ��˵Ĵ�ѧ������");
		fprintf(fp, "%d %s %s\n", G->vertexs[9].num, G->vertexs[9].name, G->vertexs[9].introduction);
		G->vertexs[10].num = 10;
		strcpy(G->vertexs[10].name, "1��2��ѧ����Ԣ");
		strcpy(G->vertexs[10].introduction, "1��2������¥��1������¥Ϊ�������ṫԢ¥��2������¥ΪŮ�����ṫԢ¥��");
		fprintf(fp, "%d %s %s\n", G->vertexs[10].num, G->vertexs[10].name, G->vertexs[10].introduction);
		G->vertexs[11].num = 11;
		strcpy(G->vertexs[11].name, "�ۺ�¥");
		strcpy(G->vertexs[11].introduction, "���ǲ��񴦵����ڵأ�Ҳ��УҽԺ����ŵ㣬ͬѧ�ǿ�����ҩ�ĵط����ṩ������");
		fprintf(fp, "%d %s %s\n", G->vertexs[11].num, G->vertexs[11].name, G->vertexs[11].introduction);
		G->vertexs[12].num = 12;
		strcpy(G->vertexs[12].name, "6��7��ѧ����Ԣ");
		strcpy(G->vertexs[12].introduction, "6��7�Ź�Ԣ���Ǿۺ�����¥Ϊһ�����������ṫԢ¥��");
		fprintf(fp, "%d %s %s\n", G->vertexs[12].num, G->vertexs[12].name, G->vertexs[12].introduction);
		G->vertexs[13].num = 13;
		strcpy(G->vertexs[13].name, "�ﾶ��");
		strcpy(G->vertexs[13].introduction, "�ﾶ����Ҫ��������������˶����Լ��ٰ��˶������Ŀ�ĳ��أ�Ҳ���ܲ�����Ҫ���ء�");
		fprintf(fp, "%d %s %s\n", G->vertexs[13].num, G->vertexs[13].name, G->vertexs[13].introduction);
		G->vertexs[14].num = 14;
		strcpy(G->vertexs[14].name, "����Է");
		strcpy(G->vertexs[14].introduction, "Ϊѧ������������������������ܰ���ʵľͲͻ�����ϸ�µķ���Ϊʦ���������µľͲ����顣");
		fprintf(fp, "%d %s %s\n", G->vertexs[14].num, G->vertexs[14].name, G->vertexs[14].introduction);
		G->vertexs[15].num = 15;
		strcpy(G->vertexs[15].name, "��");
		strcpy(G->vertexs[15].introduction, "��������������ճ��Ͽεĵط������⣬Ҳ�Ǵ�ҽ��������д衢���ֽ���ĳ��ء�");
		fprintf(fp, "%d %s %s\n", G->vertexs[15].num, G->vertexs[15].name, G->vertexs[15].introduction);
		G->vertexs[16].num = 16;
		strcpy(G->vertexs[16].name, "��Ӿ��");
		strcpy(G->vertexs[16].introduction, "�õ���Ϊ��Ӿ�ν�ѧ����ͬѧ�ǿ��Ը��õ�������Ӿ����ܡ�");
		fprintf(fp, "%d %s %s\n", G->vertexs[16].num, G->vertexs[16].name, G->vertexs[16].introduction);
		for (i = 1; i <= G->vexnum; i++)
		for (j = 1; j <= G->vexnum; j++)
			G->arcs[i][j].adj = INT_MAX;
		for (i = 1; i <= G->vexnum; i++)
			G->arcs[i][i].adj = 0;
		G->arcs[1][2].adj = G->arcs[2][1].adj = 100;
		G->arcs[2][3].adj = G->arcs[3][2].adj = 20;
		G->arcs[2][4].adj = G->arcs[4][2].adj = 80;
		G->arcs[3][5].adj = G->arcs[5][3].adj = G->arcs[3][7].adj = G->arcs[7][3].adj = 40;
		G->arcs[3][6].adj = G->arcs[6][3].adj = 10;
		G->arcs[4][7].adj = G->arcs[7][4].adj = G->arcs[4][8].adj = G->arcs[8][4].adj = 40;
		G->arcs[5][9].adj = G->arcs[9][5].adj = 10;
		G->arcs[6][7].adj = G->arcs[7][6].adj = 10;
		G->arcs[6][10].adj = G->arcs[10][6].adj = G->arcs[6][11].adj = G->arcs[11][6].adj = 20;
		G->arcs[7][8].adj = G->arcs[8][7].adj = 40;
		G->arcs[8][11].adj = G->arcs[11][8].adj = 40;
		G->arcs[8][12].adj = G->arcs[12][8].adj = G->arcs[8][13].adj = G->arcs[13][8].adj = 30;
		G->arcs[9][10].adj = G->arcs[10][9].adj = 10;
		G->arcs[9][14].adj = G->arcs[14][9].adj = 20;
		G->arcs[10][11].adj = G->arcs[11][10].adj = G->arcs[10][14].adj = G->arcs[14][10].adj = 10;
		G->arcs[11][12].adj = G->arcs[12][11].adj = 20;
		G->arcs[12][14].adj = G->arcs[14][12].adj = 20;
		G->arcs[12][13].adj = G->arcs[13][12].adj = G->arcs[12][15].adj = G->arcs[15][12].adj = 30;
		G->arcs[13][15].adj = G->arcs[15][13].adj = 30;
		G->arcs[13][16].adj = G->arcs[16][13].adj = 40;
		G->arcs[14][15].adj = G->arcs[15][14].adj = 30;
		G->arcs[15][16].adj = G->arcs[16][15].adj = 50;
		for (i = 1; i <= G->vexnum; i++)
		{
			for (j = 1; j <= G->vexnum; j++)
			{
				fprintf(fp, "%d\t", G->arcs[i][j].adj);
			}
		}
	}
	fclose(fp);
	return G;
}

AdjList *list(GraphType *G, AdjList *g)  //�ڽӾ���ת��Ϊ�ڽӱ�
{
	int i, j;
	ArcType1 *p;
	for (i = 1; i <= G->vexnum; i++)
		g->vextexs[i].firstarc = NULL;
	for (i = 1; i <= G->vexnum; i++)
	for (j = G->vexnum; j >= 1; j--)
	{
		if (G->arcs[i][j].adj != INT_MAX)
		{
			p = (ArcType1 *)malloc(sizeof(ArcType1));
			p->adjvex = j;
			p->next = g->vextexs[i].firstarc;   //ͷ�巨
			g->vextexs[i].firstarc = p;
		}
	}
	g->vexnum = G->vexnum;
	g->arcnum = G->arcnum;
	return g;
}

void inquiry(GraphType *G)   //��ѯ������Ϣ
{
	int n;
	printf("�����ѯ�ľ�����Ϊ��");
	scanf("%d", &n);
	printf("%d,%s", G->vertexs[n].num, G->vertexs[n].name);
	printf("\n�������:\n");
	printf("%s", G->vertexs[n].introduction);
}
void shortest(GraphType *G, int P[][MAX], int D[][MAX]) //���·��
{
	int m, n;
	printf("��ϣ����ѯ������?\n");
	scanf("%d", &m);
	printf("��\n");
	scanf("%d", &n);
	fflush(stdin);
	if (m<n)
	{
		printf("%s��%s֮������·������Ϊ%d\n", G->vertexs[m].name, G->vertexs[n].name, D[m][n]);
		printf("path: %s", G->vertexs[n].name);
		while (P[m][n] != 0)
		{
			printf("<--%s", G->vertexs[P[m][n]].name);
			if (m<n)
				n = P[m][n];
			else
				m = P[n][m];
		}
		printf("<--%s", G->vertexs[m].name);
	}
	else
	{
		printf("path: %s", G->vertexs[m].name);
		while (P[m][n] != 0)
		{
			printf("-->%s", G->vertexs[P[m][n]].name);
			if (m<n)
				n = P[m][n];
			else
				m = P[n][m];
		}
		printf("-->%s", G->vertexs[n].name);
		printf("%s��%s֮������·������Ϊ%d\n", G->vertexs[m].name, G->vertexs[n].name, D[m][n]);
	}
}

void floyd(GraphType *G)   //��������
{
	int D[MAX][MAX];
	int P[MAX][MAX];
	//P[i][j]Ϊi��j�ĵ�ǰ���·����D[i][j]��¼·������
	int i, j, k;
	for (j = 1; j <= G->vexnum; j++)
	{
		for (k = 1; k <= G->vexnum; k++)
		{
			D[j][k] = G->arcs[j][k].adj;  //��ʼ��D
			P[j][k] = 0;         //��ʼ��P
		}
	}
	for (i = 1; i <= G->vexnum; i++)
	{
		for (j = 1; j <= G->vexnum; j++)
		{
			for (k = 1; k <= G->vexnum; k++)
			{
				if (D[j][i] + D[i][k]<D[j][k])
				{
					D[j][k] = D[j][i] + D[i][k];
					P[j][k] = i;
					P[k][j] = i;  //��¼������·��
				}
			}
		}
	}
	shortest(G, P, D);
}
void allpath(GraphType *G, AdjList *g, int m, int n, int path[], int d) //�����������·��
{
	int w, i;
	ArcType1 *p;
	visited[m] = 1;
	d++;
	path[d] = m;
	if (m == n&&d >= 1)
	{
		printf(" ");
		for (i = 0; i<d; i++)
			printf("%s->", G->vertexs[path[i]].name);
		printf("%s", G->vertexs[path[d]].name);
		printf("\n");
	}
	p = g->vextexs[m].firstarc;
	while (p != NULL)
	{
		w = p->adjvex;
		if (visited[w] == 0)
			allpath(G, g, w, n, path, d);
		p = p->next;
	}
	visited[m] = 0;
}
void getallpath(GraphType *G, AdjList *g)  //�ó�����·��
{
	int m, n;
	int path[MAX];
	printf("��ϣ����ѯ������?");
	scanf("%d", &m);
	printf("��");
	scanf("%d", &n);
	allpath(G, g, m, n, path, -1);
}

void add(GraphType *G, FILE *fp)   //���Ӿ���
{
	int length, i;
	fp = fopen("D:\\file.txt", "at+");
	G->vexnum = G->vexnum + 1;
	G->vertexs[G->vexnum].num = G->vexnum;
	printf("�����������������֣�");
	scanf("%s", G->vertexs[G->vexnum].name);
	printf("����������������ܣ�");
	scanf("%s", G->vertexs[G->vexnum].introduction);
	fprintf(fp, "%d %s %s", G->vertexs[G->vexnum].num, G->vertexs[G->vexnum].name, G->vertexs[G->vexnum].introduction);
	printf("����������Ϊ��");
	printf("%d", G->vertexs[G->vexnum].num);
	printf("������þ��㵽�����������·��\n");
	for (i = 1; i <= G->vexnum; i++)
	{
		printf("��%d�ž����·�����ȣ��������ڣ�������INT_MAX����", i);
		scanf("%d\t", &length);
		G->arcs[G->vexnum][i].adj = G->arcs[i][G->vexnum].adj = length;
	}
	fclose(fp);
}

void update(GraphType *G, FILE *fp)   //���¾�����Ϣ
{
	int num0, num, num1;
	fp = fopen("D:\\file.txt", "at+");
	printf("���������޸ľ�����");
	scanf("%d", &num0);
	printf("��Ҫ���ĵ���1������  2�����  3���������·��\n�������ţ�");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("�������޸ĺ������");
		scanf("%s", G->vertexs[num0].name);
		break;
	case 2:
		printf("�������޸ĺ�ļ��");
		scanf("%s", G->vertexs[num0].introduction);
		break;
	case 3:
		printf("�����޸ĸõ㵽�ĵ��·��\n�����룺");
		scanf("%d", &num1);
		printf("����1������·��  2��ɾ��·��  3���޸�·������\n�����룺");
		scanf("%d", &num1);
		switch (num1)
		{
		case 1:
			printf("������·������Ϊ��");
			scanf("%d", &G->arcs[num0][num1].adj);
			G->arcs[num1][num0].adj = G->arcs[num0][num1].adj;
			break;
		case 2:
			G->arcs[num1][num0].adj = INT_MAX;
			G->arcs[num0][num1].adj = INT_MAX;
			break;
		case 3:
			printf("·�������޸�Ϊ");
			scanf("%d", &G->arcs[num0][num1]);
			G->arcs[num1][num0].adj = G->arcs[num0][num1].adj;
			break;
		}
	}
	fclose(fp);
}

void menu()
{
	printf("\t\t�˵�\n");
	printf("\t1����ѯ������Ϣ\n\t2����ѯ�����������·��\n\t3����ѯ�������������·��\n\t4�����Ӿ���\n\t5�����¾���͵�·��Ϣ\n");
	printf("\t6����¼\n\t7��ע��\n");
	printf("\tע����ֻ��ע���Ϊ����Ա�ſ�ִ��4��5\n\t    ���˳�ϵͳ������0\n");
}
void map()
{
	printf("��~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~��\n");
	printf("��                                                                   ��---------��   ��\n");
	printf("��                                          ��---------��           ___��16.��Ӿ�ݩ�   ��\n");
	printf("��                                         _�� 15.     ��         �u    ��---------��   ��\n");
	printf("��                                       �u  ��  ��  �� ��_______�u                    ��\n");
	printf("��                                     �u    ��---------��                            ��\n");
	printf("��                                   �u              �v                              ��\n");
	printf("��                                 �u                  �v                            ��\n");
	printf("��                               �u             ��----------��                        ��\n");
	printf("��                          ��-------��          ��12. 6��7�ũ�________         ����   ��\n");
	printf("��                  ��      ��14.    ��----------��  ѧ����Ԣ��        �v����-------��    ��\n");
	printf("��                        �u �� ����Է��          ��----------���v         �v��13.    ��    ��\n");
	printf("��            ��        �u   ��-------��              ��         �v        �� �ﾶ����    ��\n");
	printf("��   ����������-------������     ��                   ��         ���v      ��-------��    ��\n");
	printf("��           ��9.     ��         ��              ��---------��        �v                 ��\n");
	printf("��           �� ��ܰԷ��         ��             �u��11.�ۺ�¥��          �v               ��\n");
	printf("��         �u ��-------�� �v    ��----------��  �u   ��---------���v           �v             ��\n");
	printf("��       �u               �v  ��10. 1��2�ũ��u          ��       �v ________��-------��     ��\n");
	printf("��     �u                   �v�� ѧ����Ԣ ���v          ��                 �� 8.    ��     ��\n");
	printf("�� ��-----------��            ��----------��  �v        ��              �u  �� �����ݩ�     ��\n");
	printf("�� ��5. 3��4��5 ��                             �v ��--------��       �u    ��-------��     ��\n");
	printf("�� �� ��ѧ����Ԣ��   �v                         __��6.ͼ��ݩ�     �u          ��         ��\n");
	printf("�� ��-----------��     �v                     �u   ��--------��   �u            ��         ��\n");
	printf("��                     �v                 �u         ��      �u              ��         ��\n");
	printf("��                       �v             �u           ��    �u                ��         ��\n");
	printf("��                         �v ��------���u        ��------��                   ��         ��\n");
	printf("��                           ��4.��ة�����������----��7.���֩�_____              ��         ��\n");
	printf("��                           ��------��         ��------��      �v            ��         ��\n");
	printf("��                                   �v                        �v __��----------��     ��\n");
	printf("��                                     �v                          ��3.��ѧ������     ��\n");
	printf("��                                ��----------��  _________________�u��----------��     ��\n");
	printf("��                                ��2.��ѧ�������u                                    ��\n");
	printf("��                                ��----------��                                     ��\n");
	printf("��                                         ��                                       ��\n");
	printf("��                                         ��                                       ��\n");
	printf("��                                         ��                                       ��\n");
	printf("��                                       ��----------��                              ��\n");
	printf("��                                       ��1.ѧУ���ũ�                              ��\n");
	printf("��                                       ��----------��                              ��\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	printf("\n");
	fflush(stdin);
}/*map*/
void denglu()  //����Ա��¼ϵͳ
{
	FILE *fp;
	int len = 0;
	printf("�������˺�");
	scanf("%s", name);
	printf("����������");
	scanf("%s", pass);
	strcat(name, pass);    //�ַ������� 
	strcat(name, "\n");
	fp = fopen("D:\\users0.txt", "at+");
	if (NULL == fp)
	{
		printf("failed to open dos.txt\n");
	}

	while (!feof(fp))  //�ļ�ָ�뵽ĩβ������ֵΪ����
	{
		memset(textstring, 0, sizeof(textstring));  //��ʼ��textstring[]
		fgets(textstring, sizeof(textstring)-1, fp); //��ָ���ļ���һ���ַ������ַ�������
		if (strcmp(name, textstring) == 0)  //�ַ����Ƚ�
		{
			ok = 1;
			break;
		}
	}
	if (ok)
		printf("    ��¼�ɹ�\n");
	else
		printf("    ��¼ʧ��\n");
	fclose(fp);

}
void zhuce()
{
	FILE *fp = fopen("D:\\users0.txt", "at+");
	printf("�������˺�");
	scanf("%s", name);
	printf("����������");
	scanf("%s", pass);
	fputs(name, fp);
	fputs(pass, fp);
	fputs("\n", fp);
	fflush(stdin);
	fclose(fp);
	printf("ע��ɹ������¼\n");
	denglu();
}
void run()
{
	int m, n;
	GraphType *G;
	AdjList *g;
	G = (GraphType *)malloc(sizeof(GraphType));
	g = (AdjList *)malloc(sizeof(AdjList));
	G = create(G);
	g = list(G, g);
	system("color F0");
	map();
	while (stop)
	{
		menu();
		printf("\n���������������һ��������");
		scanf("%d", &n);
		switch (n)
		{
		case 0:stop = 0;
			printf("\n\t���˳�\n\n"); break;
		case 1:inquiry(G);
			printf("\n"); break;
		case 2:floyd(G);
			printf("\n"); break;
		case 3:getallpath(G, g);
			printf("\n"); break;
		case 4:
		case 5:printf("�������ǹ���Ա\n"); break;
		case 6:denglu();
			if (ok)
			{
				menu();
				printf("\n���������������һ��������");
				scanf("%d", &m);
				switch (m)
				{
				case 0:stop = 0;
					printf("\n\t���˳�\n\n"); break;
				case 1:inquiry(G);
					printf("\n"); break;
				case 2:floyd(G);
					printf("\n"); break;
				case 3:getallpath(G, g);
					printf("\n"); break;
				case 4:add(G, fp);
					printf("\n"); break;
				case 5:update(G, fp);
					printf("\n"); break;
				default:printf("error");
				}
			}
			break;
		case 7:zhuce();
			if (ok)
			{
				menu();
				printf("\n���������������һ��������");
				scanf("%d", &m);
				switch (m)
				{
				case 0:stop = 0;
					printf("\n\t���˳�\n\n"); break;
				case 1:inquiry(G);
					printf("\n"); break;
				case 2:floyd(G);
					printf("\n"); break;
				case 3:getallpath(G, g);
					printf("\n"); break;
				case 4:add(G, fp);
					printf("\n"); break;
				case 5:update(G, fp);
					printf("\n"); break;
				default:printf("error");
				}
			}
			break;
		default:printf("error");
		}
	}
}
void main()
{
	run();
}
