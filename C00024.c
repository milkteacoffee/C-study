#include<stdio.h>

int main()
{
 int x,y;
 int sum = 0;//和
 int cha = 0;//差
 int zhi = 0;//积
 int den = 0;//商
 int yus = 0;//余
 scanf("%d%d",&x,&y);
 sum = x+y;
 cha = x-y;
 zhi = x*y;
 den = x/y;
 yus = x%y;
 printf("sum=%d\ncha=%d\nzhi=%d\nden=%d\nyus=%d\n",sum,cha,zhi,den,yus);
 
 return 0;
}
