#include<stdio.h>                                                                                  
#include<stdlib.h>  //����ͷ�ļ�  ��̬����ռ�  ��ʹ��system()���� 
#include<string.h>  //����ͷ�ļ� ʹ���ַ���strcmp()�ȽϺ��� 
#include <windows.h>   //����windows��ͷ�ļ�,ʹ��Sleep 

//Ա��ͨѶ��Ϣ�Ľṹ���Ͷ���
typedef struct {
    char num[5];       /*Ա�����*/
    char name[8];      /*Ա������*/ 
    char phone[9];     /*�칫�ҵ绰����*/
    char call[12];     /*�ֻ�����*/
}DataType;
//ͨѶ¼������Ľ������
typedef struct node
{   DataType data;   /*����������*/
    struct node *prior;   /*����ǰָ����*/
    struct node *next;   /*���ĺ�ָ����*/
}ListNode;               //,*LinkList

ListNode* head;         //����Ϊȫ�ֱ��� 

/* ��������n������˫��ѭ������*/
//һ��ָ��ͷָ�룬һ��ʼ��ָ��β����һ��ָ���½�����
ListNode*LinkList() {                  //����Ҫ�����Ľ���� 
	char u;
	char n;
	char y; 
	ListNode * s,*p;                 //sָ��β�� pָ���½������  tailΪβ��ָ�� 
	head = (ListNode *)malloc(sizeof(ListNode));  //����ͷ���
	head->next = NULL;
	s = head;
	while (1) 
	{
		p = (ListNode*)malloc(sizeof(ListNode));  //�����µĽ�� 
		printf("����Ա�����\n");
		scanf("%s", &p->data.num);
		printf("����Ա������\n");
		scanf("%s", &p->data.name);		
		printf("����Ա���칫�ҵ绰����\n");
		scanf("%s", &p->data.phone);
		printf("����Ա���绰����\n");
		scanf("%s", &p->data.call);
			
		s->next = p; //���½ڵ��������Ľ�β sָ�����һ��Ϊpָ��Ľ��
		p->prior=s;   //p��ǰָ��Ϊs��� 
		s = p; //ָ��s����  
		printf("�Ƿ����¼����һ��Ա����Ϣ ����1 ����: ����ڵ���2����\n");
        //scanf("%s",&u);
        getchar(u);
        if(u==n)
        {
            s->next = head;
            break;  //������ѭ�� 
        }
        /*if(u==y)
		        {
		            printf("�������\n");
		            system("pause");   //��ͣ������ʾ��Ϣ
		            break;
		        } 
		        */
        printf("\n");
        if(u!=n&&y)
        {
            printf("�������\n");
            system("pause");   //��ͣ������ʾ��Ϣ
            break;
        } 
	}
	s->next = head;  //ѭ������ ���һ��������һ��Ϊͷ��� 
	return head;
}

void Baocun(ListNode* head) //�������ݽ����ļ� 
{
  ListNode *p;
  p=head->next;
  
  FILE *fp;
  fp=fopen("D:\\yuangongxinxi.txt","w");
  if(fp==NULL)
  {
	printf("�ļ�����ʧ��!");
	return ;
  }
  if(p==head)
  {
  printf("����Ϊ��!"); 
  return ;
  }

  p=head->next;
  while(p!=head)  //��һ����Ϊhead 
  {
  	 //����ָ����ʽ¼������ 
     fprintf(fp,"%s %s %s %s\n",p->data.num,p->data.name,p->data.phone,p->data.call);
     p=p->next;
  }
  fclose(fp);  //�ر��ļ� 
  printf("Ա����Ϣ����ɹ�!\n");
  return ;
}

void Quanbu(ListNode *head)//���ļ� 
	{
		ListNode *p;
		p=head->next;
		char num[5];       /*Ա�����*/
	    char name[8];      /*Ա������*/ 
	    char phone[9];     /*�칫�ҵ绰����*/
	    char call[12];     /*�ֻ�����*/
		FILE *fp;
		fp=fopen("D:\\yuangongxinxi.txt","r");//���ļ� 
		if(p==head)
		{
			printf("���ļ�Ϊ�գ�");
		}
		while(fscanf(fp,"%s %s %s %s",&num,&name,&phone,&call)!=EOF)  //fscanf������ߵ���β�򷵻�EOF 
		{
			printf("��ţ�%s ������%s �칫�ҵ绰���룺%s �ֻ����룺%s\n",num,name,phone,call);
		}

	fclose(fp);  //�ر��ļ� 
	}

