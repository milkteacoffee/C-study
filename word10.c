#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <linux/input.h>	
	
	
char the_number[12][16*29/8] = {
/*--  文字:  1  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x1F,0x80,0x1F,0x80,
0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,
0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x07,0xC0,
0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  2  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x1C,0xF0,0x38,0x38,
0x70,0x3C,0x78,0x3C,0x78,0x3C,0x38,0x3C,0x00,0x38,0x00,0x78,0x00,0x70,0x00,0xE0,
0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x0C,0x38,0x1C,0x70,0x1C,0x7F,0xF8,
0x7F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  3  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x3C,0xF0,0x38,0x70,
0x78,0x78,0x78,0x38,0x38,0x38,0x00,0x78,0x00,0x70,0x01,0xE0,0x07,0xC0,0x01,0xF0,
0x00,0x78,0x00,0x38,0x00,0x3C,0x30,0x3C,0x78,0x3C,0x78,0x38,0x78,0x38,0x3C,0xF0,
0x1F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  4  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xF0,0x01,0xF0,
0x01,0xF0,0x03,0xF0,0x07,0xF0,0x06,0xF0,0x0E,0xF0,0x1C,0xF0,0x18,0xF0,0x30,0xF0,
0x70,0xF0,0x60,0xF0,0xFF,0xFE,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,
0x07,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  5  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,0x3F,0xF8,0x38,0x00,
0x38,0x00,0x38,0x00,0x38,0x00,0x30,0x00,0x3F,0xE0,0x3F,0xF0,0x38,0x78,0x30,0x38,
0x00,0x3C,0x00,0x3C,0x00,0x3C,0x38,0x3C,0x78,0x3C,0x78,0x38,0x78,0x78,0x3C,0xF0,
0x1F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  6  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF0,0x0F,0x78,0x1C,0x78,
0x38,0x38,0x38,0x00,0x78,0x00,0x78,0x00,0x77,0xF0,0x7F,0xF8,0x7C,0x38,0x78,0x3C,
0x78,0x1C,0x70,0x1C,0x70,0x1C,0x78,0x1C,0x78,0x1C,0x38,0x3C,0x3C,0x38,0x1E,0x70,
0x0F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  7  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFC,0x3F,0xFC,0x78,0x18,
0x70,0x30,0x60,0x70,0x00,0x60,0x00,0xE0,0x00,0xC0,0x01,0xC0,0x01,0xC0,0x03,0x80,
0x03,0x80,0x03,0x80,0x07,0x80,0x07,0x80,0x07,0x80,0x07,0x80,0x07,0x80,0x07,0x80,
0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  8  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xE0,0x3C,0xF0,0x38,0x38,
0x70,0x3C,0x70,0x1C,0x70,0x1C,0x78,0x38,0x3E,0x38,0x1F,0xF0,0x0F,0xE0,0x1F,0xF0,
0x38,0xF8,0x70,0x78,0x70,0x3C,0x70,0x1C,0x70,0x1C,0x70,0x1C,0x78,0x38,0x3C,0xF0,
0x1F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  9  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xE0,0x3C,0xF0,0x38,0x78,
0x70,0x38,0x70,0x3C,0x70,0x3C,0x70,0x3C,0x70,0x3C,0x70,0x3C,0x78,0x7C,0x3C,0xFC,
0x1F,0xFC,0x07,0x3C,0x00,0x3C,0x00,0x38,0x00,0x78,0x38,0x70,0x38,0xF0,0x3D,0xE0,
0x1F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  0  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x1E,0xF0,0x1C,0x70,
0x38,0x38,0x38,0x38,0x78,0x3C,0x78,0x3C,0x70,0x3C,0x70,0x3C,0x70,0x3C,0x70,0x3C,
0x70,0x3C,0x70,0x3C,0x78,0x3C,0x78,0x3C,0x38,0x38,0x38,0x38,0x1C,0x70,0x1E,0xF0,
0x0F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  *  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,
0x03,0x80,0x03,0x80,0x73,0x9C,0x7F,0xBC,0x7F,0xFC,0x1F,0xF0,0x03,0x80,0x1F,0xF0,
0x7F,0xFC,0x7B,0xBC,0x73,0x9C,0x03,0x80,0x03,0x80,0x03,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  #  --*/
/*--  宋体22;  此字体下对应的点阵为：宽x高=15x29   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=16x29  --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x38,0x0C,0x38,0x0C,0x38,
0x1C,0x30,0x7F,0xFC,0xFF,0xFE,0xFF,0xFE,0x1C,0x30,0x1C,0x30,0x18,0x70,0x18,0x70,
0x18,0x70,0x7F,0xFC,0xFF,0xFE,0xFF,0xFE,0x38,0x60,0x38,0x60,0x38,0x60,0x38,0x60,
0x38,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};






int lcd_fd = 0;
int *plcd = NULL;
int show_word(char data[],int x0,int y0,int w,int len,int color);







void lcd_draw_point(int x,int y,int color)
{
	if(x>=0&&x<800&&y>=0&&y<480)
	{
		*(plcd+x+800*y)=color;
	}
	
}




int display_bmp(int x0,int y0,const char *bmppath)
{
    //1.打开BMP文件
    int fd_bmp = open(bmppath,O_RDONLY);
    if(fd_bmp == -1)
    {
        perror("open bmp file failed");
        return -1;
    }

    unsigned char buf[4] = {0};
    //2.判断当前打开的文件到底是不是一张BMP文件
    int ret = read(fd_bmp,buf,2);
    if(ret == -1)
    {
        perror("read bmp failed");
        return -1;
    }

    if(buf[0] == 0x42 && buf[1] == 0x4D)
    {
        printf("%s is bmp file!\n",bmppath);
    }
    else
    {
        printf("%s is not bmp file!\n",bmppath);
        printf("bye bye!\n");
        return -1;
    }

    //3.先把光标偏移至宽度数据之前后再去读取文件的宽度数据
    lseek(fd_bmp,0x12,SEEK_SET);

    int width;
    ret = read(fd_bmp,buf,4);
    if(ret == -1)
    {
        perror("read bmp width failed");
        return -1;
    }

    width = (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
    printf("width = %d\n",width);



    //4.先把光标偏移至高度数据之前后再去读取文件的高度数据
    lseek(fd_bmp,0x16,SEEK_SET);

    int hight;
    ret = read(fd_bmp,buf,4);
    if(ret == -1)
    {
        perror("read bmp hight failed");
        return -1;
    }

    hight = (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
    printf("hight = %d\n",hight);


    //5.先把光标偏移至位深数据之前后再去读取文件的位深数据
    lseek(fd_bmp,0x1c,SEEK_SET);
	
	int depth;
    ret = read(fd_bmp,buf,2);
    if(ret == -1)
    {
        perror("read bmp depth failed");
        return -1;
    }

    depth =(buf[1] << 8) | buf[0];
    printf("depth = %d\n",depth);


    //6.根据宽度高度位深算出应该在内存中开辟一块多少的空间去保存像素数组
	int naizi;
	int real_byte;
	int real;
	
	if(width*depth/8%4!=0)
	{
		naizi=4-width*depth/8%4;
		real=width*depth/8+naizi;
	}
	else
	{
		real=width*depth/8+naizi;
	}
		real_byte=width*depth/8;

   
    //7.先把光标偏移至像素数组数据之前后再去读取文件的像素数组数据
	lseek(fd_bmp,54,SEEK_SET);
	
	unsigned char pixel_date[800*480*3]={0};
    ret = read(fd_bmp,pixel_date,real_byte*hight);
    if(ret !=real_byte*hight)
    {
        perror("read bmp pixel_date failed");
        return -1;
    }
   
		
    //8.对像素数组数据进行数据处理完后将其画到屏幕对应的像素点上去即可。
	int i;
	int j;
	int color=0;
	int sum=0;
	
	for(i=0;i<hight;i++)
	{	
		for(j=0;j<width;j++)
		{
			color =(pixel_date[2+sum] << 16) | (pixel_date[1+sum] << 8) | pixel_date[0+sum];
			lcd_draw_point(j+x0,(hight-1-i)+y0,color);
			sum=sum+3;
		}
		sum=sum+naizi;
	}
	
}
  


void get_input_event(void)
{
	int fd;
	int x;
	int y;
	int i=0;
	struct input_event ev;

	/* 打开输入事件文件  /dev/input/event0 */
	fd = open("/dev/input/event0",O_RDONLY);
	if(-1 == fd)
	{

	}
	
	/* 从文件中，读取输入事件 ==》 struct input_event结构数据 */
	while(1)
	{
		read(fd,&ev,sizeof(ev));	//ev结构体变量中，就存储了一次输入事件
		printf("0x%x  0x%x  %d\n",ev.type,ev.code,ev.value);

		/* 处理输入事件 */
		if(ev.type == EV_ABS)	//触摸屏事件 0X03
		{
			if(ev.code == ABS_X)	//触摸点的X轴 0X00
			{
				printf("X:%d\n",ev.value);
				x = ev.value;
			}
			else if(ev.code == ABS_Y)	//触摸点的Y轴 0X01
			{
				printf("Y:%d\n",ev.value);
				y = ev.value;
			}
		}

		if(ev.type == EV_KEY)
		{
			if(ev.code == BTN_TOUCH)
			{
				if(ev.value == 1)
				{
		if(i<16)
		{
			if(x>160 && x<320 && y>240 && y<300) //1
			{
						//printf("1");
				show_word(the_number[0],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>320 && x<480 && y>240 && y<300) //2
			{
				show_word(the_number[1],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>480 && x<600 && y>240 && y<300) //3
			{
				show_word(the_number[2],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>160 && x<320 && y>300 && y<360) //4
			{
				show_word(the_number[3],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>320 && x<320 && y>300 && y<360) //5
			{
				show_word(the_number[4],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>480 && x<600 && y>300 && y<360) //6
			{
				show_word(the_number[5],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>160 && x<320 && y>360 && y<420) //7
			{
				show_word(the_number[6],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>320 && x<480 && y>360 && y<420) //8
			{
				show_word(the_number[7],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>480 && x<600 && y>360 && y<420) //9
			{
				show_word(the_number[8],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>320&& x<480 && y>420&& y<480) //0
			{
				show_word(the_number[9],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>160 && x<320 && y>420 && y<480) //*
			{
				show_word(the_number[10],240+i*16,120,16,16*29/8,0x000000);
			}
			else if(x>480 && x<600 && y>420 && y<480) //#
			{
				show_word(the_number[11],240+i*16,120,16,16*29/8,0x000000);
			}
			else 
			{
				i--;
			}
		i++;
		}
					printf("key down:(%d,%d)\n",x,y);
				}
			}
		}
    		
		
		
		
	}

	/* 关闭文件 */
	close(fd);
}





int lcd_init(void)
{
	lcd_fd = open("/dev/fb0",O_RDWR);
	if(-1 == lcd_fd)
	{
		perror("open lcd error");
		return -1;
	}
	plcd = mmap(NULL,	//指定映射空间的地址，NULL表示系统自己选择
				800*480*4, //映射空间大小
				PROT_READ|PROT_WRITE, //映射空间权限 可读可写
				MAP_SHARED,	//共享映射，操作映射内存就是操作了文件
				lcd_fd,		//要映射的文件描述符
				0		//文件偏移量，0表示从头开始映射
			);
	if(MAP_FAILED == plcd)
	{
		perror("mmap errpr");
		return -1;
	}

}





void lcd_show_rectangle(int x0,int y0,int w,int h,int color)
{
	int x;
	int y;
	for(x=x0;x<w;x++)
	{
		for(y=y0;y<h;y++)
		{
			if(x*y<=w*h)
			{
				lcd_draw_point(x,y,color);
			}
		}
	}	
}





	//任务：
		/*
		 *	show_word:可以在屏幕指定位置显示文字
		 *		@data：要显示的文字所在的数组名 比如： 欧 ==》 my_name[0]
		 *		@x0:
		 *		@y0:
		 *		@w : 字体宽度，比如上述的4个字节，宽度是  32像素点
		 *		@len：数组长度，该数组有多少字节 比如上述的为 32*29/8
		 *		@color：文字颜色（请不要跟底色一样）
		*/
int show_word(char data[],int x0,int y0,int w,int len,int color)
{
	int tmp = w/8;	//一行需要多少字节
	int j,i;

	/* 遍历每一个字节 */
	for(j=0;j<len;j++)
	{
		/* 遍历该字节中每个bit位 0不显示，1显示 */
		for(i=7;i>=0;i--)
		{
			/* 判断是否需要显示 */
			if(data[j] & (1<<i))
			{
						
			/*
			要显示的像素点(x,y)坐标与i,j的关系请自行推导
			*/
			lcd_draw_point(x0+(7-i)+(j%tmp*8),y0+(j/tmp),color);
			}
		}
	}			

			
}


int main(void)
{
	lcd_init();
	display_bmp(0,0,"/zhouxin/2.bmp");
	//lcd_show_rectangle(0,0,800,480,0xffffff);
	show_word(the_number[0],160+55,240+25,16,16*29/8,0x000000);
	show_word(the_number[1],320+55,240+25,16,16*29/8,0x000000);
	show_word(the_number[2],480+55,240+25,16,16*29/8,0x000000);
	show_word(the_number[3],160+55,300+25,16,16*29/8,0x000000);
	show_word(the_number[4],320+55,300+25,16,16*29/8,0x000000);
	show_word(the_number[5],480+55,300+25,16,16*29/8,0x000000);
	show_word(the_number[6],160+55,360+25,16,16*29/8,0x000000);
	show_word(the_number[7],320+55,360+25,16,16*29/8,0x000000);
	show_word(the_number[8],480+55,360+25,16,16*29/8,0x000000);
	show_word(the_number[9],320+55,420+25,16,16*29/8,0x000000);
	show_word(the_number[10],160+55,420+25,16,16*29/8,0x000000);
	show_word(the_number[11],480+55,420+25,16,16*29/8,0x000000);
	get_input_event();
		}