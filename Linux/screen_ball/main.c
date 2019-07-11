#include "fb.h"
#include "screen.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define N 8

struct circle c[N];

void *do_circle(void *data)
{
	struct circle *c = data;
	while (1) {
		usleep(30000);
		move_circle(c);
	}
}

int main(void)
{
	int i;
	pthread_t tid[N];

	fb_init();  //读取缓冲区

	screen_set_bak(); //屏幕直接附颜色

	for (i = 0;  i < N; i++) {
		// 初始化一个圆，把这个圆交给线程去控制
		circle_init(c+i);
		pthread_create(tid+i, NULL, do_circle, c+i);
		sleep(1);
	}
	getchar();
	return 0;
}

