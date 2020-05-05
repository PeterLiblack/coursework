#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>  //getch()
#include<stdlib.h> //exit()
#include<string.h>
//#include<limits.h> //∞
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

GraphType *create(GraphType *G)  //创建无向图
{
	int i, j;
	if ((fp = fopen("D:\\file.txt", "wt+")) == NULL)
	{
		printf("\nerror on open D:\\file.txt file!");
//		getch();   //暂停程序
		exit(0);   //非正常运行导致退出程序
	}
	else
	{
		G = (GraphType *)malloc(sizeof(GraphType));
		G->vexnum = 16;
		G->arcnum = 29;
		G->vertexs[1].num = 1;
		strcpy(G->vertexs[1].name, "学校正门");
		strcpy(G->vertexs[1].introduction, "坐落于临潼区陕鼓大道48号，对面为群星莱骊，市井繁华，交通便利。");
		fprintf(fp, "%d %s %s\n", G->vertexs[1].num, G->vertexs[1].name, G->vertexs[1].introduction);
		G->vertexs[2].num = 2;
		strcpy(G->vertexs[2].name, "教学东区");
		strcpy(G->vertexs[2].introduction, "1-3号教学楼，还包括实验楼、煤炭楼等。");
		fprintf(fp, "%d %s %s\n", G->vertexs[2].num, G->vertexs[2].name, G->vertexs[2].introduction);
		G->vertexs[3].num = 3;
		strcpy(G->vertexs[3].name, "砚池");
		strcpy(G->vertexs[3].introduction, "西安科技大学临潼校区的一大景点，环境清幽，水色秀丽。");
		fprintf(fp, "%d %s %s\n", G->vertexs[3].num, G->vertexs[3].name, G->vertexs[3].introduction);
		G->vertexs[4].num = 4;
		strcpy(G->vertexs[4].name, "教学西区");
		strcpy(G->vertexs[4].introduction, "9-18号教学楼，包括计算机学院和创新实验基地等。");
		fprintf(fp, "%d %s %s\n", G->vertexs[4].num, G->vertexs[4].name, G->vertexs[4].introduction);
		G->vertexs[5].num = 5;
		strcpy(G->vertexs[5].name, "3、4、5号学生公寓");
		strcpy(G->vertexs[5].introduction, "3、4、5号学生公寓，均为女生宿舍公寓楼。");
		fprintf(fp, "%d %s %s\n", G->vertexs[5].num, G->vertexs[5].name, G->vertexs[5].introduction);
		G->vertexs[6].num = 6;
		strcpy(G->vertexs[6].name, "图书馆");
		strcpy(G->vertexs[6].introduction, "历史悠久，文化积淀。供同学安静学习的环境。");
		fprintf(fp, "%d %s %s\n", G->vertexs[6].num, G->vertexs[6].name, G->vertexs[6].introduction);
		G->vertexs[7].num = 7;
		strcpy(G->vertexs[7].name, "雁林");
		strcpy(G->vertexs[7].introduction, "这里绿意盎然，鸟语花香，是人放松身心的好地方。");
		fprintf(fp, "%d %s %s\n", G->vertexs[7].num, G->vertexs[7].name, G->vertexs[7].introduction);
		G->vertexs[8].num = 8;
		strcpy(G->vertexs[8].name, "体育馆");
		strcpy(G->vertexs[8].introduction, "馆内有室内羽毛球以及乒乓球等各种运动场地，为我们本校学生提供了很好的锻炼条件，丰富课余生活");
		fprintf(fp, "%d %s %s\n", G->vertexs[8].num, G->vertexs[8].name, G->vertexs[8].introduction);
		G->vertexs[9].num = 9;
		strcpy(G->vertexs[9].name, "榴馨苑");
		strcpy(G->vertexs[9].introduction, "西科新网红，颇具情调的灯彩、五彩缤纷的食材，被称为是别人的大学餐厅。");
		fprintf(fp, "%d %s %s\n", G->vertexs[9].num, G->vertexs[9].name, G->vertexs[9].introduction);
		G->vertexs[10].num = 10;
		strcpy(G->vertexs[10].name, "1、2号学生公寓");
		strcpy(G->vertexs[10].introduction, "1、2号宿舍楼，1号宿舍楼为男生宿舍公寓楼，2号宿舍楼为女生宿舍公寓楼。");
		fprintf(fp, "%d %s %s\n", G->vertexs[10].num, G->vertexs[10].name, G->vertexs[10].introduction);
		G->vertexs[11].num = 11;
		strcpy(G->vertexs[11].name, "综合楼");
		strcpy(G->vertexs[11].introduction, "既是财务处的所在地，也是校医院的落脚点，同学们看病拿药的地方，提供便利。");
		fprintf(fp, "%d %s %s\n", G->vertexs[11].num, G->vertexs[11].name, G->vertexs[11].introduction);
		G->vertexs[12].num = 12;
		strcpy(G->vertexs[12].name, "6、7号学生公寓");
		strcpy(G->vertexs[12].introduction, "6、7号公寓，是聚合两栋楼为一栋的男生宿舍公寓楼。");
		fprintf(fp, "%d %s %s\n", G->vertexs[12].num, G->vertexs[12].name, G->vertexs[12].introduction);
		G->vertexs[13].num = 13;
		strcpy(G->vertexs[13].name, "田径场");
		strcpy(G->vertexs[13].introduction, "田径场主要进行室外的体育运动，以及举办运动会等项目的场地，也是跑步的主要场地。");
		fprintf(fp, "%d %s %s\n", G->vertexs[13].num, G->vertexs[13].name, G->vertexs[13].introduction);
		G->vertexs[14].num = 14;
		strcpy(G->vertexs[14].name, "骊绣苑");
		strcpy(G->vertexs[14].introduction, "为学生自助餐厅，整洁明亮，温馨舒适的就餐环境与细致的服务为师生带来了新的就餐体验。");
		fprintf(fp, "%d %s %s\n", G->vertexs[14].num, G->vertexs[14].name, G->vertexs[14].introduction);
		G->vertexs[15].num = 15;
		strcpy(G->vertexs[15].name, "球场");
		strcpy(G->vertexs[15].introduction, "用于网球、篮球的日常上课的地方，此外，也是大家进行体育切磋、娱乐健身的场地。");
		fprintf(fp, "%d %s %s\n", G->vertexs[15].num, G->vertexs[15].name, G->vertexs[15].introduction);
		G->vertexs[16].num = 16;
		strcpy(G->vertexs[16].name, "游泳馆");
		strcpy(G->vertexs[16].introduction, "该地区为游泳课教学区域，同学们可以更好地掌握游泳这项技能。");
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

AdjList *list(GraphType *G, AdjList *g)  //邻接矩阵转化为邻接表
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
			p->next = g->vextexs[i].firstarc;   //头插法
			g->vextexs[i].firstarc = p;
		}
	}
	g->vexnum = G->vexnum;
	g->arcnum = G->arcnum;
	return g;
}

