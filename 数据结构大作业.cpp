
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 100
#define X 10

/*学生信息结构体，包括学号，姓名，各学科分数，总分，均分*/
typedef struct student
{
  long number;
  char name[M];
  int score[X];
  int psscore [X];
  int stutotal;
  float stuaverage;
}STUDENT;/*对学生信息结构体取别名“STUDENT”*/

//函数展示
void Swap(STUDENT *a,STUDENT *b);
void Input(STUDENT stu[],int n,int x);
void SubCalculate(STUDENT stu[],int subtotal[],float subaverage[],int n,int x);
void StuCalculate(STUDENT stu[],int n,int x);
void SortStuScoreUpdown(STUDENT stu[],int n);
void SortEnglishScoreUpdown(STUDENT stu[],int n);
void SortPEScoreUpdown(STUDENT stu[],int n);
void SortStuScoreDownup(STUDENT stu[],int n);
void SortNumberDownup(STUDENT stu[],int n);
void SortName(STUDENT stu[],int n);
void SearchNumber(STUDENT stu[],int n,int x);
void SearchName(STUDENT stu[],int n,int x);
void List(STUDENT stu[],int subtotal[],float subaverage[],int n,int x);
void Print1(STUDENT stu[],int n,int x);
void Print2(int subtotal[],float subaverage[],int x);
void WritetoFile(STUDENT stu[],int subtotal[],float subaverage[],int n,int x);
void ReadfromFile(STUDENT stu[],int subtotal[],float subaverage[],int *n,int *x);
void Mulua();
//函数展示 


/*实现两个结构体的交换*/
void Swap(STUDENT *a,STUDENT *b)
{
  STUDENT temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

/*键盘依次输入学生信息*/
void Input(STUDENT stu[],int n,int x)
{
	printf("\n\n");
	int i,j;
	printf("+++++++++++++++++++++++++++++++++\n");
	for(i=0;i<n;i++)
	{
		printf("学号:\t");
		scanf("%ld",&stu[i].number);
		getchar();/*清除缓冲区中的回车字符，防止被读入学生姓名*/
		printf("姓名:\t");
		gets(stu[i].name);
		for(j=0;j<x;j++)
		{
			printf("++++++++++++++++++++++++++++\n");
			printf("学科分类\n");
			printf("1.高数 2.英语 3.体育\n");
			do{
			    printf("学科%d分数:",j+1);
			    scanf("%d",&stu[i].score[j]);//录入各科分数 
			    printf("学科%d平时分数:",j+1);
			    scanf("%d",&stu[i].psscore [j]);//录入各科平时分数 
			}while(stu[i].score[j]<0||stu[i].score[j]>100||stu[i].psscore[j]<0||stu[i].psscore[j]>100);/*防止录入异常成绩*/
			printf("\n++++++++++++++++++++++++++++\n");
			
		}
	}
}

/*计算学科的总分和均分*/
void SubCalculate(STUDENT stu[],int subtotal[],float subaverage[],int n,int x)
{
	int i,j;
	printf("+++++++++++++++++++++++++++++++++\n");
	for(j=0;j<x;j++)
	{
		subtotal[j]=0;/*学科总成绩初始化为0*/
		for(i=0;i<n;i++)
		{
			//三课总分所在位置 
			subtotal[j]=subtotal[j]+stu[i].score[j];
		}
		// 三科平均分所在位置
		subaverage[j]=(float)subtotal[j]/n;/*浮点数运算，确保数据准确性*/
		printf("学科%d总分:%d    平均分:%6.2f\n",j+1,subtotal[j],subaverage[j]);
	}
	printf("\n+++++++++++++++++++++++++++++++++\n");
 }

/*计算每个学生的总分和加权平均分*/
void StuCalculate(STUDENT stu[],int n,int x)
{
	int i,j;
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	for(i=0;i<n;i++)
	{
		stu[i].stutotal=0;/*学生总成绩初始化为0*/
		for(j=0;j<x;j++)
		{
			/*学生总分所在位置*/ 
			stu[i].stutotal=stu[i].stutotal+stu[i].score[j];
		}
		/*学生总加权平均分所在位置*/
		stu[i].stuaverage=(float)(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])*0.7+(stu[i].psscore[0]+stu[i].psscore[1]+stu[i].psscore[2])*0.3;/*浮点数运算，确保数据准确性*/
		printf("(学生 %d  %s)总分:%d    加权平均分:%6.2f\n",i+1,stu[i].name,stu[i].stutotal,stu[i].stuaverage);
	}
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

/*将学生成绩按从高到低的顺序排列*/
void SortStuScoreUpdown(STUDENT stu[],int n)
{
	for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (stu[i].stutotal < stu[j].stutotal) Swap(&stu[i], &stu[j]);
			/*如果前面的学生的总成绩小于后面的学生的总成绩，则交换两个学生信息结构体位置*/
        }
	  }
}
/*将学生高数成绩按从高到低的顺序排列*/
void SortMathScoreUpdown(STUDENT stu[],int n)
{
	for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (stu[i].score[0] < stu[j].score[0]) Swap(&stu[i], &stu[j]);
			/*如果前面的学生的高数成绩小于后面的学生的高数成绩，则交换两个学生信息结构体位置*/
        }
	  }
}
/*将学生英语成绩按从高到低的顺序排列*/
void SortEnglishScoreUpdown(STUDENT stu[],int n)
{
	for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (stu[i].score[1] < stu[j].score[1]) Swap(&stu[i], &stu[j]);
			/*如果前面的学生的英语成绩小于后面的学生的英语成绩，则交换两个学生信息结构体位置*/
        }
	  }
}
/*将学生体育成绩按从高到低的顺序排列*/
void SortPEScoreUpdown(STUDENT stu[],int n)
{
	for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (stu[i].score[2] < stu[j].score[2]) Swap(&stu[i], &stu[j]);
			/*如果前面的学生的体育成绩小于后面的学生的体育成绩，则交换两个学生信息结构体位置*/
        }
	  }
}

