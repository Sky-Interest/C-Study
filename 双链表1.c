#include<stdio.h>
typedef struct node{
int data;
struct node*next;
}Node;
Node*create()/*����������,����һ��ָ�������ͷ ���� ָ��head*/
	 {Node*head,*q,*p;/*����ָ��� ��*/ 
	 int a,n;/*�����СΪn*/ 
	 scanf("%d",&n);
	 head=(Node*)malloc(sizeof(Node));/*�����µĴ洢 �ռ�,������ͷ���*/
	 head->data=n;
	 q=head;
	 while(n>0){
	 	scanf("%d",&a);/*������Ԫ��*/
	 p=(Node*)malloc(sizeof(Node));
	 p->data=a;
	 q->next=p;
	 q=p;
	 n=n-1;
	 }
	 q->next=NULL;
	 return(head);/*���ر�ͷָ��head*/
	 };
	 
void print(Node*head)/*����������Ԫ��*/
	{Node*p;
	  p=head->next;
	 while(p!=NULL)
	 {printf("%d",p->data);
	  p=p->next;} 
	  printf("\n");
	}
	 
int Jdnz(Node*head)/*{�������Ԫ�ؾ͵���תɱ*/ 
	{
	  	Node*p,*q,*r;
		   if(((head->next)==NULL)||(((head->next)->next)==NULL))
		   return(1);
	}/*��������� Ϊ�ջ�ֻ��һ�����,�����͵���ת,����1*�� else /*�� p,q,r����ָ��߷��ʵ�������,�������ת*/
