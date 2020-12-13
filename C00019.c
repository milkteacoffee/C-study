#include<stdio.h>

int main()
{
 int x = 0;
 float y = 0;//类型错误产生warning: format ‘%f’ expects argument of type ‘double’, but argument 3 has type ‘int’ [-Wformat=]
 int a = 1;
 float b = 2.1;
 a++;
 b++;
 printf("%d %.1f\n",a,b);
 ++a;
 ++b;
 printf("%d %.1f\n",a,b);
 x = a++;
 y = b++;
 printf("%d %.1f\n",x,y);
 printf("%d %.1f\n",a,b);
#if 0
 int x=0,y=0,z=0;
 scanf("%d*%d%d",&x,&y,&z);//忘记加取地址符产生
 printf("%d%d%d\n",x,y,z);//warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘int’ [-Wformat=]
#endif
 return 0;
}
