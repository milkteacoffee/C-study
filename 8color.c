#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	unsigned int  color1 = 0x00ff00;
	unsigned int  color2 = 0x0000ff;
    unsigned int  color3 = 0xFF00FF;
	unsigned int  color4 = 0x9400D3;
	unsigned int  color5 = 0x000080;
	unsigned int  color6 = 0xfffacd;
	unsigned int  color7 = 0x8deeee;
	unsigned int  color8 = 0xE6E6FA;
	int w,h;
	int fd;
	
	
	/*打开屏幕文件  /dev/fb0 */
	fd = open("/dev/fb0",O_RDWR);
	/*写入颜色*/
	for(h=0;h<480;h++)
	{
		for(w=0;w<120;w++)
		{
			write(fd,&color1,4);	
		}
		for(w=120;w<240;w++)
		{
			write(fd,&color2,4);	
		}
		for(w=240;w<360;w++)
		{
			write(fd,&color3,4);	
		}
		for(w=360;w<420;w++)
		{
			write(fd,&color4,4);	
		}
		for(w=420;w<500;w++)
		{
			write(fd,&color5,4);	
		}
		for(w=500;w<600;w++)
		{
			write(fd,&color6,4);	
		}
		for(w=600;w<720;w++)
		{
			write(fd,&color7,4);	
		}
		for(w=720;w<800;w++)
		{
			write(fd,&color8,4);	
		}
	}
	

	close(fd);

}