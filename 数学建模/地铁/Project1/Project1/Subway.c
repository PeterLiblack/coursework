#define _CRT_SECURE_NO_WARNINGS 1

#include "Subway.h"

void inquiry(GraphType *G)   //��ѯ��·��Ϣ
{
	int n = 0;
	printf("�ٺ���ȫ��վ�� ��%s", G->vertexs[1].name);
	for (n = 2; n <= 25; n++) {
			printf(" --> %s", G->vertexs[n].name);
	}
	printf("\n");
	printf("\n�ں���ȫ��վ�� ��%s", G->vertexs[26].name);
	for (n = 27; n <= 49; n++) {
		printf(" --> %s", G->vertexs[n].name);
	}
	printf("\n");
	printf("\n�ۺ���ȫ��վ�� ��%s", G->vertexs[50].name);
	for (n = 51; n <= 78; n++) {
		printf(" --> %s", G->vertexs[n].name);
	}
	printf("\n");
	printf("\n�ܺ���ȫ��վ�� ��%s", G->vertexs[79].name);
	for (n = 80; n <= 107; n++) {
		printf(" --> %s", G->vertexs[n].name);
	}
	printf("\n");
	printf("\n�ݺ���ȫ��վ�� ��%s", G->vertexs[108].name);
	for (n = 109; n <= 139; n++) {
		printf(" --> %s", G->vertexs[n].name);
	}
	printf("\n");
	printf("\n�޺���ȫ��վ�� ��%s", G->vertexs[140].name);
	for (n = 141; n <= 167; n++) {
		printf(" --> %s", G->vertexs[n].name);
	}
	printf("\n");
	printf("\nע������Ϊ����վ\n");
}

void in_quiry(GraphType *G)   //��ѯ������Ϣ
{
	int n;
	printf("�����ѯ�ľ�����Ϊ��");
	scanf("%d", &n);
	printf("%d,%s", G->vertexs[n].num, G->vertexs[n].name);
	printf("\n�������:\n");
	printf("%s\n", G->vertexs[n].introduction);
}


