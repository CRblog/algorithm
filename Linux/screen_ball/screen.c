#include "fb.h"
#include "screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAK_COL 0xFFFF00  //屏幕颜色

#define STEP 3
struct position {
	int x;
	int y;
};

/*８个元素代表了圆运行的轨迹: 1则表示加，-1则表示减，０则表示不变*/
struct position actions[8] = {
	{1,  0},{1, -1},{1,   1},
	{0,  1},{0, -1},
	{-1, 0},{-1, 1},{-1, -1}
};

void draw_point(int x, int y, int col)
{
	*(fb + y*xres + x) = col;
}


void draw_circle(struct circle *c)
{
	srand(c->col);
	int x0 = c->x0;
	int y0 = c->y0;
	int r = c->r;
	int col =rand()%0x10000;
	int i, j;

	for (i = y0 - r; i < y0 + r; i++) {
		for (j = x0 - r; j < x0 + r; j++) {
		if ((j-x0)*(j-x0) + (i-y0)*(i-y0) <= r*r) {
			draw_point(j, i, col);
		}
		}
	}
}


void circle_init(struct circle *c)
{
	srand(time(NULL));

	c->r = (yres/7) + rand()%15;

	while (1) {
		c->x0 = rand()%xres;
		if ((c->x0 >= c->r) && (c->x0 <= (xres - 1 - c->r))) {
			break;
		}
	}

	while (1) {
		c->y0 = rand()%yres;
		if ((c->y0 >= c->r) && (c->y0 <= (yres - 1 - c->r))) {
			break;
		}
	}

	c->col = rand()%0x10000;
	c->action = rand()%8;
	c->cnt = 0;


	draw_circle(c);
}

/*设置整个屏幕的颜色为预置的背景色*/
void screen_set_bak(void)
{
	int i, j;
	for (i = 0; i < yres; i++) {
		for (j = 0; j < xres; j++) {
			draw_point(j, i, BAK_COL);
		}
	}
}

/*将圆画成背景色*/
void clear_circle(struct circle *c)          //
{
	int x0 = c->x0;
	int y0 = c->y0;
	int r = c->r;
	int i, j;

	for (i = y0 - r; i < y0 + r; i++) {
		for (j = x0 - r; j < x0 + r; j++) {
		if ((j-x0)*(j-x0) + (i-y0)*(i-y0) <= r*r) {
			draw_point(j, i, BAK_COL);
		}
		}
	}
}

/*根据圆的运行轨迹改变圆心的坐标*/
void change_pos(struct circle *c)
{
	int index = c->action;	/*0~7*/
	struct position pos = actions[index];
	int x,y;
	int r = c->r;

	if (pos.x == -1) {
		if (c->x0 == (r - 1)) {
			c->action = rand()%8;
			change_pos(c);
			return;
		} else if ((c->x0 - r) < STEP) {
			x = r - 1;
		} else {
			x = c->x0 - STEP;
		}
	} else if (pos.x == 1) {
		if ((c->x0 + r) == (xres - 1)) {
			c->action = rand()%8;
			change_pos(c);
			return;
		} else if ((xres-1-(c->x0 + r)) < STEP) {
			x = xres-1-r;
		} else {
			x = c->x0 + STEP;
		}
	} else {
		x = c->x0;
	}


	if (pos.y == -1) {
		if (c->y0 == r) {
			c->action = rand()%8;
			change_pos(c);
			return;
		} else if ((c->y0 - STEP) < r+1) {
			y = r;
		} else {
			y = c->y0 - STEP;
		}
	} else if (pos.y == 1) {
		if ((c->y0 + r) == (yres - 1)) {
			c->action = rand()%8;
			change_pos(c);
			return;
		} else if ((yres-1-(c->y0 + r)) < STEP) {
			y = yres-1-r;
		} else {
			y = c->y0 + STEP;
		}
	} else {
		y = c->y0;
	}

	c->x0 = x;
	c->y0 = y;
	c->col += 1;
	c->cnt++;
	if (c->cnt > 10) {
		c->col = rand()%0x1000000;
		c->cnt = 0;
	}
}

/*移动圆*/
void move_circle(struct circle *c)
{
	//clear_circle(c);
	change_pos(c);
	draw_circle(c);
}