/*将学生成绩按从低到高的顺序排列*/
void SortStuScoreDownup(STUDENT stu[],int n)
{
		for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (stu[i].stutotal > stu[j].stutotal) Swap(&stu[i], &stu[j]);
			/*如果前面的学生的总成绩大于后面的学生的总成绩，则交换两个学生信息结构体位置*/
        }
	  }
}

/*将学生学号按从小到大排列*/
void SortNumberDownup(STUDENT stu[],int n)
{
		for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (stu[i].number > stu[j].number) Swap(&stu[i], &stu[j]);
			/*如果前面的学生的学号大于后面的学生的学号，则交换两个学生信息结构体位置*/
        }
	  }
}

/*将学生姓名按字典顺序排列*/
void SortName(STUDENT stu[],int n)
{
	for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (strcmp(stu[i].name,stu[j].name)>0) Swap(&stu[i], &stu[j]);
			/*如果前面的学生的字母序位大于后面的学生的字母序位，则交换两个学生信息结构体位置*/
        }
	  }
}

/*按学号查找学生并输出学生信息*/
void SearchNumber(STUDENT stu[],int n,int x)
{
	int i,j,flag=0;/*未找到学生时flag初始化为0*/
	long temp;
	printf("输入学号:\t");
	scanf("%ld",&temp);
	getchar();
	SortStuScoreUpdown(stu,n);/*将学生按照成绩从高到低排序以获得学生的排名情况*/
	for(i=0;i<n;i++)/*将录入的学生学号与待查学号进行比对*/
	{
		if(stu[i].number==temp)/*找到待查学号*/
		{
			flag=1;/*找到学号对应的学生时，flag被赋值为1*/
			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("姓名:       学号:        成绩排位:      总分:      加权平均分:       高数/平时分:  英语/平时分:  体育/平时分:  \n");
			printf("%-10s  %-ld  %9d  %9d  %13.2f  ",stu[i].name,stu[i].number,i+1,stu[i].stutotal,stu[i].stuaverage);
			for(j=0;j<x;j++)
			{
				printf("%2d  %2d",stu[i].score[j],stu[i].psscore[j]);
			}
			printf("\n");
			break;//编号唯一 
		}
	}
	if(flag==0)/*未找到学号对应学生时，flag的值仍为0*/
	{
		printf("\n未找到此学生!\n");
    }
}

