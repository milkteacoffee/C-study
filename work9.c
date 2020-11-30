#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

//屏幕文件的描述符
int fd_lcd = -1;
//映射区域的指针
int *plcd = NULL;

/*
 *	lcd_draw_point:LCD画点函数，用来将指定像素点上色
 *		@x：像素点X轴坐标
 *		@y：像素点Y轴坐标
 *		@color：像素点颜色值
 *	返回值：
 *		无
 *	NOTE:
 *		调用lcd_draw_point(200,100,0xff0000);
 *		可以将坐标为(200,100)的像素点显示为红色
 *
 *		注意：x的有效范围是 0~799
 *			  y的有效范围是 0~479
**/

void lcd_draw_point(int x,int y,int color)
{
	if(x>0 && x<800 && y>0 && y<480)
	{
		*(plcd+x+800*y) = color;
	}
}

/*
    将bmppath指向的BMP文件显示到(x0,y0)处
    返回值:显示图片成功返回0,显示图片失败返回-1
*/
int display_bmp(int x0,int y0,const char *bmppath)
{
    //1.打开BMP文件
    int fd_bmp = open(bmppath,O_RDONLY);
    if(fd_bmp == -1)
    {
        perror("open bmp file failed");
        return -1;
    }

    unsigned char buf[4] = {0};//定义一个无符号（unsigned）长度为4的数组，初值为0
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
        printf("the end\n");
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
	
	int height;
	int ret1 = read(fd_bmp,buf,4);
	if(ret1 == -1)
    {
        perror("read bmp height failed");
        return -1;
    }
	
	height = (buf[3] <<24) | (buf[2] << 16) | (buf[1] <<8) | buf[0];
	printf("height = %d\n",height);
	
    //5.先把光标偏移至位深数据之前后再去读取文件的位深数据
	lseek(fd_bmp,0x1C,SEEK_SET);
	int bitdepth;
	int ret2 = read(fd_bmp,buf,2);//bmp文件的数据存储是小端模式，而读取时从内存地址的开头开始读
	if(ret2 == -1)
    {
        perror("read bmp bitdepth failed");
        return -1;
    }
	bitdepth = (buf[1] <<8) | buf[0]  ;//?read(,,?)！指读多少个字节到buf中
	printf("bitdepth = %d\n",bitdepth);

    //6.根据宽度高度位深算出应该在内存中开辟一块多少的空间去保存像素数组
	
    if(width%4 == 1)
	{
		width=width+3;
	}
	else if(width%4 == 2)
	{
		width=width+2;
	}
	else if(width%4 == 3)
	{
		width=width+1;
	}
	int place;
	place = width*height*bitdepth/8;
	
    //7.先把光标偏移至像素数组数据之前后再去读取文件的像素数组数据
	
	lseek(fd_bmp,0x36,SEEK_SET);
	unsigned char buf1 [place];
	int ret3 = read(fd_bmp,buf1,place);
	if(ret3 == -1)
    {
        perror("read bmp bitdepth failed");
        return -1;
    }
	
    //8.对像素数组数据进行数据处理完后将其画到屏幕对应的像素点上去即可。
	int h,w,color=0,n=0;//n表示第一个像素点
	for(h=0;h<height;h++)
	{
		for(w=0;w<width;w++)
		{
			if(bitdepth/8 == 3)
			{
				color=buf1[2+3*n] <<16 | buf1[1+3*n] <<8 | buf1[0+3*n];
				printf("2");
			}
			else if(bitdepth/8 == 4)
			{
				color=buf1[3+4*n] << 24 | buf1[2+4*n] <<16 | buf1[1+4*n] <<8 | buf1[0+4*n];
				printf("1");
			}
			//lcd_draw_point(h,w,color);
			printf("3");
			n++;
	    }
	}
}
/*
    对屏幕文件的初始化
    返回值:初始化成功返回0,初始化失败返回-1
*/
int lcd_init(void)
{
    fd_lcd = open("/dev/fb0",O_RDWR);
    if(fd_lcd == -1)
    {
        perror("open lcd failed");
        return -1;
    }

    plcd = mmap(NULL,480*800*4,PROT_READ | PROT_WRITE,MAP_SHARED,fd_lcd,0);
    if(plcd == MAP_FAILED)
    {
        perror("mmap failed");
        return -1;
    }
    return 0;
}

/*
    对屏幕文件的解初始化
*/
void lcd_uinit(void)
{
    close(fd_lcd);
    munmap(plcd,480*800*4);
}

int main()
{
    lcd_init();
    display_bmp(100,250,"./1.bmp");
    lcd_uinit();
}

