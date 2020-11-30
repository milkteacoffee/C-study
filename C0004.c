#include<stdio.h>
int number =1000;//全局变量：定义在代码块（{}）之外的变量
int main()
{
 int number =10;//全局变量和局部变量不要相同，相同会产生Bug；当全局变量和局部变量相同时，局部变量优先
 printf("number is %d\n",number);
 char str = 'X';//局部变量：定义在代码块（{}）之内的变量
 short age = 22;//向内存申请2个字节(16个比特位)，用来存放20
 printf("%d\n",age);
 float weight = 102.5f;//向内存申请4个字节，用来存放小数，f用来规范编写单精度浮点型
 printf("%.1f\n",weight);//.1f保留小数点后一位整数
 return 0;
}

