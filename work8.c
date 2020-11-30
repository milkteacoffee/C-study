#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

int lcd_fd = 0;		
int *plcd = NULL;	


int lcd_init(void)
{
	
	lcd_fd = open("/dev/fb0",O_RDWR);//打开Lcd屏
	if(-1 == lcd_fd)                 //LCD打开失败时，返回-1
	{
		perror("open lcd error");
		return -1;
	}
	
	plcd = mmap(NULL,800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED,lcd_fd,0);
	
	if(MAP_FAILED == plcd)//当文件映射失败时，返回-1
	{
		perror("mmap errpr");
		return -1;
	}
}



void lcd_uninit(void)
{
		munmap(plcd,800*480*4);
		close(lcd_fd);
}



void lcd_draw_point(int x,int y,int color)
{
	int h,w;
		for(h=0;h<480;h++)
		{
			for(w=0;w<800;w++)
			{
			
				if(x==w&&y==h)
				{
					*(plcd+w+800*h) = color;
				}
				
			}
		}
}




void lcd_show_rectangle(int x0,int y0,int w,int h,int color)
{
	int x,y;
	for(x=0;x<480;x++)
	{
		for(y=0;y<800;y++)
		{
			if(x>x0&&x<h)
			
			{
				if(y>y0&&y<w)
				*(plcd+y+800*x) = color;
			}
		}
	}
}




void lcd_show_round(int x0,int y0,int r,int color)
{
		int h,w;
		for(h=0;h<480;h++)
			{
				for(w=0;w<800;w++)
				{
				
					if((w-x0)*(w-x0) + (h-y0)*(h-y0)<=r*r)
					{
						*(plcd+w+800*h) = color;
					}
				}
			}
}



int main(void)
{
	lcd_init();
	
	lcd_show_rectangle(0,0,800,480,0x0000ff);	
	
	lcd_show_rectangle(400, 240, 400, 400, 0xff0000);
	
	lcd_show_round(400,240,24,0x00ff00);

	lcd_draw_point(400,240,0xffffff);

	lcd_uninit();
	

}
