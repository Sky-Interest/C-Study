#include<stdio.h>                                                                                  
#include<stdlib.h>  //引入头文件  动态分配空间  和使用system()函数 
#include<string.h>  //引入头文件 使用字符串strcmp()比较函数 
#include <windows.h>   //引入windows的头文件,使用Sleep 

//员工通讯信息的结构类型定义
typedef struct {
    char num[5];       /*员工编号*/
    char name[8];      /*员工姓名*/ 
    char phone[9];     /*办公室电话号码*/
    char call[12];     /*手机号码*/
}DataType;
//通讯录单链表的结点类型
typedef struct node
{   DataType data;   /*结点的数据域*/
    struct node *prior;   /*结点的前指针域*/
    struct node *next;   /*结点的后指针域*/
}ListNode;               //,*LinkList

ListNode* head;         //定义为全局变量 

/* 建立含有n个结点的双向循环链表*/
//一个指向头指针，一个始终指向尾部，一个指向新建立的
ListNode*LinkList() {                  //传入要创建的结点数 
	char u;
	char n;
	char y; 
	ListNode * s,*p;                 //s指向尾部 p指向新建立结点  tail为尾部指针 
	head = (ListNode *)malloc(sizeof(ListNode));  //创建头结点
	head->next = NULL;
	s = head;
	while (1) 
	{
		p = (ListNode*)malloc(sizeof(ListNode));  //创建新的结点 
		printf("输入员工编号\n");
		scanf("%s", &p->data.num);
		printf("输入员工姓名\n");
		scanf("%s", &p->data.name);		
		printf("输入员工办公室电话号码\n");
		scanf("%s", &p->data.phone);
		printf("输入员工电话号码\n");
		scanf("%s", &p->data.call);
			
		s->next = p; //把新节点插入链表的结尾 s指针的下一个为p指针的结点
		p->prior=s;   //p的前指针为s结点 
		s = p; //指针s后移  
		printf("是否继续录入下一个员工信息 否：输1 继续: 输大于等于2的数\n");
        //scanf("%s",&u);
        getchar(u);
        if(u==n)
        {
            s->next = head;
            break;  //跳出死循环 
        }
        /*if(u==y)
		        {
		            printf("输入错误！\n");
		            system("pause");   //暂停处理并显示消息
		            break;
		        } 
		        */
        printf("\n");
        if(u!=n&&y)
        {
            printf("输入错误！\n");
            system("pause");   //暂停处理并显示消息
            break;
        } 
	}
	s->next = head;  //循环建立 最后一个结点的下一个为头结点 
	return head;
}

void Baocun(ListNode* head) //保存数据进入文件 
{
  ListNode *p;
  p=head->next;
  
  FILE *fp;
  fp=fopen("D:\\yuangongxinxi.txt","w");
  if(fp==NULL)
  {
	printf("文件保存失败!");
	return ;
  }
  if(p==head)
  {
  printf("链表为空!"); 
  return ;
  }

  p=head->next;
  while(p!=head)  //下一个不为head 
  {
  	 //按照指定格式录入数据 
     fprintf(fp,"%s %s %s %s\n",p->data.num,p->data.name,p->data.phone,p->data.call);
     p=p->next;
  }
  fclose(fp);  //关闭文件 
  printf("员工信息保存成功!\n");
  return ;
}

void Quanbu(ListNode *head)//打开文件 
	{
		ListNode *p;
		p=head->next;
		char num[5];       /*员工编号*/
	    char name[8];      /*员工姓名*/ 
	    char phone[9];     /*办公室电话号码*/
	    char call[12];     /*手机号码*/
		FILE *fp;
		fp=fopen("D:\\yuangongxinxi.txt","r");//读文件 
		if(p==head)
		{
			printf("此文件为空！");
		}
		while(fscanf(fp,"%s %s %s %s",&num,&name,&phone,&call)!=EOF)  //fscanf出错或者到结尾则返回EOF 
		{
			printf("编号：%s 姓名：%s 办公室电话号码：%s 手机号码：%s\n",num,name,phone,call);
		}

	fclose(fp);  //关闭文件 
	}

