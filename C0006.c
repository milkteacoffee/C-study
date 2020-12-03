#include<stdio.h>

//3.#define 定义的标识符常量
//#define MAX 10

//4.枚举常量-enum
//枚举：一一列举
enum Sex
{
  MALE,
  FEMALE,
  SECRET
};
int main()
{
//enum Sex s = MMALE;
printf("%d\n",MALE);//0
printf("%d\n",FEMALE);//1
printf("%d\n",SECRET);//2


#if 0
int a[MAX] = {0};
printf("%d\n",MAX);

const int n = 10;//n是变量，但是又有常属性，所以我们说n是常变量，
int a[10] = {0};
//2.const-常属性
//const修饰的常变量
const int num = 4;
printf("%d\n",num);
//num = 8;
//printf("%d\n",num);

//1.字面常量
//4;
//3.14;
//20;

#endif

return 0;
}