void inquiry(GraphType *G)   //查询景点信息
{
	int n;
	printf("您想查询的景点编号为：");
	scanf("%d", &n);
	printf("%d,%s", G->vertexs[n].num, G->vertexs[n].name);
	printf("\n景点介绍:\n");
	printf("%s", G->vertexs[n].introduction);
}
void shortest(GraphType *G, int P[][MAX], int D[][MAX]) //最短路径
{
	int m, n;
	printf("您希望查询哪两点?\n");
	scanf("%d", &m);
	printf("与\n");
	scanf("%d", &n);
	fflush(stdin);
	if (m<n)
	{
		printf("%s与%s之间的最短路径长度为%d\n", G->vertexs[m].name, G->vertexs[n].name, D[m][n]);
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
		printf("%s与%s之间的最短路径长度为%d\n", G->vertexs[m].name, G->vertexs[n].name, D[m][n]);
	}
}

void floyd(GraphType *G)   //弗洛伊德
{
	int D[MAX][MAX];
	int P[MAX][MAX];
	//P[i][j]为i到j的当前最短路径，D[i][j]记录路径长度
	int i, j, k;
	for (j = 1; j <= G->vexnum; j++)
	{
		for (k = 1; k <= G->vexnum; k++)
		{
			D[j][k] = G->arcs[j][k].adj;  //初始化D
			P[j][k] = 0;         //初始化P
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
					P[k][j] = i;  //记录经过的路径
				}
			}
		}
	}
	shortest(G, P, D);
}
void allpath(GraphType *G, AdjList *g, int m, int n, int path[], int d) //两景点间所有路径
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
void getallpath(GraphType *G, AdjList *g)  //得出所有路径
{
	int m, n;
	int path[MAX];
	printf("您希望查询哪两点?");
	scanf("%d", &m);
	printf("与");
	scanf("%d", &n);
	allpath(G, g, m, n, path, -1);
}

