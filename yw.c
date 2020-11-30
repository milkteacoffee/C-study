#include<stdio.h>
#define n 4
  
int main()
{
	int i;
    int a[n];
	for(i=0;i<4;i++)
	{
		scanf("%d",&a[i]);
	}
    int max = 0;
    int max_i = 0;
    for (i=0; i<4; i++)
    {
     if (a[i] > max) 
      {
		max = a[i];
		max_i = i;
      }
    }
    printf("%d,%d\n", max, max_i);
}