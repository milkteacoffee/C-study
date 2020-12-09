#include<stdio.h>

//static修饰局部变量
//局部变量的生命周期变长
//static修饰全局变量
//改变了变量的作用域，让静态的全局变量只能在自己所在的源文件
//内部使用，出了源文件就没办法使用了
//static修饰函数
//改变了函数的链接属性（外部连接属性->内部链接属性）

#if 0
void mash()
{
  static int a = 1;
  a++;
  printf("a=%d\n",a);
}
int main()
{
 int i =0;
 while(i<5)
 	{
 	mash();
	i++;
 	}
 #endif
 return 0;
}
