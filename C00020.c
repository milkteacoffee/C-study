#include<stdio.h>

int main()
{
 int a=4,b=8,c=6;
 int d1,d2,d3,d4;
 d1 = (a<b)||(++a==5)||(c>b--);
 printf("d1=%d a=%d b=%d c=%d\n",d1,a,b,c);
 d2 = (a>b)&&(++a==5)||(c>b--);
 printf("d2=%d a=%d b=%d c=%d\n",d2,a,b,c);
 d3 = (a<b)||(++a==5)&&(c>b--);
 printf("d3=%d a=%d b=%d c=%d\n",d3,a,b,c);
 d4 = (a>b)&&(++a==5)&&(c>b--);
 printf("d4=%d a=%d b=%d c=%d\n",d4,a,b,c);
/*输出结果
 d1=1 a=4 b=8 c=6
 d2=0 a=4 b=7 c=6
 d3=1 a=4 b=7 c=6
 d4=0 a=4 b=7 c=6*/
 return 0;
}
