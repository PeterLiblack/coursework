#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define N 2000
//结点结构体
typedef struct{
	double weight;//结点权值
	unsigned int parent,lchild,rchild;
	unsigned char ch;//结点值
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;//动态分配数组存储哈弗曼编码表
 
typedef struct{//字符结构体
	unsigned char ch;//字符值
	unsigned int num;//字符个数
	double frequent;//字符频率
}list;
 
HuffmanTree HT;//全局变量
list l[N];//全局变量
HuffmanCode HC;	//全局变量
 
  //	//在HT[1...end]选择weigt最小的两个结点，其序号分别为s1和s2.
void Select(HuffmanTree HT,int end,int &s1,int &s2){
	double min=1.0;
	for(int i=1;i<=end;i++){
		if(HT[i].parent==0&&HT[i].weight<min){
			s1=i;
			min=HT[i].weight ;
		}
	}
	min=1.0;
	for(i=1;i<=end;i++){
		if(HT[i].parent ==0&&HT[i].weight <min&&i!=s1){
			s2=i;
			min=HT[i].weight ;
 
		}
	}
 
}
//创建哈弗曼树
void HuffmanCoding(int n){
	//w存放n个字符的权值（均>0）,构造哈弗曼树HT,str存放n个字符
	int i,m,s1,s2;
	if(n<=1)
		return;
	m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//0号单元未用
	for(i=1;i<=n;++i){
		HT[i].ch=l[i].ch;
		HT[i].weight =l[i].frequent;
		HT[i].parent =0;
		HT[i].lchild =0;
		HT[i].rchild =0;
	}
	for(;i<=m;++i){
		HT[i].parent =0;
		HT[i].lchild =0;
		HT[i].rchild =0;
	}
 
	for(i=n+1;i<=m;++i){
		Select(HT,i-1,s1,s2);
		HT[s1].parent =i;
		HT[s2].parent =i;
		HT[i].lchild =s1;
		HT[i].rchild =s2;
		HT[i].weight =HT[s1].weight +HT[s2].weight ;
	}
}
	
//编码
void Encode(int n){
	FILE *fp,*fw;
	char code;
	if((fp=fopen("huff1.txt","r"))==NULL)
		printf("huff1.txt文件打开失败！");
	if((fw=fopen("encode.txt","w+"))==NULL)
		printf("encode.txt文件打开失败！");
	char *cd;//存放一个Huffman编码的临时空间
	int start;//Huffman编码在临时空间cd中的起始下标
	unsigned int c,f;//c,f互为父子节点
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	cd=(char*)malloc(n*sizeof(char));//为临时空间分配存储空间（n个叶结点形成的HUffamnTree深度一定不会超过n）
	cd[n-1]='\0';//设置字符串结束标记
	
	for(int i=1;i<=n;++i){
		start=n-1;
		for(c=i,f=HT[i].parent ;f!=0;c=f,f=HT[f].parent ){
			if(HT[f].lchild ==c)
				cd[--start]='0';
			else
				cd[--start]='1';
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));//为第i个字符编码设置空间
		strcpy(HC[i],&cd[start]);//从cd复制编码到HC
	}
	free(cd);
	fscanf(fp,"%c",&code);//从文件中读入第一个字符
	while(!feof(fp)){
		for(int i=1;i<=n;i++)
			if(HT[i].ch==code)
				break;
			for(int r=0;HC[i][r]!='\0';r++)
				fputc(HC[i][r],fw);
			fscanf(fp,"%c",&code);
	}
	fclose(fw);
	fclose(fp);
	printf("编码成功，并存入encode.txt中");
}
 
 
//解码
void Decode(int n){
	FILE *fp,*fw;
	char code;
	int i,j;
	if((fp=fopen("encode.txt","r"))==NULL)
	printf("encode.txt文件打开失败!");
	if((fw=fopen("decode.txt","w+"))==NULL)
	printf("decode.txt文件打开失败!");
	i=j=2*n-1;//从根结点向下搜索
	fscanf(fp,"%c",&code);
	while(!feof(fp)){
		if(code=='0')
			i=HT[i].lchild ;//走向左孩子
		else
			i=HT[i].rchild ;//走向右孩子
		if(HT[i].lchild ==0&&HT[i].rchild ==0)//HT[i]是叶结点
		{
			fputc(HT[i].ch,fw);
			i=j;//回到根结点
		}
		fscanf(fp,"%c",&code);//读入下一个字符
	}
	printf("解码成功，并存入decode.txt中\n");
	fclose(fp);
	fclose(fw);
}
void Compare(int n){
	FILE *fp,*fw;
	char str1[N],str2[N];
	int i=1;
	if((fp=fopen("huff1.txt","r"))==NULL)
	printf("huff1.txt文件打开失败!");
	if((fw=fopen("decode.txt","r"))==NULL)
	printf("decode.txt文件打开失败!");
    fscanf(fp,"%c",&str1);
	fscanf(fw,"%c",&str2);
	while(i<n){
		if(str1[i]==str2[i]){
			fscanf(fp,"%c",&str1);//读入下一个字符
			fscanf(fw,"%c",&str2);//读入下一个字符
			i++;
		}
		else
		{
			printf("huff1.txt文件与decode.txt文件不一样，失败!");
			break;
		}
		if(i==n)
		{
			printf("huff1.txt文件与decode.txt文件一样，成功!");
			break;
		}
	}
	fclose(fp);
	fclose(fw);
}
 
//统计字符总数和出现频率
int counte(){
	int type=0;//字符种类数
	int i=0;
	double w[]={0};
	unsigned char file[N]={0};
	int num[N]={0};
	FILE *fp;
	if((fp=fopen("huff1.txt","r"))==NULL)
	{
		printf("打开文件失败!");
	}
	while(!feof(fp))
		fread(&file[i++],sizeof(char),1,fp);
	fclose(fp);
	int n=i-1;
	for(i=1;i<N;i++){
		l[i].num=0;
		l[i].frequent=0.0;
	}
	printf("huff1.txt文件中字符一共%d个!\n",n);
	for(i=0;i<n;i++){
		for(int j=1;j<=type;j++){
			if(file[i] == l[j].ch)  
            {  
                l[j].num++;  
                break;  
            }  
        }
		if(j==type+1){
			l[j].ch=file[i];
			l[j].num++;
			type++;
		}
	}
	for(i=1;i<=type;i++){
		l[i].frequent=(double)l[i].num/(double)n;
		printf("字符%c的个数为%2d,出现频率是%lf\n",l[i].ch,l[i].num,l[i].frequent);
	}
	printf("其他字符出现个数与频率都是0");
	return type;
 
}
int main(){
	char choose;
	HuffmanTree HT;
	int n=counte();
	HuffmanCoding(n);
	while(1){
		printf("请选择:\n");  
        printf("\t1.编码\n");  
        printf("\t2.解码\n");  
		printf("\t3.比较结果\n");
        printf("\t4.结束\n"); 
		scanf("%c", &choose);   
		switch(choose){
		case '1':Encode(n);
			break;
		case '2':Decode(n);
			break;
		case '3':Compare(n);
			break;
		case '4':return;
		}
	}
	//return 0;

}