void Chaxun(ListNode *head)//查询信息 
{
	 
    ListNode *p;
    int n,i=0;   //n为查询方式 i为活动锁 
    char num1[5]; 
    char name1[8];
	system("cls");   //执行window命令 实现清除屏幕功能 
    printf("\t\t 请选择查找员工信息的方式： \n");
    printf("\t\t 1.通过编号查找 2.通过姓名查找\n"); //查询方式 
    p=head->next; 
    if(p==head)
    {
        printf("没有员工信息，请先保存员工信息!\n");
    }
    printf("===========================\n");
    printf("请输入您的选择： 1 或 2 \n");
    printf("===========================\n");
    scanf("%d",&n);
    switch(n) 
    {
        case 1: 
        printf("请输入要查找的员工的编号:\n");
        scanf("%s",&num1);
        while(p!=head) 
        {
            if(strcmp(p->data.num,num1)==0)   //strcmp(字符串1,字符串2); 字符串比较 相等则返回0 
            {
            	printf("成功找到此员工信息!\n");
                printf("员工的编号、姓名、办公室号码、电话：\n");
                printf("编号:%s\n",p->data.num);
                printf("姓名:%s\n",p->data.name);
                printf("办公室号码:%s\n",p->data.phone);
                printf("电话:%s\n",p->data.call);
                i=1;  //开锁 代表查找成功 
                break;  //编号唯一
            }  
			                                                                    
            p=p->next; 
			
        }
        if(i==0)
        {
        	printf("未查找到此员工信息!\n");
            break;
		}
        case 2: 
        printf("请输入要查找的员工的姓名:\n");
        scanf("%s",&name1);
        while(p!=head) 
        {
            if(strcmp(p->data.name,name1)==0)   //名字可能存在同名 
            {
            	printf("成功找到此员工信息!\n");
                printf("员工的编号、姓名、办公室号码、电话：\n");
                printf("编号:%s\n",p->data.num);
                printf("姓名:%s\n",p->data.name);
                printf("办公室号码:%s\n",p->data.phone);
                printf("电话:%s\n",p->data.call);
                i=1;
            }
           

            p=p->next;
            
        }
        if(i==0)
        printf("未查找到此员工信息!\n");
        break; 
        default:printf("查找有错误!\n");
    }
}

void Charu(ListNode *head) //添加信息 
{
	int n;
	FILE *fp;
	fp=fopen("D:\\yuangongxinxi.txt","a");  //打开文件 
    ListNode *s,*p;  //p为新建结点 
    s=head->next;
    while(s->next!=head)  //在最后插入 
    {
        s=s->next; 
    }
     while(1)
    {
    p=(ListNode*)malloc(sizeof(ListNode));
    printf("输入员工编号\n");
		scanf("%s", &p->data.num);
		printf("输入员工姓名\n");
		scanf("%s", &p->data.name);
		printf("输入员工办公室电话号码\n");
				scanf("%s", &p->data.phone);
			
				printf("输入员工电话号码\n");
				scanf("%s", &p->data.call);
				
	    s->next = p; //把新节点插入链表的结尾 s指针的下一个为p指针的结点
		p->prior=s;   //p的前指针为s结点 
		s = p; //指针s后移 
        s->next=head; //建立循环 
        printf("插入成功\n"); 
	  
       break; 
   }  
}

void Shanchu(ListNode *head) //删除信息 
{
    int k,i=0;    //利用活动锁判断是否有此人 
    ListNode *q,*p;
    char num2[5];
    char name2[8];
    q=head;
	p=head->next; 
    system("cls"); 
    printf("\t\t 1.按编号删除 2.按姓名删除\n");
    printf("请选择 :\n");
    scanf("%d",&k);
    if(p==head)
    {
    	printf("没有员工信息！！\n");
	}
    switch(k)
    {
        case 1:
        {
            printf("请输入要删除的员工的编号:\n");
            scanf("%s",&num2);
            break; 
        }
        case 2:
        {
            printf("请输入要删除的员工的姓名:\n");
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
            free(p);//释放节点 
            printf("已将该员工信息删除！\n");
            i=1;
            break;
        }
        if(strcmp(p->data.name,name2)==0)//比较 
        {
            q->next=p->next;
            p->next->prior=q;
            free(p);
			printf("已将该员工信息删除！\n");
			i=1;
            //break;
        }
        q=p;
        p=p->next;
		
    }
    if(i==0)
    printf("未找到需要删除的员工信息！\n");
 
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
        printf("没有员工信息，请先录入员工信息!\n");
    }
    system("cls"); 
    printf("\t\t 请选择查找需要修改目标员工的方式： \n");
    printf("\t\t 1.通过编号修改 2.通过姓名修改\n");
    printf("===========================\n");
    printf("请输入您的选择： 1 或 2 \n");
    scanf("%d",&n);
	switch(n) 
	{
		case 1:
		{
			printf("请输入被修改的员工编号:\n");
        	scanf("%s",&num3);
	        while(p!=head) 
	        {
	        	if(strcmp(p->data.num,num3)==0)
	        	{
	        		printf("输入员工编号\n");
					scanf("%s", &p->data.num);
					printf("输入员工姓名\n");
					scanf("%s", &p->data.name);
					printf("输入员工办公室电话号码\n");
							scanf("%s", &p->data.phone);
							
							printf("输入员工电话号码\n");
							scanf("%s", &p->data.call);
								
					printf("对编号的修改成功！\n");
					i=1;
					break;
							
				}
					p=p->next;
			}
			break;
		}
		
        case 2:
        {
		    printf("请输入被修改的姓名:\n");
       		scanf("%s",&name3);
       	    while(p!=head) 
       		{
       		 	if(strcmp(p->data.name,name3)==0)
       		 	{
       		 		printf("输入员工编号\n");
					scanf("%s", &p->data.num);
					printf("输入员工姓名\n");
					scanf("%s", &p->data.name);
				    printf("输入员工办公室电话号码\n");
						scanf("%s", &p->data.phone);
					
						printf("输入员工电话号码\n");
						scanf("%s", &p->data.call); 
					printf("对编号的修改成功！\n");
					i=1;
					break;
				}
					
					p=p->next;									         		 	     		 	
			}		
		}
		if(i==0){
			printf("未找到目标员工！\n");
	        break;
		}
        
        default:printf("输入的内容有错误!\n");
	}
}

