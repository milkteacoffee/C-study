#include<stdio.h>

int main()
{
 int a = 520;
 int b = a++;//后置++，先使用，再++（后置--相同）
 int c = ++a;//前置++，先++，再使用（前置--相同）
 printf("a=%d b=%d\n",a,b);
 printf("c=%d\n",c);
 

#if 0
 int a = 0;
 int b = ~a;//b是有符号的整型，负数存储的是二进制的补码
 printf("%d\n",b);//-1
  #endif
  return 0;

}
