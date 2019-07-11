#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sys/mman.h>
/*
   ���ڱ�����Ļ���ڵ�ˮƽ����ֱ���ص�ֱ���
 */
int xres, yres;
/*
   һ�����ݶ�Ӧ���ֽ�����
 */
int sz;
/*�ں˵�frambufferӳ�䵽���û��ռ��ַ*/
unsigned short *fb;

void fb_init(void)
{
	int fd;
	int ret;
	struct fb_var_screeninfo info;
    //���豸�ļ�
	fd = open("/dev/fb0", O_RDWR);
	if (fd < 0) {
		printf("open /dev/fb0 error!\n");
		exit(1);
	}
    //ȡ����Ļ��ز���
    //fd���ļ���ָ��
    //
	ret = ioctl(fd, FBIOGET_VSCREENINFO, &info);
	if (ret != 0) {
		printf("ioctl error!\n");
		exit(1);
	}
    //��ȡ��Ļ�ĳ���ߣ�������Ļ�Ĵ�С
	xres = info.xres;  //xres = info.xres + 10;
	yres = info.yres;
	sz = xres*yres*(info.bits_per_pixel >> 3);

	fb = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED
			, fd, 0);
	//ӳ����Ļ���������û���ַ�ռ䣬֮��Ϳ�����fbָ������д������
	if (fb == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}
}


