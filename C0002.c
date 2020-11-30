#include<stdio.h>

int main()
{
//char 字符类型
 char ch = 'A';//在内存中取一个空间，来存储A
 printf("%c\n",ch);//%c打印字符格式的数据
 short int age = 20;
 printf("%d\n",age);//%d打印整型十进制数据
 long num = 100;//long 长整型
 printf("%ld\n",num);//%ld(%mld 也可)，输出长整型数据
 float f =5.20;//单精度浮点型
 printf("%f\n",f);
 double d =3.1415;//双精度浮点型
 printf("%lf\n",d); 
 return 0;
}

