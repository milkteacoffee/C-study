#include <stdio.h>
int zhishu(int m)
{   
    int i; 
    for(i=2;i<m;i++)
        if(m%i==0)
            return 0;
		return 1;
    
}
int digit_to_str(int num,char *str)
{
	int t=num;
	int count=1;
	if(num<0)
	{
		*str++='-';
		count++;
		num=-num;
		t=num;
	}	
	while(t/=10)
	{
		str++;
		count++;
	}
	while(num>0)
	{
		*str--=num%10+'0';
		num/=10;
	}
	return count;
			
}
int main()
{
	int x;
	scanf("%d",&x);
	int ret_val;	//转换后字符数组长度
	char s[100]={0};
	if(1==zhishu(x))
		printf("%d是质数\n",x);
	else
		printf("%d不是质数\n",x);
	ret_val=digit_to_str(-x,s);
	printf("转换结果：%s,，字符串长度：%d\n",s,ret_val);
	return 0;
}