void Mulu()//目录 
{ 
            printf("\n0.欢迎使用本程序\n");
            Sleep(500);
			printf("\n1.初次进入系统请先录入员工信息;\n");
			Sleep(500);
			printf("\n2.按照菜单提示输入数字代号;\n");
			Sleep(500);
			printf("\n3.输入不相关的数据可能会导致系统崩溃！！！\n");
			Sleep(500);
			printf("\n4.最后感谢您使用此程序！\n");
			//printf("\n请按回车进入本程序\n");
			//getchar();
}
void Mulua()
{
	            printf("\n\t\t\t\t+++++++++++++++++++++++++++++++++\n");
				printf("\t\t\t\t+\t1.录入员工信息\t\t+\n\t\n");
			    printf("\t\t\t\t+\t2.插入员工信息\t\t+\n\t\t\n"); 
				printf("\t\t\t\t+\t3.查询员工信息\t\t+\n\t\t\n");
				printf("\t\t\t\t+\t4.修改员工信息\t\t+\n\t\t\n");
				printf("\t\t\t\t+\t5.删除员工信息\t\t+\n\t\t\n");
				printf("\t\t\t\t+\t6.保存员工信息\t\t+\n\t\t\n");
				printf("\t\t\t\t+\t7.查询全部记录\t\t+\n\t\t\n");
				printf("\t\t\t\t+++++++++++++++++++++++++++++++++\n");
				printf("\n    请输入相关选项的代号 :\t              "); 
				printf("\n");
}


int main()
{  
	int m;
	FILE *fp; //C语言课本P396详细说明，此为文件操作 
	printf("欢迎进入员工管理系统\n");
	printf("请输入本系统的密码!\n");
    char s[30];
    char c[30]={"6666"};//此处大括号内为密码 
    printf("你只有一次机会!错误则自动退出系统\n");
    printf("密码："); 
    
    int a=1;
    while((a--)>0)
    {
	    scanf("%s",s);  //输入密码 
	    getchar(); //获取缓存区的回车符 
    	if(strcmp(s,c)==0)  //判断密码正确 
    	{
		  system("color 3");  //最后设置颜色为3 
		  printf("密码输入正确!\n"); 
		  printf("正在加载系统......\n");
		  Sleep(1000);
		  printf("请耐心等待......\n");
		  Sleep(1000);
		  printf("请耐心等待......\n");
		  Sleep(500);
		  printf("系统加载成功,请输入回车键进入系统。\n");
		  getchar();
		  
		  system("cls"); //清屏 
		  Mulu();//一级目录 
		        while(1)
		        {
		            //system("cls"); 
		            //Mulu();
		            system("cls"); 
		            Mulua();//循环目录
		            char ch=getchar();
		            switch(ch)     //进行对应字符的匹配 
		            {   
		                case '1':head=LinkList();Baocun(head);break;   //录入完毕直接保存 
		                case '2':Charu(head);Baocun(head);break; //插入 
		                case '3':Chaxun(head);break;//查询 
		                case '4':Xiugai(head);Baocun(head);break;//修改 
		                case '5':Shanchu(head);Baocun(head);break;//删除 
		                case '6':Baocun(head);break;//保存 
		                case '7':Quanbu(head);break;//全部输出 
		                default:
		                printf("选择功能错误!\n");
		            }
		            printf("\n");
		            printf("------------------------------------------------------------\n");
		            printf("是否退出系统 否输：1 是输： 2 \n");
		            printf("------------------------------------------------------------\n");
		            scanf("%d",&m);
		            getchar();
		            if(m==2)
		            {
		               printf("感谢您使用本系统，欢迎再次使用！\n"); break;  //直接退出while死循环 
		            }
		        }
		   }
			else
				printf("输入错误!即将退出系统\n");
				Sleep(1000);
			} 
			return 0; 
}