void Chaxun(ListNode *head)//��ѯ��Ϣ 
{
	 
    ListNode *p;
    int n,i=0;   //nΪ��ѯ��ʽ iΪ��� 
    char num1[5]; 
    char name1[8];
	system("cls");   //ִ��window���� ʵ�������Ļ���� 
    printf("\t\t ��ѡ�����Ա����Ϣ�ķ�ʽ�� \n");
    printf("\t\t 1.ͨ����Ų��� 2.ͨ����������\n"); //��ѯ��ʽ 
    p=head->next; 
    if(p==head)
    {
        printf("û��Ա����Ϣ�����ȱ���Ա����Ϣ!\n");
    }
    printf("===========================\n");
    printf("����������ѡ�� 1 �� 2 \n");
    printf("===========================\n");
    scanf("%d",&n);
    switch(n) 
    {
        case 1: 
        printf("������Ҫ���ҵ�Ա���ı��:\n");
        scanf("%s",&num1);
        while(p!=head) 
        {
            if(strcmp(p->data.num,num1)==0)   //strcmp(�ַ���1,�ַ���2); �ַ����Ƚ� ����򷵻�0 
            {
            	printf("�ɹ��ҵ���Ա����Ϣ!\n");
                printf("Ա���ı�š��������칫�Һ��롢�绰��\n");
                printf("���:%s\n",p->data.num);
                printf("����:%s\n",p->data.name);
                printf("�칫�Һ���:%s\n",p->data.phone);
                printf("�绰:%s\n",p->data.call);
                i=1;  //���� ������ҳɹ� 
                break;  //���Ψһ
            }  
			                                                                    
            p=p->next; 
			
        }
        if(i==0)
        {
        	printf("δ���ҵ���Ա����Ϣ!\n");
            break;
		}
        case 2: 
        printf("������Ҫ���ҵ�Ա��������:\n");
        scanf("%s",&name1);
        while(p!=head) 
        {
            if(strcmp(p->data.name,name1)==0)   //���ֿ��ܴ���ͬ�� 
            {
            	printf("�ɹ��ҵ���Ա����Ϣ!\n");
                printf("Ա���ı�š��������칫�Һ��롢�绰��\n");
                printf("���:%s\n",p->data.num);
                printf("����:%s\n",p->data.name);
                printf("�칫�Һ���:%s\n",p->data.phone);
                printf("�绰:%s\n",p->data.call);
                i=1;
            }
           

            p=p->next;
            
        }
        if(i==0)
        printf("δ���ҵ���Ա����Ϣ!\n");
        break; 
        default:printf("�����д���!\n");
    }
}

void Charu(ListNode *head) //�����Ϣ 
{
	int n;
	FILE *fp;
	fp=fopen("D:\\yuangongxinxi.txt","a");  //���ļ� 
    ListNode *s,*p;  //pΪ�½���� 
    s=head->next;
    while(s->next!=head)  //�������� 
    {
        s=s->next; 
    }
     while(1)
    {
    p=(ListNode*)malloc(sizeof(ListNode));
    printf("����Ա�����\n");
		scanf("%s", &p->data.num);
		printf("����Ա������\n");
		scanf("%s", &p->data.name);
		printf("����Ա���칫�ҵ绰����\n");
				scanf("%s", &p->data.phone);
			
				printf("����Ա���绰����\n");
				scanf("%s", &p->data.call);
				
	    s->next = p; //���½ڵ��������Ľ�β sָ�����һ��Ϊpָ��Ľ��
		p->prior=s;   //p��ǰָ��Ϊs��� 
		s = p; //ָ��s���� 
        s->next=head; //����ѭ�� 
        printf("����ɹ�\n"); 
	  
       break; 
   }  
}