void add(GraphType *G, FILE *fp)   //增加景点
{
	int length, i;
	fp = fopen("D:\\file.txt", "at+");
	G->vexnum = G->vexnum + 1;
	G->vertexs[G->vexnum].num = G->vexnum;
	printf("请输入新增景点名字：");
	scanf("%s", G->vertexs[G->vexnum].name);
	printf("请输入新增景点介绍：");
	scanf("%s", G->vertexs[G->vexnum].introduction);
	fprintf(fp, "%d %s %s", G->vertexs[G->vexnum].num, G->vertexs[G->vexnum].name, G->vertexs[G->vexnum].introduction);
	printf("新增景点编号为：");
	printf("%d", G->vertexs[G->vexnum].num);
	printf("请输入该景点到其他各景点的路径\n");
	for (i = 1; i <= G->vexnum; i++)
	{
		printf("到%d号景点的路径长度（若不相邻，则输入INT_MAX）：", i);
		scanf("%d\t", &length);
		G->arcs[G->vexnum][i].adj = G->arcs[i][G->vexnum].adj = length;
	}
	fclose(fp);
}

void update(GraphType *G, FILE *fp)   //更新景点信息
{
	int num0, num, num1;
	fp = fopen("D:\\file.txt", "at+");
	printf("请输入所修改景点编号");
	scanf("%d", &num0);
	printf("您要更改的是1、名称  2、简介  3、两景点间路径\n请输入编号：");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("请输入修改后的名称");
		scanf("%s", G->vertexs[num0].name);
		break;
	case 2:
		printf("请输入修改后的简介");
		scanf("%s", G->vertexs[num0].introduction);
		break;
	case 3:
		printf("您想修改该点到哪点的路径\n请输入：");
		scanf("%d", &num1);
		printf("您想1、增加路径  2、删除路径  3、修改路径长度\n请输入：");
		scanf("%d", &num1);
		switch (num1)
		{
		case 1:
			printf("该新增路径长度为：");
			scanf("%d", &G->arcs[num0][num1].adj);
			G->arcs[num1][num0].adj = G->arcs[num0][num1].adj;
			break;
		case 2:
			G->arcs[num1][num0].adj = INT_MAX;
			G->arcs[num0][num1].adj = INT_MAX;
			break;
		case 3:
			printf("路径长度修改为");
			scanf("%d", &G->arcs[num0][num1]);
			G->arcs[num1][num0].adj = G->arcs[num0][num1].adj;
			break;
		}
	}
	fclose(fp);
}

