#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* print1(void* arg)
{
	while(1)
	{
		printf("I'm ou yang hualiang\n");
		sleep(1);//��ʱ1s
	}
}	

void* print2(void* arg)
{
	while(1)
	{
		printf("is a big shuaige\n");
		sleep(1);
	}
}

int main(void)
{
	pthread_t  tid1,tid2;

	//print1(NULL);
	//print2(NULL);
	pthread_create(&tid1,NULL,print1,NULL);	//����һ���̣߳����߳�ȥִ��  print1����
	pthread_create(&tid2,NULL,print2,NULL);//�ٴ���һ���̣߳����߳�ȥִ��print2����
	//���̻߳��������ִ��
	while(1)
	{
		printf("heiheihei\n");
		sleep(1);
	}
	return 0;
}
