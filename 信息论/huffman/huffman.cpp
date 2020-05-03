#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define N 2000
//���ṹ��
typedef struct{
	double weight;//���Ȩֵ
	unsigned int parent,lchild,rchild;
	unsigned char ch;//���ֵ
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;//��̬��������洢�����������
 
typedef struct{//�ַ��ṹ��
	unsigned char ch;//�ַ�ֵ
	unsigned int num;//�ַ�����
	double frequent;//�ַ�Ƶ��
}list;
 
HuffmanTree HT;//ȫ�ֱ���
list l[N];//ȫ�ֱ���
HuffmanCode HC;	//ȫ�ֱ���
 
  //	//��HT[1...end]ѡ��weigt��С��������㣬����ŷֱ�Ϊs1��s2.
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
//������������
void HuffmanCoding(int n){
	//w���n���ַ���Ȩֵ����>0��,�����������HT,str���n���ַ�
	int i,m,s1,s2;
	if(n<=1)
		return;
	m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//0�ŵ�Ԫδ��
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
	
//����
void Encode(int n){
	FILE *fp,*fw;
	char code;
	if((fp=fopen("huff1.txt","r"))==NULL)
		printf("huff1.txt�ļ���ʧ�ܣ�");
	if((fw=fopen("encode.txt","w+"))==NULL)
		printf("encode.txt�ļ���ʧ�ܣ�");
	char *cd;//���һ��Huffman�������ʱ�ռ�
	int start;//Huffman��������ʱ�ռ�cd�е���ʼ�±�
	unsigned int c,f;//c,f��Ϊ���ӽڵ�
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	cd=(char*)malloc(n*sizeof(char));//Ϊ��ʱ�ռ����洢�ռ䣨n��Ҷ����γɵ�HUffamnTree���һ�����ᳬ��n��
	cd[n-1]='\0';//�����ַ����������
	
	for(int i=1;i<=n;++i){
		start=n-1;
		for(c=i,f=HT[i].parent ;f!=0;c=f,f=HT[f].parent ){
			if(HT[f].lchild ==c)
				cd[--start]='0';
			else
				cd[--start]='1';
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));//Ϊ��i���ַ��������ÿռ�
		strcpy(HC[i],&cd[start]);//��cd���Ʊ��뵽HC
	}
	free(cd);
	fscanf(fp,"%c",&code);//���ļ��ж����һ���ַ�
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
	printf("����ɹ���������encode.txt��");
}
 
 
//����
void Decode(int n){
	FILE *fp,*fw;
	char code;
	int i,j;
	if((fp=fopen("encode.txt","r"))==NULL)
	printf("encode.txt�ļ���ʧ��!");
	if((fw=fopen("decode.txt","w+"))==NULL)
	printf("decode.txt�ļ���ʧ��!");
	i=j=2*n-1;//�Ӹ������������
	fscanf(fp,"%c",&code);
	while(!feof(fp)){
		if(code=='0')
			i=HT[i].lchild ;//��������
		else
			i=HT[i].rchild ;//�����Һ���
		if(HT[i].lchild ==0&&HT[i].rchild ==0)//HT[i]��Ҷ���
		{
			fputc(HT[i].ch,fw);
			i=j;//�ص������
		}
		fscanf(fp,"%c",&code);//������һ���ַ�
	}
	printf("����ɹ���������decode.txt��\n");
	fclose(fp);
	fclose(fw);
}
void Compare(int n){
	FILE *fp,*fw;
	char str1[N],str2[N];
	int i=1;
	if((fp=fopen("huff1.txt","r"))==NULL)
	printf("huff1.txt�ļ���ʧ��!");
	if((fw=fopen("decode.txt","r"))==NULL)
	printf("decode.txt�ļ���ʧ��!");
    fscanf(fp,"%c",&str1);
	fscanf(fw,"%c",&str2);
	while(i<n){
		if(str1[i]==str2[i]){
			fscanf(fp,"%c",&str1);//������һ���ַ�
			fscanf(fw,"%c",&str2);//������һ���ַ�
			i++;
		}
		else
		{
			printf("huff1.txt�ļ���decode.txt�ļ���һ����ʧ��!");
			break;
		}
		if(i==n)
		{
			printf("huff1.txt�ļ���decode.txt�ļ�һ�����ɹ�!");
			break;
		}
	}
	fclose(fp);
	fclose(fw);
}
 
//ͳ���ַ������ͳ���Ƶ��
int counte(){
	int type=0;//�ַ�������
	int i=0;
	double w[]={0};
	unsigned char file[N]={0};
	int num[N]={0};
	FILE *fp;
	if((fp=fopen("huff1.txt","r"))==NULL)
	{
		printf("���ļ�ʧ��!");
	}
	while(!feof(fp))
		fread(&file[i++],sizeof(char),1,fp);
	fclose(fp);
	int n=i-1;
	for(i=1;i<N;i++){
		l[i].num=0;
		l[i].frequent=0.0;
	}
	printf("huff1.txt�ļ����ַ�һ��%d��!\n",n);
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
		printf("�ַ�%c�ĸ���Ϊ%2d,����Ƶ����%lf\n",l[i].ch,l[i].num,l[i].frequent);
	}
	printf("�����ַ����ָ�����Ƶ�ʶ���0");
	return type;
 
}
int main(){
	char choose;
	HuffmanTree HT;
	int n=counte();
	HuffmanCoding(n);
	while(1){
		printf("��ѡ��:\n");  
        printf("\t1.����\n");  
        printf("\t2.����\n");  
		printf("\t3.�ȽϽ��\n");
        printf("\t4.����\n"); 
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