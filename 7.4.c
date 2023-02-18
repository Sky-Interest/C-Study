#include<stdio.h>
int ZXGBS(int a,int b);
int main()
{
	int a,b,x;
	printf("输入a和b：");
	scanf("%d,%d",&a,&b);
	x=ZXGBS(a,b);
	if(x!=-1){
	   printf("%d和%d中最小公倍数为：%d\n",a,b,x);
	}else{
		printf("输入错误\n");
	}
	return 0;
}

int ZXGBS(int a,int b)
{
	int i;
	if(a<=0||b<=0){
		return -1;
	}else{
	for(i=1;i<b;i++){
		if(i*a%b==0)  return i*a;
		
   }
	}
   return b*a;
}	