void getShortestPath(GraphType *G, int P[][MAX], int D[][MAX])
{
	int m, n;
	printf("��ϣ����ѯ������?\n");
	scanf("%d%d", &m,&n);
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
	//shortest(G, P, D);
	getShortestPath(G, P, D);
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
	printf("�����������յ㣺");
	scanf("%d%d", &m, &n);
	allpath(G, g, m, n, path, -1);
}

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
		G->vexnum = 167;
		G->arcnum = 176;

		//һ����
		G->vertexs[1].num = 1;
		strcpy(G->vertexs[1].name, "1��ɭ�ֹ�԰��");
		strcpy(G->vertexs[1].introduction, "һ����1");
		fprintf(fp, "%d %s %s\n", G->vertexs[1].num, G->vertexs[1].name, G->vertexs[1].introduction);
		G->vertexs[2].num = 2;
		strcpy(G->vertexs[2].name, "2���涫·��");
		strcpy(G->vertexs[2].introduction, "һ����2");
		fprintf(fp, "%d %s %s\n", G->vertexs[2].num, G->vertexs[2].name, G->vertexs[2].introduction);
		G->vertexs[3].num = 3;
		strcpy(G->vertexs[3].name, "3������·��");
		strcpy(G->vertexs[3].introduction, "1.3");
		fprintf(fp, "%d %s %s\n", G->vertexs[3].num, G->vertexs[3].name, G->vertexs[3].introduction);
		G->vertexs[4].num = 4;
		strcpy(G->vertexs[4].name, "4���żҴ壩");
		strcpy(G->vertexs[4].introduction, "1.4");
		fprintf(fp, "%d %s %s\n", G->vertexs[4].num, G->vertexs[4].name, G->vertexs[4].introduction);
		G->vertexs[5].num = 5;
		strcpy(G->vertexs[5].name, "5������կ��");
		strcpy(G->vertexs[5].introduction, "1.5");
		fprintf(fp, "%d %s %s\n", G->vertexs[5].num, G->vertexs[5].name, G->vertexs[5].introduction);
		G->vertexs[6].num = 6;
		strcpy(G->vertexs[6].name, "6����ջ��");
		strcpy(G->vertexs[6].introduction, "1.6");
		fprintf(fp, "%d %s %s\n", G->vertexs[6].num, G->vertexs[6].name, G->vertexs[6].introduction);
		G->vertexs[7].num = 7;
		strcpy(G->vertexs[7].name, "7����ӣ�");
		strcpy(G->vertexs[7].introduction, "1.7");
		fprintf(fp, "%d %s %s\n", G->vertexs[7].num, G->vertexs[7].name, G->vertexs[7].introduction);
		G->vertexs[8].num = 8;
		strcpy(G->vertexs[8].name, "8����԰��");
		strcpy(G->vertexs[8].introduction, "1.8");
		fprintf(fp, "%d %s %s\n", G->vertexs[8].num, G->vertexs[8].name, G->vertexs[8].introduction);
		G->vertexs[9].num = 9;
		strcpy(G->vertexs[9].name, "9������·��");
		strcpy(G->vertexs[9].introduction, "1.9");
		fprintf(fp, "%d %s %s\n", G->vertexs[9].num, G->vertexs[9].name, G->vertexs[9].introduction);
		G->vertexs[10].num = 10;
		strcpy(G->vertexs[10].name, "10����Զ�ţ�");
		strcpy(G->vertexs[10].introduction, "1.10");
		fprintf(fp, "%d %s %s\n", G->vertexs[10].num, G->vertexs[10].name, G->vertexs[10].introduction);
		G->vertexs[11].num = 11;
		strcpy(G->vertexs[11].name, "11���Ͷ�·��");
		strcpy(G->vertexs[11].introduction, "1.11");
		fprintf(fp, "%d %s %s\n", G->vertexs[11].num, G->vertexs[11].name, G->vertexs[11].introduction);
		G->vertexs[12].num = 12;
		strcpy(G->vertexs[12].name, "12�������ţ�");
		strcpy(G->vertexs[12].introduction, "1.12");
		fprintf(fp, "%d %s %s\n", G->vertexs[12].num, G->vertexs[12].name, G->vertexs[12].introduction);
		G->vertexs[13].num = 13;
		strcpy(G->vertexs[13].name, "13������¥��");
		strcpy(G->vertexs[13].introduction, "1.13");
		fprintf(fp, "%d %s %s\n", G->vertexs[13].num, G->vertexs[13].name, G->vertexs[13].introduction);
		G->vertexs[14].num = 14;
		strcpy(G->vertexs[14].name, "14������֡�");
		strcpy(G->vertexs[14].introduction, "1.14");
		fprintf(fp, "%d %s %s\n", G->vertexs[14].num, G->vertexs[14].name, G->vertexs[14].introduction);
		G->vertexs[15].num = 15;
		strcpy(G->vertexs[15].name, "15����·�ڡ�");
		strcpy(G->vertexs[15].introduction, "1.15");
		fprintf(fp, "%d %s %s\n", G->vertexs[15].num, G->vertexs[15].name, G->vertexs[15].introduction);
		G->vertexs[16].num = 16;
		strcpy(G->vertexs[16].name, "16�������ţ�");
		strcpy(G->vertexs[16].introduction, "1.16");
		fprintf(fp, "%d %s %s\n", G->vertexs[16].num, G->vertexs[16].name, G->vertexs[16].introduction);
		G->vertexs[17].num = 17;
		strcpy(G->vertexs[17].name, "17������·��");
		strcpy(G->vertexs[17].introduction, "1.17");
		fprintf(fp, "%d %s %s\n", G->vertexs[17].num, G->vertexs[17].name, G->vertexs[17].introduction);
		G->vertexs[18].num = 18;
		strcpy(G->vertexs[18].name, "18��ͨ���š�");
		strcpy(G->vertexs[18].introduction, "1.18");
		fprintf(fp, "%d %s %s\n", G->vertexs[18].num, G->vertexs[18].name, G->vertexs[18].introduction);
		G->vertexs[19].num = 19;
		strcpy(G->vertexs[19].name, "19������·��");
		strcpy(G->vertexs[19].introduction, "1.19");
		fprintf(fp, "%d %s %s\n", G->vertexs[19].num, G->vertexs[19].name, G->vertexs[19].introduction);
		G->vertexs[20].num = 20;
		strcpy(G->vertexs[20].name, "20�������£�");
		strcpy(G->vertexs[20].introduction, "1.20");
		fprintf(fp, "%d %s %s\n", G->vertexs[20].num, G->vertexs[20].name, G->vertexs[20].introduction);
		G->vertexs[21].num = 21;
		strcpy(G->vertexs[21].name, "21����屣�");
		strcpy(G->vertexs[21].introduction, "1.21");
		fprintf(fp, "%d %s %s\n", G->vertexs[21].num, G->vertexs[21].name, G->vertexs[21].introduction);
		G->vertexs[22].num = 22;
		strcpy(G->vertexs[22].name, "22�����£�");
		strcpy(G->vertexs[22].introduction, "1.22");
		fprintf(fp, "%d %s %s\n", G->vertexs[22].num, G->vertexs[22].name, G->vertexs[22].introduction);
		G->vertexs[23].num = 23;
		strcpy(G->vertexs[23].name, "23����֯�ǡ�");
		strcpy(G->vertexs[23].introduction, "1.23");
		fprintf(fp, "%d %s %s\n", G->vertexs[23].num, G->vertexs[23].name, G->vertexs[23].introduction);
		G->vertexs[24].num = 24;
		strcpy(G->vertexs[24].name, "24�����죩");
		strcpy(G->vertexs[24].introduction, "1.24");
		fprintf(fp, "%d %s %s\n", G->vertexs[24].num, G->vertexs[24].name, G->vertexs[24].introduction);
		G->vertexs[25].num = 25;
		strcpy(G->vertexs[25].name, "25��������");
		strcpy(G->vertexs[25].introduction, "1.25");
		fprintf(fp, "%d %s %s\n", G->vertexs[25].num, G->vertexs[25].name, G->vertexs[25].introduction);

		//������
		G->vertexs[26].num = 26;
		strcpy(G->vertexs[26].name, "26���¼ұ���");
		strcpy(G->vertexs[26].introduction, "2.1");
		fprintf(fp, "%d %s %s\n", G->vertexs[26].num, G->vertexs[26].name, G->vertexs[26].introduction);
		G->vertexs[27].num = 27;
		strcpy(G->vertexs[27].name, "27����̲��");
		strcpy(G->vertexs[27].introduction, "2.2");
		fprintf(fp, "%d %s %s\n", G->vertexs[27].num, G->vertexs[27].name, G->vertexs[27].introduction);
		G->vertexs[28].num = 28;
		strcpy(G->vertexs[28].name, "28������¡��");
		strcpy(G->vertexs[28].introduction, "2.3");
		fprintf(fp, "%d %s %s\n", G->vertexs[28].num, G->vertexs[28].name, G->vertexs[28].introduction);
		G->vertexs[29].num = 29;
		strcpy(G->vertexs[29].name, "29������վ��");
		strcpy(G->vertexs[29].introduction, "2.4");
		fprintf(fp, "%d %s %s\n", G->vertexs[29].num, G->vertexs[29].name, G->vertexs[29].introduction);
		G->vertexs[30].num = 30;
		strcpy(G->vertexs[30].name, "30����Է��");
		strcpy(G->vertexs[30].introduction, "2.5");
		fprintf(fp, "%d %s %s\n", G->vertexs[30].num, G->vertexs[30].name, G->vertexs[30].introduction);
		G->vertexs[31].num = 31;
		strcpy(G->vertexs[31].name, "31���˶���԰��");
		strcpy(G->vertexs[31].introduction, "2.6");
		fprintf(fp, "%d %s %s\n", G->vertexs[31].num, G->vertexs[31].name, G->vertexs[31].introduction);
		G->vertexs[32].num = 32;
		strcpy(G->vertexs[32].name, "32���������ġ�");
		strcpy(G->vertexs[32].introduction, "2.7");
		fprintf(fp, "%d %s %s\n", G->vertexs[32].num, G->vertexs[32].name, G->vertexs[32].introduction);
		G->vertexs[33].num = 33;
		strcpy(G->vertexs[33].name, "33�������·��");
		strcpy(G->vertexs[33].introduction, "2.8");
		fprintf(fp, "%d %s %s\n", G->vertexs[33].num, G->vertexs[33].name, G->vertexs[33].introduction);
		G->vertexs[34].num = 34;
		strcpy(G->vertexs[34].name, "34����ͼ��ݣ�");
		strcpy(G->vertexs[34].introduction, "2.9");
		fprintf(fp, "%d %s %s\n", G->vertexs[34].num, G->vertexs[34].name, G->vertexs[34].introduction);
		G->vertexs[35].num = 35;
		strcpy(G->vertexs[35].name, "35������������");
		strcpy(G->vertexs[35].introduction, "2.10");
		fprintf(fp, "%d %s %s\n", G->vertexs[35].num, G->vertexs[35].name, G->vertexs[35].introduction);
		G->vertexs[36].num = 36;
		strcpy(G->vertexs[36].name, "36������ԭ��");
		strcpy(G->vertexs[36].introduction, "2.11");
		fprintf(fp, "%d %s %s\n", G->vertexs[36].num, G->vertexs[36].name, G->vertexs[36].introduction);
		G->vertexs[37].num = 37;
		strcpy(G->vertexs[37].name, "37����Զ�ţ�");
		strcpy(G->vertexs[37].introduction, "2.12");
		fprintf(fp, "%d %s %s\n", G->vertexs[37].num, G->vertexs[37].name, G->vertexs[37].introduction);
		G->vertexs[38].num = 38;
		strcpy(G->vertexs[38].name, "38������֡�");
		strcpy(G->vertexs[38].introduction, "2.13");
		fprintf(fp, "%d %s %s\n", G->vertexs[38].num, G->vertexs[38].name, G->vertexs[38].introduction);
		G->vertexs[39].num = 39;
		strcpy(G->vertexs[39].name, "39����¥��");
		strcpy(G->vertexs[39].introduction, "2.14");
		fprintf(fp, "%d %s %s\n", G->vertexs[39].num, G->vertexs[39].name, G->vertexs[39].introduction);
		G->vertexs[40].num = 40;
		strcpy(G->vertexs[40].name, "40�������ţ�");
		strcpy(G->vertexs[40].introduction, "2.15");
		fprintf(fp, "%d %s %s\n", G->vertexs[40].num, G->vertexs[40].name, G->vertexs[40].introduction);
		G->vertexs[41].num = 41;
		strcpy(G->vertexs[41].name, "41�������š�");
		strcpy(G->vertexs[41].introduction, "2.16");
		fprintf(fp, "%d %s %s\n", G->vertexs[41].num, G->vertexs[41].name, G->vertexs[41].introduction);
		G->vertexs[42].num = 42;
		strcpy(G->vertexs[42].name, "42����������");
		strcpy(G->vertexs[42].introduction, "2.17");
		fprintf(fp, "%d %s %s\n", G->vertexs[42].num, G->vertexs[42].name, G->vertexs[42].introduction);
		G->vertexs[43].num = 43;
		strcpy(G->vertexs[43].name, "43��Сկ��");
		strcpy(G->vertexs[43].introduction, "2.18");
		fprintf(fp, "%d %s %s\n", G->vertexs[43].num, G->vertexs[43].name, G->vertexs[43].introduction);
		G->vertexs[44].num = 44;
		strcpy(G->vertexs[44].name, "44��γһ�֣�");
		strcpy(G->vertexs[44].introduction, "2.19");
		fprintf(fp, "%d %s %s\n", G->vertexs[44].num, G->vertexs[44].name, G->vertexs[44].introduction);
		G->vertexs[45].num = 45;
		strcpy(G->vertexs[45].name, "45����չ���ģ�");
		strcpy(G->vertexs[45].introduction, "2.20");
		fprintf(fp, "%d %s %s\n", G->vertexs[45].num, G->vertexs[45].name, G->vertexs[45].introduction);
		G->vertexs[46].num = 46;
		strcpy(G->vertexs[46].name, "46����س��");
		strcpy(G->vertexs[46].introduction, "2.21");
		fprintf(fp, "%d %s %s\n", G->vertexs[46].num, G->vertexs[46].name, G->vertexs[46].introduction);
		G->vertexs[47].num = 47;
		strcpy(G->vertexs[47].name, "47������ԭ��");
		strcpy(G->vertexs[47].introduction, "2.22");
		fprintf(fp, "%d %s %s\n", G->vertexs[47].num, G->vertexs[47].name, G->vertexs[47].introduction);
		G->vertexs[48].num = 48;
		strcpy(G->vertexs[48].name, "48������ǣ�");
		strcpy(G->vertexs[48].introduction, "2.23");
		fprintf(fp, "%d %s %s\n", G->vertexs[48].num, G->vertexs[48].name, G->vertexs[48].introduction);
		G->vertexs[49].num = 49;
		strcpy(G->vertexs[49].name, "49��Τ���ϣ�");
		strcpy(G->vertexs[49].introduction, "2.24");
		fprintf(fp, "%d %s %s\n", G->vertexs[49].num, G->vertexs[49].name, G->vertexs[49].introduction);

		//������
		G->vertexs[50].num = 50;
		strcpy(G->vertexs[50].name, "50����˰����");
		strcpy(G->vertexs[50].introduction, "3.1");
		fprintf(fp, "%d %s %s\n", G->vertexs[50].num, G->vertexs[50].name, G->vertexs[50].introduction);
		G->vertexs[51].num = 51;
		strcpy(G->vertexs[51].name, "51��������");
		strcpy(G->vertexs[51].introduction, "3.2");
		fprintf(fp, "%d %s %s\n", G->vertexs[51].num, G->vertexs[51].name, G->vertexs[51].introduction);
		G->vertexs[52].num = 52;
		strcpy(G->vertexs[52].name, "52��˫կ��");
		strcpy(G->vertexs[52].introduction, "3.3");
		fprintf(fp, "%d %s %s\n", G->vertexs[52].num, G->vertexs[52].name, G->vertexs[52].introduction);
		G->vertexs[53].num = 53;
		strcpy(G->vertexs[53].name, "53�����ʸ�������");
		strcpy(G->vertexs[53].introduction, "3.4");
		fprintf(fp, "%d %s %s\n", G->vertexs[53].num, G->vertexs[53].name, G->vertexs[53].introduction);
		G->vertexs[54].num = 54;
		strcpy(G->vertexs[54].name, "54����ׯ��");
		strcpy(G->vertexs[54].introduction, "3.5");
		fprintf(fp, "%d %s %s\n", G->vertexs[54].num, G->vertexs[54].name, G->vertexs[54].introduction);
		G->vertexs[55].num = 55;
		strcpy(G->vertexs[55].name, "55������԰��");
		strcpy(G->vertexs[55].introduction, "3.6");
		fprintf(fp, "%d %s %s\n", G->vertexs[55].num, G->vertexs[55].name, G->vertexs[55].introduction);
		G->vertexs[56].num = 56;
		strcpy(G->vertexs[56].name, "56��������ģ�");
		strcpy(G->vertexs[56].introduction, "3.7");
		fprintf(fp, "%d %s %s\n", G->vertexs[56].num, G->vertexs[56].name, G->vertexs[56].introduction);
		G->vertexs[57].num = 57;
		strcpy(G->vertexs[57].name, "57���һ�̶��");
		strcpy(G->vertexs[57].introduction, "3.8");
		fprintf(fp, "%d %s %s\n", G->vertexs[57].num, G->vertexs[57].name, G->vertexs[57].introduction);
		G->vertexs[58].num = 58;
		strcpy(G->vertexs[58].name, "58����̩�ţ�");
		strcpy(G->vertexs[58].introduction, "3.9");
		fprintf(fp, "%d %s %s\n", G->vertexs[58].num, G->vertexs[58].name, G->vertexs[58].introduction);
		G->vertexs[59].num = 59;
		strcpy(G->vertexs[59].name, "59��������");
		strcpy(G->vertexs[59].introduction, "3.10");
		fprintf(fp, "%d %s %s\n", G->vertexs[59].num, G->vertexs[59].name, G->vertexs[59].introduction);
		G->vertexs[60].num = 60;
		strcpy(G->vertexs[60].name, "60��ʯ�ҽ֣�");
		strcpy(G->vertexs[60].introduction, "3.11");
		fprintf(fp, "%d %s %s\n", G->vertexs[60].num, G->vertexs[60].name, G->vertexs[60].introduction);
		G->vertexs[61].num = 61;
		strcpy(G->vertexs[61].name, "61��������");
		strcpy(G->vertexs[61].introduction, "3.12");
		fprintf(fp, "%d %s %s\n", G->vertexs[61].num, G->vertexs[61].name, G->vertexs[61].introduction);
		G->vertexs[62].num = 62;
		strcpy(G->vertexs[62].name, "62��ͨ���š�");
		strcpy(G->vertexs[62].introduction, "3.13");
		fprintf(fp, "%d %s %s\n", G->vertexs[62].num, G->vertexs[62].name, G->vertexs[62].introduction);
		G->vertexs[63].num = 63;
		strcpy(G->vertexs[63].name, "63�����ֹ�԰��");
		strcpy(G->vertexs[63].introduction, "3.14");
		fprintf(fp, "%d %s %s\n", G->vertexs[63].num, G->vertexs[63].name, G->vertexs[63].introduction);
		G->vertexs[64].num = 64;
		strcpy(G->vertexs[64].name, "64�������š�");
		strcpy(G->vertexs[64].introduction, "3.15");
		fprintf(fp, "%d %s %s\n", G->vertexs[64].num, G->vertexs[64].name, G->vertexs[64].introduction);
		G->vertexs[65].num = 65;
		strcpy(G->vertexs[65].name, "65�������ţ�");
		strcpy(G->vertexs[65].introduction, "3.16");
		fprintf(fp, "%d %s %s\n", G->vertexs[65].num, G->vertexs[65].name, G->vertexs[65].introduction);
		G->vertexs[66].num = 66;
		strcpy(G->vertexs[66].name, "66���������¡�");
		strcpy(G->vertexs[66].introduction, "3.17");
		fprintf(fp, "%d %s %s\n", G->vertexs[66].num, G->vertexs[66].name, G->vertexs[66].introduction);
		G->vertexs[67].num = 67;
		strcpy(G->vertexs[67].name, "67������ͷ��");
		strcpy(G->vertexs[67].introduction, "3.18");
		fprintf(fp, "%d %s %s\n", G->vertexs[67].num, G->vertexs[67].name, G->vertexs[67].introduction);
		G->vertexs[68].num = 68;
		strcpy(G->vertexs[68].name, "68����������");
		strcpy(G->vertexs[68].introduction, "3.19");
		fprintf(fp, "%d %s %s\n", G->vertexs[68].num, G->vertexs[68].name, G->vertexs[68].introduction);
		G->vertexs[69].num = 69;
		strcpy(G->vertexs[69].name, "69��Сկ��");
		strcpy(G->vertexs[69].introduction, "3.20");
		fprintf(fp, "%d %s %s\n", G->vertexs[69].num, G->vertexs[69].name, G->vertexs[69].introduction);
		G->vertexs[70].num = 70;
		strcpy(G->vertexs[70].name, "70������壩");
		strcpy(G->vertexs[70].introduction, "3.21");
		fprintf(fp, "%d %s %s\n", G->vertexs[70].num, G->vertexs[70].name, G->vertexs[70].introduction);
		G->vertexs[71].num = 71;
		strcpy(G->vertexs[71].name, "71��̫����·��");
		strcpy(G->vertexs[71].introduction, "3.22");
		fprintf(fp, "%d %s %s\n", G->vertexs[71].num, G->vertexs[71].name, G->vertexs[71].introduction);
		G->vertexs[72].num = 72;
		strcpy(G->vertexs[72].name, "72���Ƽ�·��");
		strcpy(G->vertexs[72].introduction, "3.23");
		fprintf(fp, "%d %s %s\n", G->vertexs[72].num, G->vertexs[72].name, G->vertexs[72].introduction);
		G->vertexs[73].num = 73;
		strcpy(G->vertexs[73].name, "73����ƽ�ţ�");
		strcpy(G->vertexs[73].introduction, "3.24");
		fprintf(fp, "%d %s %s\n", G->vertexs[73].num, G->vertexs[73].name, G->vertexs[73].introduction);
		G->vertexs[74].num = 74;
		strcpy(G->vertexs[74].name, "74���ɰ˱�·��");
		strcpy(G->vertexs[74].introduction, "3.25");
		fprintf(fp, "%d %s %s\n", G->vertexs[74].num, G->vertexs[74].name, G->vertexs[74].introduction);
		G->vertexs[75].num = 75;
		strcpy(G->vertexs[75].name, "75���㻯կ��");
		strcpy(G->vertexs[75].introduction, "3.26");
		fprintf(fp, "%d %s %s\n", G->vertexs[75].num, G->vertexs[75].name, G->vertexs[75].introduction);
		G->vertexs[76].num = 76;
		strcpy(G->vertexs[76].name, "76��¹��ׯ��");
		strcpy(G->vertexs[76].introduction, "3.27");
		fprintf(fp, "%d %s %s\n", G->vertexs[76].num, G->vertexs[76].name, G->vertexs[76].introduction);
		G->vertexs[77].num = 77;
		strcpy(G->vertexs[77].name, "77������կ��");
		strcpy(G->vertexs[77].introduction, "3.28");
		fprintf(fp, "%d %s %s\n", G->vertexs[77].num, G->vertexs[77].name, G->vertexs[77].introduction);
		G->vertexs[78].num = 78;
		strcpy(G->vertexs[78].name, "78���Ϸᣩ");
		strcpy(G->vertexs[78].introduction, "3.29");
		fprintf(fp, "%d %s %s\n", G->vertexs[78].num, G->vertexs[78].name, G->vertexs[78].introduction);

		//�ĺ���
		G->vertexs[79].num = 79;
		strcpy(G->vertexs[79].name, "79���а�·��");
		strcpy(G->vertexs[79].introduction, "4.1");
		fprintf(fp, "%d %s %s\n", G->vertexs[79].num, G->vertexs[79].name, G->vertexs[79].introduction);
		G->vertexs[80].num = 80;
		strcpy(G->vertexs[80].name, "80����Է·��");
		strcpy(G->vertexs[80].introduction, "4.2");
		fprintf(fp, "%d %s %s\n", G->vertexs[80].num, G->vertexs[80].name, G->vertexs[80].introduction);
		G->vertexs[81].num = 81;
		strcpy(G->vertexs[81].name, "81������·��");
		strcpy(G->vertexs[81].introduction, "4.3");
		fprintf(fp, "%d %s %s\n", G->vertexs[81].num, G->vertexs[81].name, G->vertexs[81].introduction);
		G->vertexs[82].num = 82;
		strcpy(G->vertexs[82].name, "82�����ʮ��·��");
		strcpy(G->vertexs[82].introduction, "4.4");
		fprintf(fp, "%d %s %s\n", G->vertexs[82].num, G->vertexs[82].name, G->vertexs[82].introduction);
		G->vertexs[83].num = 83;
		strcpy(G->vertexs[83].name, "83����Ǿ�·��");
		strcpy(G->vertexs[83].introduction, "4.5");
		fprintf(fp, "%d %s %s\n", G->vertexs[83].num, G->vertexs[83].name, G->vertexs[83].introduction);
		G->vertexs[84].num = 84;
		strcpy(G->vertexs[84].name, "84���ľ�·��");
		strcpy(G->vertexs[84].introduction, "4.6");
		fprintf(fp, "%d %s %s\n", G->vertexs[84].num, G->vertexs[84].name, G->vertexs[84].introduction);
		G->vertexs[85].num = 85;
		strcpy(G->vertexs[85].name, "85���������ġ�");
		strcpy(G->vertexs[85].introduction, "4.7");
		fprintf(fp, "%d %s %s\n", G->vertexs[85].num, G->vertexs[85].name, G->vertexs[85].introduction);
		G->vertexs[86].num = 86;
		strcpy(G->vertexs[86].name, "86������·��");
		strcpy(G->vertexs[86].introduction, "4.8");
		fprintf(fp, "%d %s %s\n", G->vertexs[86].num, G->vertexs[86].name, G->vertexs[86].introduction);
		G->vertexs[87].num = 87;
		strcpy(G->vertexs[87].name, "87������·��");
		strcpy(G->vertexs[87].introduction, "4.9");
		fprintf(fp, "%d %s %s\n", G->vertexs[87].num, G->vertexs[87].name, G->vertexs[87].introduction);
		G->vertexs[88].num = 88;
		strcpy(G->vertexs[88].name, "88���ٻ��壩");
		strcpy(G->vertexs[88].introduction, "4.10");
		fprintf(fp, "%d %s %s\n", G->vertexs[88].num, G->vertexs[88].name, G->vertexs[88].introduction);
		G->vertexs[89].num = 89;
		strcpy(G->vertexs[89].name, "89���ܼ���");
		strcpy(G->vertexs[89].introduction, "4.11");
		fprintf(fp, "%d %s %s\n", G->vertexs[89].num, G->vertexs[89].name, G->vertexs[89].introduction);
		G->vertexs[90].num = 90;
		strcpy(G->vertexs[90].name, "90������·��");
		strcpy(G->vertexs[90].introduction, "4.12");
		fprintf(fp, "%d %s %s\n", G->vertexs[90].num, G->vertexs[90].name, G->vertexs[90].introduction);
		G->vertexs[91].num = 91;
		strcpy(G->vertexs[91].name, "91����������");
		strcpy(G->vertexs[91].introduction, "4.13");
		fprintf(fp, "%d %s %s\n", G->vertexs[91].num, G->vertexs[91].name, G->vertexs[91].introduction);
		G->vertexs[92].num = 92;
		strcpy(G->vertexs[92].name, "92����Ԫ·��");
		strcpy(G->vertexs[92].introduction, "4.14");
		fprintf(fp, "%d %s %s\n", G->vertexs[92].num, G->vertexs[92].name, G->vertexs[92].introduction);
		G->vertexs[93].num = 93;
		strcpy(G->vertexs[93].name, "93��������վ��");
		strcpy(G->vertexs[93].introduction, "4.15");
		fprintf(fp, "%d %s %s\n", G->vertexs[93].num, G->vertexs[93].name, G->vertexs[93].introduction);
		G->vertexs[94].num = 94;
		strcpy(G->vertexs[94].name, "94����·�ڡ�");
		strcpy(G->vertexs[94].introduction, "4.16");
		fprintf(fp, "%d %s %s\n", G->vertexs[94].num, G->vertexs[94].name, G->vertexs[94].introduction);
		G->vertexs[95].num = 95;
		strcpy(G->vertexs[95].name, "95������С�");
		strcpy(G->vertexs[95].introduction, "4.17");
		fprintf(fp, "%d %s %s\n", G->vertexs[95].num, G->vertexs[95].name, G->vertexs[95].introduction);
		G->vertexs[96].num = 96;
		strcpy(G->vertexs[96].name, "96����ƽ�ţ�");
		strcpy(G->vertexs[96].introduction, "4.18");
		fprintf(fp, "%d %s %s\n", G->vertexs[96].num, G->vertexs[96].name, G->vertexs[96].introduction);
		G->vertexs[97].num = 97;
		strcpy(G->vertexs[97].name, "97����Ҵ塿");
		strcpy(G->vertexs[97].introduction, "4.19");
		fprintf(fp, "%d %s %s\n", G->vertexs[97].num, G->vertexs[97].name, G->vertexs[97].introduction);
		G->vertexs[98].num = 98;
		strcpy(G->vertexs[98].name, "98����壩");
		strcpy(G->vertexs[98].introduction, "4.20");
		fprintf(fp, "%d %s %s\n", G->vertexs[98].num, G->vertexs[98].name, G->vertexs[98].introduction);
		G->vertexs[99].num = 99;
		strcpy(G->vertexs[99].name, "99����������");
		strcpy(G->vertexs[99].introduction, "4.21");
		fprintf(fp, "%d %s %s\n", G->vertexs[99].num, G->vertexs[99].name, G->vertexs[99].introduction);
		G->vertexs[100].num = 100;
		strcpy(G->vertexs[100].name, "100������ܽ��԰��");
		strcpy(G->vertexs[100].introduction, "4.22");
		fprintf(fp, "%d %s %s\n", G->vertexs[100].num, G->vertexs[100].name, G->vertexs[100].introduction);
		G->vertexs[101].num = 101;
		strcpy(G->vertexs[101].name, "101�������أ�");
		strcpy(G->vertexs[101].introduction, "4.23");
		fprintf(fp, "%d %s %s\n", G->vertexs[101].num, G->vertexs[101].name, G->vertexs[101].introduction);
		G->vertexs[102].num = 102;
		strcpy(G->vertexs[102].name, "102����������");
		strcpy(G->vertexs[102].introduction, "4.24");
		fprintf(fp, "%d %s %s\n", G->vertexs[102].num, G->vertexs[102].name, G->vertexs[102].introduction);
		G->vertexs[103].num = 103;
		strcpy(G->vertexs[103].name, "103����������");
		strcpy(G->vertexs[103].introduction, "4.25");
		fprintf(fp, "%d %s %s\n", G->vertexs[103].num, G->vertexs[103].name, G->vertexs[103].introduction);
		G->vertexs[104].num = 104;
		strcpy(G->vertexs[104].name, "104������·��");
		strcpy(G->vertexs[104].introduction, "4.26");
		fprintf(fp, "%d %s %s\n", G->vertexs[104].num, G->vertexs[104].name, G->vertexs[104].introduction);
		G->vertexs[105].num = 105;
		strcpy(G->vertexs[105].name, "105������·��");
		strcpy(G->vertexs[105].introduction, "4.27");
		fprintf(fp, "%d %s %s\n", G->vertexs[105].num, G->vertexs[105].name, G->vertexs[105].introduction);
		G->vertexs[106].num = 106;
		strcpy(G->vertexs[106].name, "106�����ݴ����");
		strcpy(G->vertexs[106].introduction, "4.28");
		fprintf(fp, "%d %s %s\n", G->vertexs[106].num, G->vertexs[106].name, G->vertexs[106].introduction);
		G->vertexs[107].num = 107;
		strcpy(G->vertexs[107].name, "107�����춫·��");
		strcpy(G->vertexs[107].introduction, "4.29");
		fprintf(fp, "%d %s %s\n", G->vertexs[107].num, G->vertexs[107].name, G->vertexs[107].introduction);

		//�����
		G->vertexs[108].num = 108;
		strcpy(G->vertexs[108].name, "108����Ҧ��");
		strcpy(G->vertexs[108].introduction, "5.1");
		fprintf(fp, "%d %s %s\n", G->vertexs[108].num, G->vertexs[108].name, G->vertexs[108].introduction);
		G->vertexs[109].num = 109;
		strcpy(G->vertexs[109].name, "109��ʷ�ұ���");
		strcpy(G->vertexs[109].introduction, "5.2");
		fprintf(fp, "%d %s %s\n", G->vertexs[109].num, G->vertexs[109].name, G->vertexs[109].introduction);
		G->vertexs[110].num = 110;
		strcpy(G->vertexs[110].name, "110����ׯ��");
		strcpy(G->vertexs[110].introduction, "5.3");
		fprintf(fp, "%d %s %s\n", G->vertexs[110].num, G->vertexs[110].name, G->vertexs[110].introduction);
		G->vertexs[111].num = 111;
		strcpy(G->vertexs[111].name, "111����ׯ��");
		strcpy(G->vertexs[111].introduction, "5.4");
		fprintf(fp, "%d %s %s\n", G->vertexs[111].num, G->vertexs[111].name, G->vertexs[111].introduction);
		G->vertexs[112].num = 112;
		strcpy(G->vertexs[112].name, "112�������ɣ�");
		strcpy(G->vertexs[112].introduction, "5.5");
		fprintf(fp, "%d %s %s\n", G->vertexs[112].num, G->vertexs[112].name, G->vertexs[112].introduction);
		G->vertexs[113].num = 113;
		strcpy(G->vertexs[113].name, "113�������ͣ�");
		strcpy(G->vertexs[113].introduction, "5.6");
		fprintf(fp, "%d %s %s\n", G->vertexs[113].num, G->vertexs[113].name, G->vertexs[113].introduction);
		G->vertexs[114].num = 114;
		strcpy(G->vertexs[114].name, "114�����̣�");
		strcpy(G->vertexs[114].introduction, "5.7");
		fprintf(fp, "%d %s %s\n", G->vertexs[114].num, G->vertexs[114].name, G->vertexs[114].introduction);
		G->vertexs[115].num = 115;
		strcpy(G->vertexs[115].name, "115�����ţ�");
		strcpy(G->vertexs[115].introduction, "5.8");
		fprintf(fp, "%d %s %s\n", G->vertexs[115].num, G->vertexs[115].name, G->vertexs[115].introduction);
		G->vertexs[116].num = 116;
		strcpy(G->vertexs[116].name, "116����������");
		strcpy(G->vertexs[116].introduction, "5.9");
		fprintf(fp, "%d %s %s\n", G->vertexs[116].num, G->vertexs[116].name, G->vertexs[116].introduction);
		G->vertexs[117].num = 117;
		strcpy(G->vertexs[117].name, "117��ţ�Ǵ壩");
		strcpy(G->vertexs[117].introduction, "5.10");
		fprintf(fp, "%d %s %s\n", G->vertexs[117].num, G->vertexs[117].name, G->vertexs[117].introduction);
		G->vertexs[118].num = 118;
		strcpy(G->vertexs[118].name, "118���侩��");
		strcpy(G->vertexs[118].introduction, "5.11");
		fprintf(fp, "%d %s %s\n", G->vertexs[118].num, G->vertexs[118].name, G->vertexs[118].introduction);
		G->vertexs[119].num = 119;
		strcpy(G->vertexs[119].name, "119�����壩");
		strcpy(G->vertexs[119].introduction, "5.12");
		fprintf(fp, "%d %s %s\n", G->vertexs[119].num, G->vertexs[119].name, G->vertexs[119].introduction);
		G->vertexs[120].num = 120;
		strcpy(G->vertexs[120].name, "120����ƽ�壩");
		strcpy(G->vertexs[120].introduction, "5.13");
		fprintf(fp, "%d %s %s\n", G->vertexs[120].num, G->vertexs[120].name, G->vertexs[120].introduction);
		G->vertexs[121].num = 121;
		strcpy(G->vertexs[121].name, "121����������");
		strcpy(G->vertexs[121].introduction, "5.14");
		fprintf(fp, "%d %s %s\n", G->vertexs[121].num, G->vertexs[121].name, G->vertexs[121].introduction);
		G->vertexs[122].num = 122;
		strcpy(G->vertexs[122].name, "122����Ҥͷ��");
		strcpy(G->vertexs[122].introduction, "5.15");
		fprintf(fp, "%d %s %s\n", G->vertexs[122].num, G->vertexs[122].name, G->vertexs[122].introduction);
		G->vertexs[123].num = 123;
		strcpy(G->vertexs[123].name, "123��������·��");
		strcpy(G->vertexs[123].introduction, "5.16");
		fprintf(fp, "%d %s %s\n", G->vertexs[123].num, G->vertexs[123].name, G->vertexs[123].introduction);
		G->vertexs[124].num = 124;
		strcpy(G->vertexs[124].name, "124������԰��");
		strcpy(G->vertexs[124].introduction, "5.17");
		fprintf(fp, "%d %s %s\n", G->vertexs[124].num, G->vertexs[124].name, G->vertexs[124].introduction);
		G->vertexs[125].num = 125;
		strcpy(G->vertexs[125].name, "125��������·��");
		strcpy(G->vertexs[125].introduction, "5.18");
		fprintf(fp, "%d %s %s\n", G->vertexs[125].num, G->vertexs[125].name, G->vertexs[125].introduction);
		G->vertexs[126].num = 126;
		strcpy(G->vertexs[126].name, "126���Ͷ���·��");
		strcpy(G->vertexs[126].introduction, "5.19");
		fprintf(fp, "%d %s %s\n", G->vertexs[126].num, G->vertexs[126].name, G->vertexs[126].introduction);
		G->vertexs[127].num = 127;
		strcpy(G->vertexs[127].name, "127���߼Ҵ壩");
		strcpy(G->vertexs[127].introduction, "5.20");
		fprintf(fp, "%d %s %s\n", G->vertexs[127].num, G->vertexs[127].name, G->vertexs[127].introduction);
		G->vertexs[128].num = 128;
		strcpy(G->vertexs[128].name, "128������壩");
		strcpy(G->vertexs[128].introduction, "5.21");
		fprintf(fp, "%d %s %s\n", G->vertexs[128].num, G->vertexs[128].name, G->vertexs[128].introduction);
		G->vertexs[129].num = 129;
		strcpy(G->vertexs[129].name, "129�������š�");
		strcpy(G->vertexs[129].introduction, "5.22");
		fprintf(fp, "%d %s %s\n", G->vertexs[129].num, G->vertexs[129].name, G->vertexs[129].introduction);
		G->vertexs[130].num = 130;
		strcpy(G->vertexs[130].name, "130������·��");
		strcpy(G->vertexs[130].introduction, "5.23");
		fprintf(fp, "%d %s %s\n", G->vertexs[130].num, G->vertexs[130].name, G->vertexs[130].introduction);
		G->vertexs[131].num = 131;
		strcpy(G->vertexs[131].name, "131����Ҵ塿");
		strcpy(G->vertexs[131].introduction, "5.24");
		fprintf(fp, "%d %s %s\n", G->vertexs[131].num, G->vertexs[131].name, G->vertexs[131].introduction);
		G->vertexs[132].num = 132;
		strcpy(G->vertexs[132].name, "132��̫��·��");
		strcpy(G->vertexs[132].introduction, "5.25");
		fprintf(fp, "%d %s %s\n", G->vertexs[132].num, G->vertexs[132].name, G->vertexs[132].introduction);
		G->vertexs[133].num = 133;
		strcpy(G->vertexs[133].name, "133������·��");
		strcpy(G->vertexs[133].introduction, "5.26");
		fprintf(fp, "%d %s %s\n", G->vertexs[133].num, G->vertexs[133].name, G->vertexs[133].introduction);
		G->vertexs[134].num = 134;
		strcpy(G->vertexs[134].name, "134�������¡�");
		strcpy(G->vertexs[134].introduction, "5.27");
		fprintf(fp, "%d %s %s\n", G->vertexs[134].num, G->vertexs[134].name, G->vertexs[134].introduction);
		G->vertexs[135].num = 135;
		strcpy(G->vertexs[135].name, "135������կ��");
		strcpy(G->vertexs[135].introduction, "5.28");
		fprintf(fp, "%d %s %s\n", G->vertexs[135].num, G->vertexs[135].name, G->vertexs[135].introduction);
		G->vertexs[136].num = 136;
		strcpy(G->vertexs[136].name, "136���ټ�կ��");
		strcpy(G->vertexs[136].introduction, "5.29");
		fprintf(fp, "%d %s %s\n", G->vertexs[136].num, G->vertexs[136].name, G->vertexs[136].introduction);
		G->vertexs[137].num = 137;
		strcpy(G->vertexs[137].name, "137������·��");
		strcpy(G->vertexs[137].introduction, "5.30");
		fprintf(fp, "%d %s %s\n", G->vertexs[137].num, G->vertexs[137].name, G->vertexs[137].introduction);
		G->vertexs[138].num = 138;
		strcpy(G->vertexs[138].name, "138���µǸ�");
		strcpy(G->vertexs[138].introduction, "5.31");
		fprintf(fp, "%d %s %s\n", G->vertexs[138].num, G->vertexs[138].name, G->vertexs[138].introduction);
		G->vertexs[139].num = 139;
		strcpy(G->vertexs[139].name, "139����֯�ǻ�վ��");
		strcpy(G->vertexs[139].introduction, "5.32");
		fprintf(fp, "%d %s %s\n", G->vertexs[139].num, G->vertexs[139].name, G->vertexs[139].introduction);

		//������
		G->vertexs[140].num = 140;
		strcpy(G->vertexs[140].name, "140���Ͽ�վ��");
		strcpy(G->vertexs[140].introduction, "6.1");
		fprintf(fp, "%d %s %s\n", G->vertexs[140].num, G->vertexs[140].name, G->vertexs[140].introduction);
		G->vertexs[141].num = 141;
		strcpy(G->vertexs[141].name, "141�����£�");
		strcpy(G->vertexs[141].introduction, "6.2");
		fprintf(fp, "%d %s %s\n", G->vertexs[141].num, G->vertexs[141].name, G->vertexs[141].introduction);
		G->vertexs[142].num = 142;
		strcpy(G->vertexs[142].name, "142��γ��ʮ��·��");
		strcpy(G->vertexs[142].introduction, "6.3");
		fprintf(fp, "%d %s %s\n", G->vertexs[142].num, G->vertexs[142].name, G->vertexs[142].introduction);
		G->vertexs[143].num = 143;
		strcpy(G->vertexs[143].name, "143��γʮ��·��");
		strcpy(G->vertexs[143].introduction, "4.4");
		fprintf(fp, "%d %s %s\n", G->vertexs[143].num, G->vertexs[143].name, G->vertexs[143].introduction);
		G->vertexs[144].num = 144;
		strcpy(G->vertexs[144].name, "144�����������");
		strcpy(G->vertexs[144].introduction, "6.5");
		fprintf(fp, "%d %s %s\n", G->vertexs[144].num, G->vertexs[144].name, G->vertexs[144].introduction);
		G->vertexs[145].num = 145;
		strcpy(G->vertexs[145].name, "145����ҵ��·��");
		strcpy(G->vertexs[145].introduction, "6.6");
		fprintf(fp, "%d %s %s\n", G->vertexs[145].num, G->vertexs[145].name, G->vertexs[145].introduction);
		G->vertexs[146].num = 146;
		strcpy(G->vertexs[146].name, "146����ҵ·��");
		strcpy(G->vertexs[146].introduction, "6.7");
		fprintf(fp, "%d %s %s\n", G->vertexs[146].num, G->vertexs[146].name, G->vertexs[146].introduction);
		G->vertexs[147].num = 147;
		strcpy(G->vertexs[147].name, "147���ɰ���·��");
		strcpy(G->vertexs[147].introduction, "6.8");
		fprintf(fp, "%d %s %s\n", G->vertexs[147].num, G->vertexs[147].name, G->vertexs[147].introduction);
		G->vertexs[148].num = 148;
		strcpy(G->vertexs[148].name, "148���ɰ���·��");
		strcpy(G->vertexs[148].introduction, "6.9");
		fprintf(fp, "%d %s %s\n", G->vertexs[148].num, G->vertexs[148].name, G->vertexs[148].introduction);
		G->vertexs[149].num = 149;
		strcpy(G->vertexs[149].name, "149���ɰ�һ·��");
		strcpy(G->vertexs[149].introduction, "6.10");
		fprintf(fp, "%d %s %s\n", G->vertexs[149].num, G->vertexs[149].name, G->vertexs[149].introduction);
		G->vertexs[150].num = 150;
		strcpy(G->vertexs[150].name, "150��ʡ��Ӿ�ݣ�");
		strcpy(G->vertexs[150].introduction, "6.11");
		fprintf(fp, "%d %s %s\n", G->vertexs[150].num, G->vertexs[150].name, G->vertexs[150].introduction);
		G->vertexs[151].num = 151;
		strcpy(G->vertexs[151].name, "151��ľ���£�");
		strcpy(G->vertexs[151].introduction, "6.12");
		fprintf(fp, "%d %s %s\n", G->vertexs[151].num, G->vertexs[151].name, G->vertexs[151].introduction);
		G->vertexs[152].num = 152;
		strcpy(G->vertexs[152].name, "152���Ƽ���·��");
		strcpy(G->vertexs[152].introduction, "6.13");
		fprintf(fp, "%d %s %s\n", G->vertexs[152].num, G->vertexs[152].name, G->vertexs[152].introduction);
		G->vertexs[153].num = 153;
		strcpy(G->vertexs[153].name, "153���Ƽ�·��");
		strcpy(G->vertexs[153].introduction, "6.14");
		fprintf(fp, "%d %s %s\n", G->vertexs[153].num, G->vertexs[153].name, G->vertexs[153].introduction);
		G->vertexs[154].num = 154;
		strcpy(G->vertexs[154].name, "154���Ͷ���·��");
		strcpy(G->vertexs[154].introduction, "6.15");
		fprintf(fp, "%d %s %s\n", G->vertexs[154].num, G->vertexs[154].name, G->vertexs[154].introduction);
		G->vertexs[155].num = 155;
		strcpy(G->vertexs[155].name, "155������·��");
		strcpy(G->vertexs[155].introduction, "6.16");
		fprintf(fp, "%d %s %s\n", G->vertexs[155].num, G->vertexs[155].name, G->vertexs[155].introduction);
		G->vertexs[156].num = 156;
		strcpy(G->vertexs[156].name, "156���������֣�");
		strcpy(G->vertexs[156].introduction, "6.17");
		fprintf(fp, "%d %s %s\n", G->vertexs[156].num, G->vertexs[156].name, G->vertexs[156].introduction);
		G->vertexs[157].num = 157;
		strcpy(G->vertexs[157].name, "157������֣�");
		strcpy(G->vertexs[157].introduction, "6.18");
		fprintf(fp, "%d %s %s\n", G->vertexs[157].num, G->vertexs[157].name, G->vertexs[157].introduction);
		G->vertexs[158].num = 158;
		strcpy(G->vertexs[158].name, "158����¥��");
		strcpy(G->vertexs[158].introduction, "6.19");
		fprintf(fp, "%d %s %s\n", G->vertexs[158].num, G->vertexs[158].name, G->vertexs[158].introduction);
		G->vertexs[159].num = 159;
		strcpy(G->vertexs[159].name, "159������С�");
		strcpy(G->vertexs[159].introduction, "6.20");
		fprintf(fp, "%d %s %s\n", G->vertexs[159].num, G->vertexs[159].name, G->vertexs[159].introduction);
		G->vertexs[160].num = 160;
		strcpy(G->vertexs[160].name, "160���������֣�");
		strcpy(G->vertexs[160].introduction, "6.21");
		fprintf(fp, "%d %s %s\n", G->vertexs[160].num, G->vertexs[160].name, G->vertexs[160].introduction);
		G->vertexs[161].num = 161;
		strcpy(G->vertexs[161].name, "161�������š�");
		strcpy(G->vertexs[161].introduction, "6.22");
		fprintf(fp, "%d %s %s\n", G->vertexs[161].num, G->vertexs[161].name, G->vertexs[161].introduction);
		G->vertexs[162].num = 162;
		strcpy(G->vertexs[162].name, "162��������·��");
		strcpy(G->vertexs[162].introduction, "6.23");
		fprintf(fp, "%d %s %s\n", G->vertexs[162].num, G->vertexs[162].name, G->vertexs[162].introduction);
		G->vertexs[163].num = 163;
		strcpy(G->vertexs[163].name, "163������壩");
		strcpy(G->vertexs[163].introduction, "6.24");
		fprintf(fp, "%d %s %s\n", G->vertexs[163].num, G->vertexs[163].name, G->vertexs[163].introduction);
		G->vertexs[164].num = 164;
		strcpy(G->vertexs[164].name, "164������·��");
		strcpy(G->vertexs[164].introduction, "6.25");
		fprintf(fp, "%d %s %s\n", G->vertexs[164].num, G->vertexs[164].name, G->vertexs[164].introduction);
		G->vertexs[165].num = 165;
		strcpy(G->vertexs[165].name, "165������·��");
		strcpy(G->vertexs[165].introduction, "6.26");
		fprintf(fp, "%d %s %s\n", G->vertexs[165].num, G->vertexs[165].name, G->vertexs[165].introduction);
		G->vertexs[166].num = 166;
		strcpy(G->vertexs[166].name, "166����һ·��");
		strcpy(G->vertexs[166].introduction, "6.27");
		fprintf(fp, "%d %s %s\n", G->vertexs[166].num, G->vertexs[166].name, G->vertexs[166].introduction);
		G->vertexs[167].num = 167;
		strcpy(G->vertexs[167].name, "167����֯�ǡ�");
		strcpy(G->vertexs[167].introduction, "6.28");
		fprintf(fp, "%d %s %s\n", G->vertexs[167].num, G->vertexs[167].name, G->vertexs[167].introduction);


		for (i = 1; i <= G->vexnum; i++)
		for (j = 1; j <= G->vexnum; j++)
			G->arcs[i][j].adj = INT_MAX;
		for (i = 1; i <= G->vexnum; i++)
		G->arcs[i][i].adj = 0;

		G->arcs[1][2].adj = G->arcs[2][1].adj = G->arcs[2][3].adj = G->arcs[3][2].adj = G->arcs[3][4].adj = G->arcs[4][3].adj = G->arcs[4][5].adj = G->arcs[5][4].adj = G->arcs[5][6].adj = G->arcs[6][5].adj = 1;
		G->arcs[6][7].adj = G->arcs[7][6].adj = G->arcs[7][8].adj = G->arcs[8][7].adj = G->arcs[8][9].adj = G->arcs[9][8].adj = G->arcs[9][10].adj = G->arcs[10][9].adj = G->arcs[10][11].adj = G->arcs[11][10].adj = 1;
		G->arcs[11][12].adj = G->arcs[12][11].adj = G->arcs[12][13].adj = G->arcs[13][12].adj = G->arcs[13][14].adj = G->arcs[14][13].adj = G->arcs[14][15].adj = G->arcs[15][14].adj = G->arcs[15][16].adj = G->arcs[16][15].adj = 1;
		G->arcs[16][17].adj = G->arcs[17][16].adj = G->arcs[17][18].adj = G->arcs[18][17].adj = G->arcs[18][19].adj = G->arcs[19][18].adj = G->arcs[19][20].adj = G->arcs[20][19].adj = G->arcs[20][21].adj = G->arcs[21][20].adj = 1;
		G->arcs[21][22].adj = G->arcs[22][21].adj = G->arcs[22][23].adj = G->arcs[23][22].adj = G->arcs[23][24].adj = G->arcs[24][23].adj = G->arcs[24][25].adj = G->arcs[25][24].adj = 1;

		G->arcs[26][27].adj = G->arcs[27][26].adj = G->arcs[27][28].adj = G->arcs[28][27].adj = G->arcs[28][29].adj = G->arcs[29][28].adj = G->arcs[29][30].adj = G->arcs[30][29].adj = G->arcs[30][31].adj = G->arcs[31][30].adj = 1;
		G->arcs[31][32].adj = G->arcs[32][31].adj = G->arcs[32][33].adj = G->arcs[33][32].adj = G->arcs[33][34].adj = G->arcs[34][33].adj = G->arcs[34][35].adj = G->arcs[35][34].adj = G->arcs[35][36].adj = G->arcs[36][35].adj = 1;
		G->arcs[36][37].adj = G->arcs[37][36].adj = G->arcs[37][38].adj = G->arcs[38][37].adj = G->arcs[38][39].adj = G->arcs[39][38].adj = G->arcs[39][40].adj = G->arcs[40][39].adj = G->arcs[40][41].adj = G->arcs[41][40].adj = 1;
		G->arcs[41][42].adj = G->arcs[42][41].adj = G->arcs[42][43].adj = G->arcs[43][42].adj = G->arcs[43][44].adj = G->arcs[44][43].adj = G->arcs[44][45].adj = G->arcs[45][44].adj = G->arcs[45][46].adj = G->arcs[46][45].adj = 1;
		G->arcs[46][47].adj = G->arcs[47][46].adj = G->arcs[47][48].adj = G->arcs[48][47].adj = G->arcs[48][49].adj = G->arcs[49][48].adj = 1;

		G->arcs[50][51].adj = G->arcs[51][50].adj = G->arcs[51][52].adj = G->arcs[52][51].adj = G->arcs[52][53].adj = G->arcs[53][52].adj = G->arcs[53][54].adj = G->arcs[54][53].adj = G->arcs[54][55].adj = G->arcs[55][54].adj = 1;
		G->arcs[55][56].adj = G->arcs[56][55].adj = G->arcs[56][57].adj = G->arcs[57][56].adj = G->arcs[57][58].adj = G->arcs[58][57].adj = G->arcs[58][59].adj = G->arcs[59][58].adj = G->arcs[59][60].adj = G->arcs[60][59].adj = 1;
		G->arcs[60][61].adj = G->arcs[61][60].adj = G->arcs[61][62].adj = G->arcs[62][61].adj = G->arcs[62][63].adj = G->arcs[63][62].adj = G->arcs[63][64].adj = G->arcs[64][63].adj = G->arcs[64][65].adj = G->arcs[65][64].adj = 1;
		G->arcs[65][66].adj = G->arcs[66][65].adj = G->arcs[66][67].adj = G->arcs[67][66].adj = G->arcs[67][68].adj = G->arcs[68][67].adj = G->arcs[68][69].adj = G->arcs[69][68].adj = G->arcs[69][70].adj = G->arcs[70][69].adj = 1;
		G->arcs[70][71].adj = G->arcs[71][70].adj = G->arcs[71][72].adj = G->arcs[72][71].adj = G->arcs[72][73].adj = G->arcs[73][72].adj = G->arcs[73][74].adj = G->arcs[74][73].adj = G->arcs[74][75].adj = G->arcs[75][74].adj = 1;
		G->arcs[75][76].adj = G->arcs[76][75].adj = G->arcs[76][77].adj = G->arcs[77][76].adj = G->arcs[77][78].adj = G->arcs[78][77].adj = 1;

		G->arcs[79][80].adj = G->arcs[80][79].adj = G->arcs[80][81].adj = G->arcs[81][80].adj = G->arcs[81][82].adj = G->arcs[82][81].adj = G->arcs[82][83].adj = G->arcs[83][82].adj = G->arcs[83][84].adj = G->arcs[84][83].adj = 1;
		G->arcs[84][85].adj = G->arcs[85][84].adj = G->arcs[85][86].adj = G->arcs[86][85].adj = G->arcs[86][87].adj = G->arcs[87][86].adj = G->arcs[87][88].adj = G->arcs[88][87].adj = G->arcs[88][89].adj = G->arcs[89][88].adj = 1;
		G->arcs[89][90].adj = G->arcs[90][89].adj = G->arcs[90][91].adj = G->arcs[91][90].adj = G->arcs[91][92].adj = G->arcs[92][91].adj = G->arcs[92][93].adj = G->arcs[93][92].adj = G->arcs[93][94].adj = G->arcs[94][93].adj = 1;
		G->arcs[94][95].adj = G->arcs[95][94].adj = G->arcs[95][96].adj = G->arcs[96][95].adj = G->arcs[96][97].adj = G->arcs[97][96].adj = G->arcs[97][98].adj = G->arcs[98][97].adj = G->arcs[98][99].adj = G->arcs[99][98].adj = 1;
		G->arcs[99][100].adj = G->arcs[100][99].adj = G->arcs[100][101].adj = G->arcs[101][100].adj = G->arcs[101][102].adj = G->arcs[102][101].adj = G->arcs[102][103].adj = G->arcs[103][102].adj = G->arcs[103][104].adj = G->arcs[104][103].adj = 1;
		G->arcs[104][105].adj = G->arcs[105][104].adj = G->arcs[105][106].adj = G->arcs[106][105].adj = G->arcs[106][107].adj = G->arcs[107][106].adj = 1;

		G->arcs[108][109].adj = G->arcs[109][108].adj = G->arcs[109][110].adj = G->arcs[110][109].adj = G->arcs[110][111].adj = G->arcs[111][110].adj = G->arcs[111][112].adj = G->arcs[112][111].adj = G->arcs[112][113].adj = G->arcs[113][112].adj = 1;
		G->arcs[113][114].adj = G->arcs[114][113].adj = G->arcs[114][115].adj = G->arcs[115][114].adj = G->arcs[115][116].adj = G->arcs[116][115].adj = G->arcs[116][117].adj = G->arcs[117][116].adj = G->arcs[117][118].adj = G->arcs[118][117].adj = 1;
		G->arcs[118][119].adj = G->arcs[119][118].adj = G->arcs[119][120].adj = G->arcs[120][119].adj = G->arcs[120][121].adj = G->arcs[121][120].adj = G->arcs[121][122].adj = G->arcs[122][121].adj = G->arcs[122][123].adj = G->arcs[123][122].adj = 1;
		G->arcs[123][124].adj = G->arcs[124][123].adj = G->arcs[124][125].adj = G->arcs[125][124].adj = G->arcs[125][126].adj = G->arcs[126][125].adj = G->arcs[126][127].adj = G->arcs[127][126].adj = G->arcs[127][128].adj = G->arcs[128][127].adj = 1;
		G->arcs[128][129].adj = G->arcs[129][128].adj = G->arcs[129][130].adj = G->arcs[130][129].adj = G->arcs[130][131].adj = G->arcs[131][130].adj = G->arcs[131][132].adj = G->arcs[132][131].adj = G->arcs[132][133].adj = G->arcs[133][132].adj = 1;
		G->arcs[133][134].adj = G->arcs[134][133].adj = G->arcs[134][135].adj = G->arcs[135][134].adj = G->arcs[135][136].adj = G->arcs[136][135].adj = G->arcs[136][137].adj = G->arcs[137][136].adj = G->arcs[137][138].adj = G->arcs[138][137].adj = G->arcs[138][139].adj = G->arcs[139][138].adj = 1;

		G->arcs[140][141].adj = G->arcs[141][140].adj = G->arcs[141][142].adj = G->arcs[142][141].adj = G->arcs[142][143].adj = G->arcs[143][142].adj = G->arcs[143][144].adj = G->arcs[144][143].adj = G->arcs[144][145].adj = G->arcs[145][144].adj = 1;
		G->arcs[145][146].adj = G->arcs[146][145].adj = G->arcs[146][147].adj = G->arcs[147][146].adj = G->arcs[147][148].adj = G->arcs[148][147].adj = G->arcs[148][149].adj = G->arcs[149][148].adj = G->arcs[149][150].adj = G->arcs[150][149].adj = 1;
		G->arcs[150][151].adj = G->arcs[151][150].adj = G->arcs[151][152].adj = G->arcs[152][151].adj = G->arcs[152][153].adj = G->arcs[153][152].adj = G->arcs[153][154].adj = G->arcs[154][153].adj = G->arcs[154][155].adj = G->arcs[155][154].adj = 1;
		G->arcs[155][156].adj = G->arcs[156][155].adj = G->arcs[156][157].adj = G->arcs[157][156].adj = G->arcs[157][158].adj = G->arcs[158][157].adj = G->arcs[158][159].adj = G->arcs[159][158].adj = G->arcs[159][160].adj = G->arcs[160][159].adj = 1;
		G->arcs[160][161].adj = G->arcs[161][160].adj = G->arcs[161][162].adj = G->arcs[162][161].adj = G->arcs[162][163].adj = G->arcs[163][162].adj = G->arcs[163][164].adj = G->arcs[164][163].adj = G->arcs[164][165].adj = G->arcs[165][164].adj = 1;
		G->arcs[165][166].adj = G->arcs[166][165].adj = G->arcs[166][167].adj = G->arcs[167][166].adj = 1;

		G->arcs[14][38].adj = G->arcs[38][14].adj = G->arcs[18][62].adj = G->arcs[62][18].adj = G->arcs[43][69].adj = G->arcs[69][43].adj = G->arcs[32][85].adj = G->arcs[85][32].adj = G->arcs[15][94].adj = G->arcs[94][15].adj = 0;
		G->arcs[68][99].adj = G->arcs[99][68].adj = G->arcs[41][129].adj = G->arcs[129][41].adj = G->arcs[97][131].adj = G->arcs[131][97].adj = G->arcs[66][134].adj = G->arcs[134][66].adj = G->arcs[72][153].adj = G->arcs[153][72].adj = 0;
		G->arcs[126][154].adj = G->arcs[154][126].adj = G->arcs[158][39].adj = G->arcs[39][158].adj = G->arcs[95][159].adj = G->arcs[159][95].adj = G->arcs[64][161].adj = G->arcs[161][64].adj = G->arcs[23][167].adj = G->arcs[167][23].adj = 0;


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