void Shanchu(ListNode *head) //ɾ����Ϣ 
{
    int k,i=0;    //���û���ж��Ƿ��д��� 
    ListNode *q,*p;
    char num2[5];
    char name2[8];
    q=head;
	p=head->next; 
    system("cls"); 
    printf("\t\t 1.�����ɾ�� 2.������ɾ��\n");
    printf("��ѡ�� :\n");
    scanf("%d",&k);
    if(p==head)
    {
    	printf("û��Ա����Ϣ����\n");
	}
    switch(k)
    {
        case 1:
        {
            printf("������Ҫɾ����Ա���ı��:\n");
            scanf("%s",&num2);
            break; 
        }
        case 2:
        {
            printf("������Ҫɾ����Ա��������:\n");
            scanf("%s",&name2);
            break;
        }
    }
    while(p!=head) 
    { 
        if(strcmp(p->data.num,num2)==0)
        {
            q->next=p->next;
            p->next->prior=q;
            free(p);//�ͷŽڵ� 
            printf("�ѽ���Ա����Ϣɾ����\n");
            i=1;
            break;
        }
        if(strcmp(p->data.name,name2)==0)//�Ƚ� 
        {
            q->next=p->next;
            p->next->prior=q;
            free(p);
			printf("�ѽ���Ա����Ϣɾ����\n");
			i=1;
            //break;
        }
        q=p;
        p=p->next;
		
    }
    if(i==0)
    printf("δ�ҵ���Ҫɾ����Ա����Ϣ��\n");
 
}

void Xiugai(ListNode *head)
{
	ListNode *p;
	int n,i=0;
	char num3[5];
    char name3[8];
	p=head->next;
	if(p==head)
    {
        printf("û��Ա����Ϣ������¼��Ա����Ϣ!\n");
    }
    system("cls"); 
    printf("\t\t ��ѡ�������Ҫ�޸�Ŀ��Ա���ķ�ʽ�� \n");
    printf("\t\t 1.ͨ������޸� 2.ͨ�������޸�\n");
    printf("===========================\n");
    printf("����������ѡ�� 1 �� 2 \n");
    scanf("%d",&n);
	switch(n) 
	{
		case 1:
		{
			printf("�����뱻�޸ĵ�Ա�����:\n");
        	scanf("%s",&num3);
	        while(p!=head) 
	        {
	        	if(strcmp(p->data.num,num3)==0)
	        	{
	        		printf("����Ա�����\n");
					scanf("%s", &p->data.num);
					printf("����Ա������\n");
					scanf("%s", &p->data.name);
					printf("����Ա���칫�ҵ绰����\n");
							scanf("%s", &p->data.phone);
							
							printf("����Ա���绰����\n");
							scanf("%s", &p->data.call);
								
					printf("�Ա�ŵ��޸ĳɹ���\n");
					i=1;
					break;
							
				}
					p=p->next;
			}
			break;
		}
		
        case 2:
        {
		    printf("�����뱻�޸ĵ�����:\n");
       		scanf("%s",&name3);
       	    while(p!=head) 
       		{
       		 	if(strcmp(p->data.name,name3)==0)
       		 	{
       		 		printf("����Ա�����\n");
					scanf("%s", &p->data.num);
					printf("����Ա������\n");
					scanf("%s", &p->data.name);
				    printf("����Ա���칫�ҵ绰����\n");
						scanf("%s", &p->data.phone);
					
						printf("����Ա���绰����\n");
						scanf("%s", &p->data.call); 
					printf("�Ա�ŵ��޸ĳɹ���\n");
					i=1;
					break;
				}
					
					p=p->next;									         		 	     		 	
			}		
		}
		if(i==0){
			printf("δ�ҵ�Ŀ��Ա����\n");
	        break;
		}
        
        default:printf("����������д���!\n");
	}
}

