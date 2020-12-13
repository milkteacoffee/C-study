#include<stdio.h>

int main()
{
 int a=3,b=5,c;
 c = (a>b)?(a+b):(a-b);//三目运算符，当表达式1为真（1）时，结果为表达式2的值
 printf("Max is %d\n",c);//反之，表达式1为假（0），结果为表达式3的值
 a = 6;
 b = 2;
 c = (a>b)?(a-b):(a+b);
 printf("Max is %d\n",c);
 return 0;
}
