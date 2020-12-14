#include<stdio.h>
#include<string.h>

int main()
{
 float b = 34.425;
 float c = 52.954;
 int a1 = 0;
 a1 = (int)b+(int)c;//强制类型转换
 printf("%d\n",a1);
#if 0
float r = 3.4;
float l = 0;
float s = 0;
l = 2*3.14*3.4;
s = 3.14*3.4*3.4;
printf("L=%.2fcm S=%.2f\n",l,s);
#endif
#if 0
 unsigned int a,b,c;
 a = 65;
 b = 66;
 c = 67;
 printf("%c %c %c\n",a,b,c);
#endif
 return 0;
}
