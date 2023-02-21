#include<stdio.h>
#include<malloc.h>
#define maxval 10000.0//˫���㣨float�����͵����ֵ
#define maxsize 100   //��������������λ��
typedef struct
{
	char ch;//ֵ 
	float weight;//Ȩ�� 
	int lchild;//�� 
	int rchild;//�Һ� 
	int parent;//˫�� 
}HFMTree;
typedef struct
{
	char bits[10];   //λ��
	int start;      //������λ���е���ʼλ��
	char ch;        //�ַ�
}CodeType;
 
void JianLiHFMTree(HFMTree tree[],int n,int m);//������������
void QiuHFMBianMa(CodeType code[],HFMTree tree[],int n);//���ݹ��������������������
void QiuHFMYiMa(HFMTree tree[],int m);//���ζ�����ģ����ݹ�����������
 
int main()
{
	int choice=0;
	int n,m;//nΪ�ڵ��ȡ��ַ��mΪ�ڵ㻻�����������34�� 
	int i,j;//ѭ������
	HFMTree *tree;//�������� 
	CodeType *code;//�������� 
	
	printf("������Ԫ�ظ�����");
	scanf("%d",&n);
	m=2*n-1;
	tree=(HFMTree *)malloc(sizeof(HFMTree)*m);//���ٴ�Ź��������ռ�
	code=(CodeType *)malloc(sizeof(CodeType)*n);//���ٴ�Ź���������ռ�
	JianLiHFMTree(tree,n,m);//������������
	printf("���������ѳɹ�������\n");
	
	QiuHFMBianMa(code,tree,n);//���ݹ��������������������
	printf("�������������\n");
	for(i = 0;i<n;i++)
	{
		printf("%c: ",code[i].ch);
		for(j = code[i].start;j < n;j++)
		printf("%c ",code[i].bits[j]);
		printf("\n");
	}
	
	QiuHFMYiMa(tree,m);//���ζ�����ģ����ݹ�����������
	
	return 0;
}
 
void JianLiHFMTree(HFMTree tree[],int n,int m)//������������  a5b1c9d2e7
{
	int i,j,p1,p2;//p1,p2�ֱ��סÿ�κϲ�ʱȨֵ��С�ʹ�С�������������±�
	float small1,small2,f;
	char c;
	for(i=0;i<m;i++)    //��ʼ��
	{
		tree[i].parent=0;
		tree[i].lchild=-1;
		tree[i].rchild=-1;
		tree[i].weight=0.0;
	}
	for(i=0;i<n;i++)  //����ǰn�������ַ���Ȩֵ
	{
		printf("�����%d��Ԫ�ص�=>\n",i+1);
		printf("\t���ֵ��");
		scanf("%c",&c);
		tree[i].ch=getchar();
		printf("\tȨֵ��");
		scanf("%f",&f);
		tree[i].weight=f;
	}
	for(i=n;i<m;i++)      //����n-1�κϲ�������n-1���½��
	{
		p1=0;p2=0;
		small1=maxval;small2=maxval;   //maxval��float���͵����ֵ
		for(j=0;j<i;j++)    //ѡ������Ȩֵ��С�ĸ����
		if(tree[j].parent==0)
		if(tree[j].weight<small1)
	{
		small2=small1;  //�ı���СȨ����СȨ����Ӧ��λ��
		small1=tree[j].weight;
		p2=p1;
		p1=j;
	}
	else
	if(tree[j].weight<small2)
	{
		small2=tree[j].weight;  //�ı��СȨ��λ��
		p2=j;
	}
		tree[p1].parent=i;
		tree[p2].parent=i;
		tree[i].lchild=p1;  //��СȨ��������½�������
		tree[i].rchild=p2;  //��СȨ��������½����Һ���
		tree[i].weight=tree[p1].weight+tree[p2].weight;
	}
}//huffman
 
void QiuHFMBianMa(CodeType code[],HFMTree tree[],int n)//���ݹ��������������������
//codetype code[]Ϊ����Ĺ���������
//hufmtree tree[]Ϊ��֪�Ĺ�������
{
	int i,c,p;
	CodeType cd;   //�������
	for(i=0;i<n;i++)
	{
		cd.start=n;
		cd.ch=tree[i].ch;
		c=i;       //��Ҷ���������ϻ���
		p=tree[i].parent;   //tree[p]��tree[i]��˫��
		while(p!=0)
		{
			cd.start--;
			if(tree[p].lchild == c)
				cd.bits[cd.start] = '0';   
			else
				cd.bits[cd.start] = '1';   
			c = p;
			p = tree[p].parent;
		}
		code[i]=cd;    //��i+1���ַ��ı������code[i]
	}
}//huffmancode
 
void QiuHFMYiMa(HFMTree tree[],int m)//���ζ�����ģ����ݹ����������� 11111000110110# 
{
	int i,j=0;
	char b[maxsize];
	char endflag='#';    //���Ľ�����־ȡ#
	i=m-1;             //�Ӹ���㿪ʼ��������
	printf("��������ģ�0 or 1��,��'#'Ϊ������־��\n");
	scanf("%s",b);
	printf("������������룺\n");
	while(b[j]!='#')
	{
		if(b[j]=='0')
			i=tree[i].lchild;   //��������
		else
			i=tree[i].rchild;   //�����Һ���
		if(tree[i].lchild == -1)     //tree[i]��Ҷ���
		{
			printf("%c",tree[i].ch);
			i=m-1;      //�ص������
		}
		j++;
	}
	printf("\n");
	if(tree[i].lchild!=-1 && b[j]!='#')   //���Ķ��꣬����δ��Ҷ�ӽ��
		printf("\nERROR\n");  //��������д�
}//decode