/*按姓名查找学生并输出学生信息*/
void SearchName(STUDENT stu[],int n,int x)
{
	int i,j,flag=0;/*未找到学生时flag初始化为0*/
	char tep[M];
	printf("输入姓名:\t");
  scanf(" %s",tep);
	SortStuScoreUpdown(stu,n);/*获得学生的排名情况*/
	for(i=0;i<n;i++)/*将录入的学生姓名与待查姓名进行比对*/
	{
		if(strcmp(stu[i].name,tep)==0)/*找到待查姓名*/
		{
			flag=1;/*找到学号对应的学生时，flag被赋值为1*/
			printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("姓名:     学号:      成绩排位:      总分:      加权平均分:      高数/平时分:  英语/平时分:  体育/平时分:  \n");
			printf("%-10s  %-ld  %9d  %9d  %13.2f  ",stu[i].name,stu[i].number,i+1,stu[i].stutotal,stu[i].stuaverage);
			for(j=0;j<x;j++)
			{
				printf("%2d  %2d",stu[i].score[j],stu[i].psscore[j]);
			}
			printf("\n");
			//break;//姓名不唯一 
		}
	}
	if(flag==0)/*未找到学号对应学生时，flag的值仍为0*/
	{
		printf("\n未找到此学生!\n");
	}
}


/*输出各学生的学生信息及各课程的总分和加权平均分*/
void List(STUDENT stu[],int subtotal[],float subaverage[],int n,int x)
{
	int i,j;
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("姓名:     学号:      总分:      加权平均分:      高数/平时分:  英语/平时分:  体育/平时分:  \n");
	for(i=0;i<n;i++)
    {
        printf("%-10s  %-ld  %9d  %13.2f  ",stu[i].name,stu[i].number,stu[i].stutotal,stu[i].stuaverage);
        for(j=0;j<x;j++)
        {
            printf("%6d  %6d",stu[i].score[j],stu[i].psscore[j]);
        }
        printf("\n");
    }
     printf("          \t             \t           \t           \t");
     for(j=0;j<x;j++)
     {
      printf("%6d",subtotal[j]);
     }
      printf("\n");
      printf("         \t             \t           \t          \t");
      for(j=0;j<x;j++)
      {
          printf("%6.2f",subaverage[j]);
      }
}

/*打印姓名，学号，总分，均分及各学科的分数*/
void Print1(STUDENT stu[],int n,int x)
{
	int i,j;
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("姓名:     学号:      总分:         平均分:      高数/平时分:     英语/平时分:     体育/平时分:  \n");
    for(i=0;i<n;i++)
    {
        printf("%-10s  %-ld  %9d  %13.2f\t",stu[i].name,stu[i].number,stu[i].stutotal,stu[i].stuaverage);
        for(j=0;j<x;j++)
        {
			printf("      %-6d  %-6d",stu[i].score[j],stu[i].psscore[j]);
        }
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\n");
    }
}

/*打印各学科的总分和均分*/
void Print2(int subtotal[],float subaverage[],int x)
{
  int i;
  printf("++++++++++++++++++++++++++++\n");
  			printf("学科分类\n");
  			printf("1.高数 2.英语 3.体育\n");
  for(i=0;i<x;i++)
  {
    printf("学科%d总分: %-6d  学科%d平均分: %-6.2f\n",i+1,subtotal[i],i+1,subaverage[i]);
  }
}

/*将信息写入文件并保存*/
void WritetoFile(STUDENT stu[],int subtotal[],float subaverage[],int n,int x)
{
  FILE *fp;
  int i,j;
  if((fp=fopen("学生成绩信息导出.txt","w"))==NULL)/*检验文件是否打开成功*/
  {
    printf("打开文件失败!\n");
    exit(0);
  }
  fprintf(fp,"%d  %d\n",n,x);
  for(i=0;i<n;i++)
  {
    fprintf(fp,"%-10s  %-ld  %9d  %13.2f  ",stu[i].name,stu[i].number,stu[i].stutotal,stu[i].stuaverage);
     for(j=0;j<x;j++)
        {
            fprintf(fp,"%-6d %-6d\n",stu[i].score[j],stu[i].psscore[j]);
        }
  }
  for(j=0;j<x;j++)
  {
      fprintf(fp,"%d  %f\n",subtotal[j],subaverage[j]);
  }
  fclose(fp);
}

