#include<stdio.h>

int add(int x,int y)
{
int z = x+y;
return z;
}
int main()
{
  int a = 1000;
  int b = 314;
  int c = 250;
  int d = 270;
  int sum = 0;
  int sum1 = 0;
  sum = add(a, b);
  sum1 = add(c, d);
  printf("%d\n",sum);
  printf("%d\n",sum1);
  return 0;
}
  	
   
