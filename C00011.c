#include<stdio.h>
 int main()
{
int line = 0;
printf("培训或自学\n");

  while(line<20000)
  {
    printf("敲一行代码：%d\n",line);//没加%d，会产生一个警告
    line++;// warning: too many arguments for format [-Wformat-extra-args]
	//break;
  }
  if(line>=20000)
printf("包吃包住7000+\n");
return 0;
}
