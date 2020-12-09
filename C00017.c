#include<stdio.h>

int main()
{

#if 0
 int a = 1;
 int b = 5;
 int c;
 c = a || b;//逻辑或，同假才为假
 //汉字忘加注释符产生error: stray ‘\351’ in program
 // c = a && b;//逻辑与，同真才为真

 printf("%d\n",c);
#endif

#if 0
 int a = (int)3.14;//强制类型转换
#endif
 return 0;
}
