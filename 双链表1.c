#include<stdio.h>
typedef struct node{
int data;
struct node*next;
}Node;
Node*create()/*创建单链表,返回一个指向链表表头 结点的 指针head*/
	 {Node*head,*q,*p;/*定义指针变 量*/ 
	 int a,n;/*链表大小为n*/ 
	 scanf("%d",&n);
	 head=(Node*)malloc(sizeof(Node));/*申请新的存储 空间,建立表头结点*/
	 head->data=n;
	 q=head;
	 while(n>0){
	 	scanf("%d",&a);/*输入新元素*/
	 p=(Node*)malloc(sizeof(Node));
	 p->data=a;
	 q->next=p;
	 q=p;
	 n=n-1;
	 }
	 q->next=NULL;
	 return(head);/*返回表头指针head*/
	 };
	 
void print(Node*head)/*输出单链表各元素*/
	{Node*p;
	  p=head->next;
	 while(p!=NULL)
	 {printf("%d",p->data);
	  p=p->next;} 
	  printf("\n");
	}
	 
int Jdnz(Node*head)/*{单链表各元素就地逆转杀*/ 
	{
	  	Node*p,*q,*r;
		   if(((head->next)==NULL)||(((head->next)->next)==NULL))
		   return(1);
	}/*如果单链表 为空或只有一个结点,不做就地逆转,返回1*／ else /*由 p,q,r三个指针边访问单链表结点,边完成逆转*/
