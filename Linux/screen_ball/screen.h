#ifndef MILLET_SCREEN_H_
#define MILLET_SCREEN_H_

struct circle {
	int x0;
	int y0;
	int r;
	int col;
	int action; //0~7, 代表运行轨迹中的一种
	int cnt;
};

extern void draw_circle(struct circle *c);        //画圆
extern void draw_point(int x, int y, int col);    //画点
extern void circle_init(struct circle *c);        //圆的初始化
extern void move_circle(struct circle *c);        //圆的移动
extern void clear_circle(struct circle *c);       //清除圆
extern void screen_set_bak(void);                 //设置背景颜色

#endif

