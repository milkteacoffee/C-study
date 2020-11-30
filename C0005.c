#include<stdio.h>

int month = 12;//全局变量在任何地方任何函数中都能使用(整个工程)
find()
	{
	printf("find  month is %d\n",month);
}
int main()
{
//C语言语法规定，变量要定义在当前代码块的最前面
  find();
  extern int number;//extrn声明外部符号（       变量）
  int a = 0;//局部变量的作用域只在当前的代码块之内
  int b = 0;
  int sum = 0;
  scanf("%d %d",&a,&b);//输入函数；&取地址符，将a和b的值放到这个地址中
  sum = a+b;
 { printf("sum = %d\n",sum);}
  printf("number = %d\n",number);
}
