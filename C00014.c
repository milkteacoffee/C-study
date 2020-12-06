#include<stdio.h>

int main()
{
int a = 10;
int b[10] = {0};
int num = 0;
//sizeof计算的是变量/类型所占空间的大小，单位为字节
num = sizeof(b)/sizeof(b[0]);//计算数组元素的个数
printf("%d\n",num);//数组总大小/每个元素的大小
printf("%d\n",sizeof(a));//4
printf("%d\n",sizeof(int));//4
printf("%d\n",sizeof a);//4
printf("%d\n",sizeof(b));
 /* int a = 0;
  printf("%d\n",a);
  printf("%d\n",!a);*/
  return 0;
}
