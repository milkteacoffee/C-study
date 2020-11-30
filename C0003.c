#include<stdio.h>

int main()
{
  printf("%d\n",sizeof(int));//4个字节（byte），32个比特位（bite）
  printf("%d\n",sizeof(char));//1个字节
  printf("%d\n",sizeof(short));//2个字节
  printf("%d\n",sizeof(long));//8个字节或者4个字节--》sizeof(long)>=sizeof(int)
  printf("%d\n",sizeof(long long));//8个字节
  printf("%d\n",sizeof(float));//4个字节
  printf("%d\n",sizeof(double));//8个字节
  return 0;
}

