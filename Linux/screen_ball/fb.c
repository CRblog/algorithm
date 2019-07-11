#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sys/mman.h>
/*
   用于保存屏幕窗口的水平及垂直像素点分辨率
 */
int xres, yres;
/*
   一屏数据对应的字节总数
 */
int sz;
/*内核的frambuffer映射到的用户空间地址*/
unsigned short *fb;

void fb_init(void)
{
	int fd;
	int ret;
	struct fb_var_screeninfo info;
    //打开设备文件
	fd = open("/dev/fb0", O_RDWR);
	if (fd < 0) {
		printf("open /dev/fb0 error!\n");
		exit(1);
	}
    //取得屏幕相关参数
    //fd是文件流指针
    //
	ret = ioctl(fd, FBIOGET_VSCREENINFO, &info);
	if (ret != 0) {
		printf("ioctl error!\n");
		exit(1);
	}
    //获取屏幕的长宽高，计算屏幕的大小
	xres = info.xres;  //xres = info.xres + 10;
	yres = info.yres;
	sz = xres*yres*(info.bits_per_pixel >> 3);

	fb = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED
			, fd, 0);
	//映射屏幕缓冲区到用户地址空间，之后就可以用fb指针来读写缓冲区
	if (fb == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}
}


