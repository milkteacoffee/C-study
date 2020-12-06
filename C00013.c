#include<stdio.h>

int main()
{
  int i = 0;
  int num[10] = {1,2,3,4,5,6,7,8,9,10};
   while(i<10)//while拼写错误-->error: expected ‘;’ before ‘{’ token
  	{
  	printf("%d ",num[i]);
	i++;
    }
  return 0;
}
