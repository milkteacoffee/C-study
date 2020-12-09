#include<stdio.h>

int Max(int a,int b)
{
 if(a>b)
 	return a;//拼写return错误-->error: ‘retun’ undeclared (first use in this function)
 else
 	return b;
}
int main()
{
 int a,b;//未定义a,b，错误-->error: ‘a’ undeclared (first use in this function)
 int max = 0;
 scanf("%d%d",&a,&b);
 max = Max(a,b);
 printf("Max=%d\n",max);
 return 0;
}


#if 0
int Max()
{
  int a,b;
  int max = 0;
  scanf("%d %d",&a,&b);
  if(a>b)
  	{
  	max = a;
	printf("MAX:%d\n",max);
    }
 else if(b>a)
	{
	max = b;
    printf("MAX:%d\n",max);
    }
	return 0;
}
int main()
{
 Max();
 return 0;
}
#endif



#if 0
int main()
{
 int a,b;
 int max = 0;
 scanf("%d %d",&a,&b); //忘加取地址符（&），产生警告
 if(a>b)//warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘int’ [-Wformat=]
	{
	max = a;
	printf("MAX:%d\n",max);
    }
 else if(b>a)
	{
	max = b;
    printf("MAX:%d\n",max);
    }

 return 0;
}
#endif
