#include <bits/stdc++.h>//C++����ͷ
#include<windows.h>//����̨�����Ҫͷ�ļ�
#include<conio.h>//getch()����
#include<stdlib.h>//system()����
using namespace std;
void pos(int x,int y);//ȷ�����λ��
void blue_border();//��ɫ����
void white_back();//��ԭ����ɫ����
void cyan_choose();//��ɫ����
void on_Select();//��ѡ��ʱ����ʽ
void onChoose(int x,int y);//ȷ����ѡ�е�λ��
void star();//��ʼ������
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼������
int main()
{
    system("color 7F");//���ÿ���̨���汳����ɫ��ǰ����ɫ
    system("mode con cols=100 lines=40");//��ʼ����������С
    SetConsoleTitle("StathamJ�ĳ���");//���ÿ���̨���ڱ���
    cyan_choose();
    cout<<"��ʾ��    1.ʹ��w,a,s,d���й�����\n          2.���¿ո�ȷ��ѡ��       "<<endl;

    blue_border();
    pos(5,5);
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//�ϱ߿�
    pos(5,25);
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//�±߿�
    for(int i=5,j=6; j<25; j++) //��߿�
    {
        pos(i,j);
        cout<<"*";
    }
    for(int i=85,j=6; j<25; j++) //�ұ߿�
    {
        pos(i,j);
        cout<<"*";
    }

    cyan_choose();
    pos(65,10);
    cout<<"2. ��ʼ ";
    pos(25,20);
    cout<<"3. ���� ";
    pos(65,20);
    cout<<"4. �˳� ";
    on_Select();
    pos(25,10);
    cout<<"1. ��ʼ ";

//wsad���ƹ��Խ�������ѡ��
    int x=25,y=10;
    char sel;
    sel=getch();
    while(sel!=' ')
    {
        star();
        switch(sel)
        {
        case 'w':
            y=y-10;
            break;
        case 's':
            y=y+10;
            break;
        case 'a':
            x=x-40;
            break;
        case 'd':
            x=x+40;
            break;
        }
//��ֹ������Χ
        if(x>=65)
        {
            x=65;
        }
        if(y>=20)
        {
            y=20;
        }
        if(x<=25)
        {
            x=25;
        }
        if(y<=10)
        {
            y=10;
        }
        pos(x,y);
        onChoose(x,y);
        sel=getch();
    }
    pos(0,30);
    white_back();//��ԭĬ������
    CloseHandle(hOut);//�رձ�׼������
    return 0;
}
//���ù��λ��
void pos(int x,int y)
{
    COORD posPoint = {x,y}; //��������
    SetConsoleCursorPosition(hOut,posPoint);
}
void blue_border()
{
    WORD blue=FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN;//����������ɫ��������ɫ
    SetConsoleTextAttribute(hOut,blue);//������ʽ
}
void white_back()
{
    WORD white=FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(hOut,white);
}
void cyan_choose()
{
    WORD cyan=FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE;
    SetConsoleTextAttribute(hOut,cyan);
}
void on_Select()
{
    WORD select=FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_RED;
    SetConsoleTextAttribute(hOut,select);
}
void onChoose(int x,int y)
{
    if(x==25&&y==10)
    {
        on_Select();
        cout<<"1. ��ʼ ";
    }
    else if(x==25&&y==20)
    {
        on_Select();
        cout<<"3. ���� ";
    }
    else if(x==65&&y==10)
    {
        on_Select();
        cout<<"2. ѡ�� ";
    }
    else if(x==65&&y==20)
    {
        on_Select();
        cout<<"4. �˳� ";
    }
}
void star()
{
    cyan_choose();
    pos(25,10);
    cout<<"1. ��ʼ1111111111 ";
    pos(65,10);
    cout<<"2. ѡ�� ";
    pos(25,20);
    cout<<"3. ���� ";
    pos(65,20);
    cout<<"4. �˳� ";
}