void menu()
{
	printf("\t\t菜单\n");
	printf("\t1、查询景点信息\n\t2、查询任意两点最短路径\n\t3、查询任意两点间所有路径\n\t4、增加景点\n\t5、更新景点和道路信息\n");
	printf("\t6、登录\n\t7、注册\n");
	printf("\t注：①只有注册成为管理员才可执行4、5\n\t    ②退出系统请输入0\n");
}
void map()
{
	printf("┃~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~┃\n");
	printf("┃                                                                   ┎---------┒   ┃\n");
	printf("┃                                          ┎---------┒           ___┃16.游泳馆┃   ┃\n");
	printf("┃                                         _┃ 15.     ┃         ╱    ┖---------┚   ┃\n");
	printf("┃                                       ╱  ┃  球  场 ┃_______╱                    ┃\n");
	printf("┃                                     ╱    ┖---------┚                            ┃\n");
	printf("┃                                   ╱              ╲                              ┃\n");
	printf("┃                                 ╱                  ╲                            ┃\n");
	printf("┃                               ╱             ┎----------┒                        ┃\n");
	printf("┃                          ┎-------┒          ┃12. 6、7号┃________         　　   ┃\n");
	printf("┃                  　      ┃14.    ┃----------┃  学生公寓┃        ╲　┎-------┒    ┃\n");
	printf("┃                        ╱ ┃ 骊绣苑┃          ┖----------┚╲         ╲┃13.    ┃    ┃\n");
	printf("┃            　        ╱   ┖-------┚              ┊         ╲        ┃ 田径场┃    ┃\n");
	printf("┃   　　　　┎-------┒　　     ┊                   ┊         　╲      ┖-------┚    ┃\n");
	printf("┃           ┃9.     ┃         ┊              ┎---------┒        ╲                 ┃\n");
	printf("┃           ┃ 榴馨苑┃         ┊             ╱┃11.综合楼┃          ╲               ┃\n");
	printf("┃         ╱ ┖-------┚ ╲    ┎----------┒  ╱   ┖---------┚╲           ╲             ┃\n");
	printf("┃       ╱               ╲  ┃10. 1、2号┃╱          ┊       ╲ ________┎-------┒     ┃\n");
	printf("┃     ╱                   ╲┃ 学生公寓 ┃╲          ┊                 ┃ 8.    ┃     ┃\n");
	printf("┃ ┎-----------┒            ┖----------┚  ╲        ┊              ╱  ┃ 体育馆┃     ┃\n");
	printf("┃ ┃5. 3、4、5 ┃                             ╲ ┎--------┒       ╱    ┖-------┚     ┃\n");
	printf("┃ ┃ 号学生公寓┃   ╲                         __┃6.图书馆┃     ╱          ┊         ┃\n");
	printf("┃ ┖-----------┚     ╲                     ╱   ┖--------┚   ╱            ┊         ┃\n");
	printf("┃                     ╲                 ╱         ┊      ╱              ┊         ┃\n");
	printf("┃                       ╲             ╱           ┊    ╱                ┊         ┃\n");
	printf("┃                         ╲ ┎------┒╱        ┎------┒                   ┊         ┃\n");
	printf("┃                           ┃4.砚池┃┈┈┈┈┈----┃7.雁林┃_____              ┊         ┃\n");
	printf("┃                           ┖------┚         ┖------┚      ╲            ┊         ┃\n");
	printf("┃                                   ╲                        ╲ __┎----------┒     ┃\n");
	printf("┃                                     ╲                          ┃3.教学西区┃     ┃\n");
	printf("┃                                ┎----------┒  _________________╱┖----------┚     ┃\n");
	printf("┃                                ┃2.教学东区┃╱                                    ┃\n");
	printf("┃                                ┖----------┚                                     ┃\n");
	printf("┃                                         ┊                                       ┃\n");
	printf("┃                                         ┊                                       ┃\n");
	printf("┃                                         ┊                                       ┃\n");
	printf("┃                                       ┎----------┒                              ┃\n");
	printf("┃                                       ┃1.学校正门┃                              ┃\n");
	printf("┃                                       ┖----------┚                              ┃\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	printf("\n");
	fflush(stdin);
}/*map*/
void denglu()  //管理员登录系统
{
	FILE *fp;
	int len = 0;
	printf("请输入账号");
	scanf("%s", name);
	printf("请输入密码");
	scanf("%s", pass);
	strcat(name, pass);    //字符串连接 
	strcat(name, "\n");
	fp = fopen("D:\\users0.txt", "at+");
	if (NULL == fp)
	{
		printf("failed to open dos.txt\n");
	}

	while (!feof(fp))  //文件指针到末尾，返回值为非零
	{
		memset(textstring, 0, sizeof(textstring));  //初始化textstring[]
		fgets(textstring, sizeof(textstring)-1, fp); //从指定文件读一个字符串到字符数组中
		if (strcmp(name, textstring) == 0)  //字符串比较
		{
			ok = 1;
			break;
		}
	}
	if (ok)
		printf("    登录成功\n");
	else
		printf("    登录失败\n");
	fclose(fp);

}
void zhuce()
{
	FILE *fp = fopen("D:\\users0.txt", "at+");
	printf("请输入账号");
	scanf("%s", name);
	printf("请输入密码");
	scanf("%s", pass);
	fputs(name, fp);
	fputs(pass, fp);
	fputs("\n", fp);
	fflush(stdin);
	fclose(fp);
	printf("注册成功，请登录\n");
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
		printf("\n请输入您想进行哪一步操作：");
		scanf("%d", &n);
		switch (n)
		{
		case 0:stop = 0;
			printf("\n\t已退出\n\n"); break;
		case 1:inquiry(G);
			printf("\n"); break;
		case 2:floyd(G);
			printf("\n"); break;
		case 3:getallpath(G, g);
			printf("\n"); break;
		case 4:
		case 5:printf("您还不是管理员\n"); break;
		case 6:denglu();
			if (ok)
			{
				menu();
				printf("\n请输入您想进行哪一步操作：");
				scanf("%d", &m);
				switch (m)
				{
				case 0:stop = 0;
					printf("\n\t已退出\n\n"); break;
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
				printf("\n请输入您想进行哪一步操作：");
				scanf("%d", &m);
				switch (m)
				{
				case 0:stop = 0;
					printf("\n\t已退出\n\n"); break;
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