void map()
{
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                             ��ӭ��������������                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	printf("��                                                                                                                                                                                                                                                                                                                                                       ��\n");
	printf("��                                                                                                                                                                                                                        �ڣ��¼ұ���                                                                                                                   ��\n");
	printf("��                                                                                                                                                                                                                           /                                                                                                                           ��\n");
	printf("��                                                                                                                                                                                                                          /                                                                                                                            ��\n");
	printf("��                                                                                                                                                                                    �ܣ����·������                ����̲��                                                                     �ۣ���˰����                                        ��\n");
	printf("��                                                                                                                                                                                                     \\               /                                                                                /                                  �٣�������    ��\n");
	printf("��                                                                                                                                                                                               ����Է·��        ������¡��                                                                       ��������                                    /        ��\n");
	printf("��                                                                                                                                                                                                    |               /                                                                                /                                       /         ��\n");
	printf("��                                                                                                                                                                                               ������·��      ������վ��                                                                       ��˫կ��                                    /          ��\n");
	printf("��                                                                                                                                                                                                    |               \\                                                                             /                                        /           ��\n");
	printf("��                                                                                                                                                                                             �����ʮ��·��      ����Է��                                                                   �����ʸ�������                                /            ��\n");
	printf("��                                                                                                                                                                                                    |                |                                                                             \\                                     /             ��\n");
	printf("��                                                                                                                             �٣�ɭ�ֹ�԰������                                              ����Ǿ�·��      ���˶���԰��                                                                      ����ׯ��                               /              ��\n");
	printf("��                                                                                                                                                \\                                                   \\                |                                                                               \\                                 /               ��\n");
	printf("��                                                                                                                                              ���涫·��                                          ���ľ�·���������������ġ���������·������                                                          \\                               /                ��\n");
	printf("��                                                                                                                                                    \\                                                                |                       \\                                                        |                          �����죩              ��\n");
	printf("��                                                                                                                                                ������·��                                                           |                    ������·��                                              ������԰��                       /                   ��\n");
	printf("��                                                                                                                                                      \\                                                        �������·��                  |                                                        |                           /                    ��\n");
	printf("��                                                                                                                                                  ���żҴ壩                                                         |                    ���ٻ��壩                                             ��������ģ�                    /                     ��\n");
	printf("��                                                                                                                                                        \\                                                            |                        |                                                       /                         /                      ��\n");
	printf("��                                                                                                                                                    ������կ��                                                  ����ͼ��ݣ�              ���ܼ���                               ������̩�ţ������һ�̶��                    /                       ��\n");
	printf("��                                                                                                                                                          \\                                                          |                        |                                   /                                           /                        ��\n");
	printf("��                                                                                                                                                       ����ջ��                                                      |                    ������·��                         ��������                                ������֯�ǡ�                    ��\n");
	printf("��                                                                                                                                                            \\                                                  ������������                  |                                   |                                    /         |                      ��\n");
	printf("��                                                                                                                                                         ����ӣ�                                                    |                    ����������                             |                               �������£�     |                      ��\n");
	printf("��                                                                                                                                                              \\                                                 ������ԭ��                   |                              ��ʯ�ҽ֣�                         /                |                      ��\n");
	printf("��                                                                                                                                                           ����԰��                                                  |                    ����Ԫ·��                             |                        �������ӣ�            |                      ��\n");
	printf("��                                                                                                                                                                \\                                                    |                       /                                   |                       /                  ����һ·��                 ��\n");
	printf("��                                                                                                                                                            ������·��                                            (��Զ��)             ��������վ��                          ��������           ���������£�                  |                      ��\n");
	printf("��                                                                                                                                                                  \\                                                  |                      |                                    |               /                              |                      ��\n");
	printf("��                                                                                                                                                                ����Զ�ţ������Ͷ�·�����������ţ� ��������¥����������֡�������������������·�ڡ����������ţ���������·������ͨ���š���������·��                             |                      ��\n");
	printf("��                                                                                                                                                                                                                     |                      |                                    |                                              |                      ��\n");
	printf("��                                                                                                      ����ƽ�壩������������������Ҥͷ������������·����������԰������                  ���������֣���������֣�������¥����������������������С� �����������������֣�     �����ֹ�԰��                                  ��������·��                 ��\n");
	printf("��                                                                                                         /                                                             \\                 /                           |                      |                       \\            |                                       /                             ��\n");
	printf("��                         �������ͣ��������̣��������ţ�����������������ţ�Ǵ壩�����侩���������壩����                                                         ��������·��    ������·��                     �������ţ�             ����ƽ�ţ�                     �������������š�����������·����������壩��������·��                          ��\n");
	printf("��                              /                                                                                                                                           \\        /                                 |                      |                                    |                                                                     ��\n");
	printf("��                        �������ɣ�                                                                                                                                       ���Ͷ���·���������߼Ҵ壩��������壩���������š�����Ů��·��������Ҵ塿����̫��·����������·��  �������ţ�                                                                ��\n");
	printf("��                             |                                                              �ۣ��Ϸᣩ����������կ���������ׯ�������㻯կ�������ɰ˱�·��������ƽ�ţ�\\     /                                        |                      |                          \\        /                                                                      ��\n");
	printf("��                         ����ׯ��                                                                                                                                       \\���Ƽ�·��                              ����������             ����壩                       �������¡�              �����µǸ�                                            ��\n");
	printf("��                            /                                                                                                                                              /   \\��̫����·��\\                        |                      |                          /        \\             /          \\                                             ��\n");
	printf("���ݣ���Ҧ������ʷ�ұ���������ׯ��                                                                                                                                          /                     ������������壩����Сկ������������������������������������������������ͷ��   ������կ��  ������·��     ����֯�ǻ�վ��                             ��\n");
	printf("��                                                                                                                                                                   ���Ƽ���·��                                      |                       \\                                       \\     /                                                           ��\n");
	printf("��                                                                                                                                                                        /                                         (γһ��)              ������ܽ��԰��                              ���ټ�կ��                                                         ��\n");
	printf("��                                                                                                                                                                  ��ľ���£�                                         |                         \\                                                                                                       ��\n");
	printf("��                                                                                                                                                                       |                                         (��չ����)                 �������أ�                                                                                                 ��\n");
	printf("��                                                                                                                                                                 ��ʡ��Ӿ�ݣ�                                        |                         /                                                                                                       ��\n");
	printf("��                                                                                                                                                                       |                                           (��س)                     /                                                                                                        ��\n");
	printf("��                                                                                                                                                                       /                                             |                   ���������                                                                                                    ��\n");
	printf("��                                                                                                                       ����ҵ·�������ɰ���·�������ɰ���·�������ɰ�һ·��                                          |                       |                                                                                                         ��\n");
	printf("��                                                                                                                          /                                                                                      ������ԭ)              ����������                                                                                                   ��\n");
	printf("��                                                                                                                  ����ҵ��·��                                                                                       |                       |                                                                                                         ��\n");
	printf("��                                                                                                                        |                                                                                        ������ǣ�              ������·��                                                                                                    ��\n");
	printf("��                                                                                                                  �����������                                                                                       |                       |                                                                                                         ��\n");
	printf("��                                                                                                                        |                                                                                            |                   ������·��                                                                                                    ��\n");
	printf("��                                                                                                                  ��γʮ��·��                                                                                       |                        \\                                                                                                        ��\n");
	printf("��                                                                                                                    /                                                                                          �ڣ�Τ���ϣ�               �����ݴ�������������춫·����                                                                               ��\n");
	printf("��                                                                                                             ��γ��ʮ��·��                                                                                                                                                                                                                            ��\n");
	printf("��                                                                                                                  /                                                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                            �����£�                                                                                                                                                                                                                                   ��\n");
	printf("��                                                                                                                /                                                                                                                                                                                                                                      ��\n");
	printf("��                                                                                                        �ޣ��Ͽ�վ��                                                                                                                                                                                                                                   ��\n");
	printf("��                                                                                                                                                                                                                                                                                                                                                       ��\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");

	printf("\n");
	fflush(stdin);
}/*map*/