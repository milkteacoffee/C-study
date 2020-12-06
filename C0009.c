#include<stdio.h>
#include<string.h>

int main()
{
printf("%d\n",strlen("c:\test\32\test.c"));
printf("%c\n",'\132');//Z
printf("%c\n",'\x61');//a
//\32--32是2个八进制数字
//32作为八进制代表的那个十进制数字，作为ASCLL码值，对应的字符
//32-->十进制数26-->作为ASCLL码值代表的字符 (  ->)箭头
return 0;
}