/*从文件中读取出信息*/
void ReadfromFile(STUDENT stu[],int subtotal[],float subaverage[],int *n,int *x)
{
  FILE *fp;
  int i,j;
  if((fp=fopen("学生成绩信息导出.txt","r"))==NULL)/*检验文件是否打开成功*/
  {
    printf("打开文件失败!\n");
    exit(0);
  }
   fscanf(fp,"%d  %d\n",n,x);
  for(i=0;i<*n;i++)
    {
      fscanf(fp,"%10s",stu[i].name);
      fscanf(fp,"%ld",&stu[i].number);
      fscanf(fp,"%9d",&stu[i].stutotal);
      fscanf(fp,"%f",&stu[i].stuaverage);
      for(j=0;j<*x;j++)
      {
        fscanf(fp,"%6d  %6d",&stu[i].score[j],&stu[i].psscore[j]);
      }
    }
    for(j=0;j<*x;j++)
    {
        fscanf(fp,"%d  %f",&subtotal[j],&subaverage[j]);
    }
    fclose(fp);
}
void Mulua()  //二级循环主目录 
{
	            printf("\n\t\t\t\t++++++++++++++++++++++++++++++++++++++\n");
				printf("\t\t\t\t+         1.输入学生记录             +\n");
			    printf("\t\t\t\t+    2.计算每门课程的总分和均分      +\n"); 
				printf("\t\t\t\t+    3.计算每个学生的总分和加权平均分+\n");
				printf("\t\t\t\t+    4.按每个学生的总分降序排序      +\n");
				printf("\t\t\t\t+    5.按每个学生的总分升序排序      +\n");
				printf("\t\t\t\t+    6.按高数成绩高低排序            +\n");
				printf("\t\t\t\t+    7.按英语成绩高低排序            +\n");
				printf("\t\t\t\t+    8.按体育成绩高低排序            +\n");
				printf("\t\t\t\t+    9.按学号大小排序                +\n");
				printf("\t\t\t\t+    10.按名称按字典顺序排序         +\n");
				printf("\t\t\t\t+    11.按学号搜索                   +\n");
				printf("\t\t\t\t+    12.按学生姓名搜索               +\n");
				printf("\t\t\t\t+    13.列表统计                     +\n");
				printf("\t\t\t\t+    14.写入文件                     +\n");
				printf("\t\t\t\t+    15.读取文件                     +\n");
				printf("\t\t\t\t+    0.退出系统                      +\n");
				printf("\t\t\t\t++++++++++++++++++++++++++++++++++++++\n");
				printf("\n\t\t\t\t请输入相关选项的代号: "); 
}

int main()
{
	int m,n,x;
	int subtotal[X];
	float subaverage[X];
	STUDENT stu[N];
	do{
        printf("请输入学生总数:");
        scanf("%d",&n);
        printf("请输入学科总数:");
        scanf("%d",&x);
    }while(n<=0||n>100||x<1||x>10);/*检测学生总人数及学科总数是否符合要求*/
 while(1){
   Mulua();
   scanf("%d",&m);
    switch(m)/*利用switch语句实现菜单中的各个功能*/
    {
      case 1: Input(stu,n,x);
               break;
      case 2: SubCalculate(stu,subtotal,subaverage,n,x);
               break;
      case 3:StuCalculate(stu,n,x);
               break;
      case 4: SortStuScoreUpdown(stu,n);
               Print1(stu,n,x);
              break;
      case 5: SortStuScoreDownup(stu,n);
              Print1(stu,n,x);
             break;
      case 6: SortMathScoreUpdown(stu,n);
	                 Print1(stu,n,x);
	                break;
      case 7: SortEnglishScoreUpdown(stu,n);
	  	                 Print1(stu,n,x);
	  	                break;
      case 8: SortPEScoreUpdown(stu,n);
	  	                 Print1(stu,n,x);
	  	                break;
      case 9: SortNumberDownup(stu,n);
	                Print1(stu,n,x);
	              break;
      case 10: SortName(stu,n);
	                Print1(stu,n,x);
	              break;
      case 11: SearchNumber(stu,n,x);
	              break;
      case 12: SearchName(stu,n,x);
	  	              break;
      case 13: List(stu,subtotal,subaverage,n,x);
	              break;
      case 14: WritetoFile(stu,subtotal,subaverage,n,x);
	              break;
	  case 15: ReadfromFile(stu,subtotal,subaverage,&n,&x);
	                  Print1(stu,n,x);
	                  Print2(subtotal,subaverage,x);
	              break;
      case 0: exit(0);
      default:
	      printf("选择功能错误!\n");
    }
 }
   return 0;
}