void Mulu()//Ŀ¼ 
{ 
            printf("\n0.��ӭʹ�ñ�����\n");
            Sleep(500);
			printf("\n1.���ν���ϵͳ����¼��Ա����Ϣ;\n");
			Sleep(500);
			printf("\n2.���ղ˵���ʾ�������ִ���;\n");
			Sleep(500);
			printf("\n3.���벻��ص����ݿ��ܻᵼ��ϵͳ����������\n");
			Sleep(500);
			printf("\n4.����л��ʹ�ô˳���\n");
			//printf("\n�밴�س����뱾����\n");
			//getchar();
}
void Mulua()
{
	            printf("\n\t\t\t\t+++++++++++++++++++++++++++++++++\n");
				printf("\t\t\t\t+\t1.¼��Ա����Ϣ\t\t+\n\t\n");
			    printf("\t\t\t\t+\t2.����Ա����Ϣ\t\t+\n\t\t\n"); 
				printf("\t\t\t\t+\t3.��ѯԱ����Ϣ\t\t+\n\t\t\n");
				printf("\t\t\t\t+\t4.�޸�Ա����Ϣ\t\t+\n\t\t\n");
				printf("\t\t\t\t+\t5.ɾ��Ա����Ϣ\t\t+\n\t\t\n");
				printf("\t\t\t\t+\t6.����Ա����Ϣ\t\t+\n\t\t\n");
				printf("\t\t\t\t+\t7.��ѯȫ����¼\t\t+\n\t\t\n");
				printf("\t\t\t\t+++++++++++++++++++++++++++++++++\n");
				printf("\n    ���������ѡ��Ĵ��� :\t              "); 
				printf("\n");
}


int main()
{  
	int m;
	FILE *fp; //C���Կα�P396��ϸ˵������Ϊ�ļ����� 
	printf("��ӭ����Ա������ϵͳ\n");
	printf("�����뱾ϵͳ������!\n");
    char s[30];
    char c[30]={"6666"};//�˴���������Ϊ���� 
    printf("��ֻ��һ�λ���!�������Զ��˳�ϵͳ\n");
    printf("���룺"); 
    
    int a=1;
    while((a--)>0)
    {
	    scanf("%s",s);  //�������� 
	    getchar(); //��ȡ�������Ļس��� 
    	if(strcmp(s,c)==0)  //�ж�������ȷ 
    	{
		  system("color 3");  //���������ɫΪ3 
		  printf("����������ȷ!\n"); 
		  printf("���ڼ���ϵͳ......\n");
		  Sleep(1000);
		  printf("�����ĵȴ�......\n");
		  Sleep(1000);
		  printf("�����ĵȴ�......\n");
		  Sleep(500);
		  printf("ϵͳ���سɹ�,������س�������ϵͳ��\n");
		  getchar();
		  
		  system("cls"); //���� 
		  Mulu();//һ��Ŀ¼ 
		        while(1)
		        {
		            //system("cls"); 
		            //Mulu();
		            system("cls"); 
		            Mulua();//ѭ��Ŀ¼
		            char ch=getchar();
		            switch(ch)     //���ж�Ӧ�ַ���ƥ�� 
		            {   
		                case '1':head=LinkList();Baocun(head);break;   //¼�����ֱ�ӱ��� 
		                case '2':Charu(head);Baocun(head);break; //���� 
		                case '3':Chaxun(head);break;//��ѯ 
		                case '4':Xiugai(head);Baocun(head);break;//�޸� 
		                case '5':Shanchu(head);Baocun(head);break;//ɾ�� 
		                case '6':Baocun(head);break;//���� 
		                case '7':Quanbu(head);break;//ȫ����� 
		                default:
		                printf("ѡ���ܴ���!\n");
		            }
		            printf("\n");
		            printf("------------------------------------------------------------\n");
		            printf("�Ƿ��˳�ϵͳ ���䣺1 ���䣺 2 \n");
		            printf("------------------------------------------------------------\n");
		            scanf("%d",&m);
		            getchar();
		            if(m==2)
		            {
		               printf("��л��ʹ�ñ�ϵͳ����ӭ�ٴ�ʹ�ã�\n"); break;  //ֱ���˳�while��ѭ�� 
		            }
		        }
		   }
			else
				printf("�������!�����˳�ϵͳ\n");
				Sleep(1000);
			} 
			return 0; 
}
