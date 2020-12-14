#include<stdio.h>

int a,b,h;

int Mash(int x,int y,int z)
{
 int s = 0;
 s = ((a+b)*h)/2;
}
int main()
{
  
  int mash = 0;
  scanf("%d%d%d",&a,&b,&h);
  mash = Mash(a, b, h);
  printf("a=%-5d b=%-5d h=%-5d\n",a,b,h);
  printf("S=%d\n",mash);// 未定义s-->error: ‘s’ undeclared (first use in this function)
  return 0;
}
