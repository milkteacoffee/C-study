#include<stdio.h>
#include<string.h>

int main()
{
 char ch = 'A';
 int i;
 for(i=1;i<=5;i++)
 	{
 	ch++;
	printf("%*c\n",i,ch);
 	}
 return 0;
 /*输出结果
   B
	C
	 D
	  E
	   F*/
}
