#ifndef MILLET_SCREEN_H_
#define MILLET_SCREEN_H_

struct circle {
	int x0;
	int y0;
	int r;
	int col;
	int action; //0~7, �������й켣�е�һ��
	int cnt;
};

extern void draw_circle(struct circle *c);        //��Բ
extern void draw_point(int x, int y, int col);    //����
extern void circle_init(struct circle *c);        //Բ�ĳ�ʼ��
extern void move_circle(struct circle *c);        //Բ���ƶ�
extern void clear_circle(struct circle *c);       //���Բ
extern void screen_set_bak(void);                 //���ñ�����ɫ

#endif

