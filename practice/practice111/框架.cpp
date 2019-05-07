#include <bits/stdc++.h>//C++万能头
#include<windows.h>//控制台编程主要头文件
#include<conio.h>//getch()函数
#include<stdlib.h>//system()函数
using namespace std;
void pos(int x,int y);//确定光标位置
void blue_border();//蓝色字体
void white_back();//还原亮白色字体
void cyan_choose();//青色字体
void on_Select();//被选中时的样式
void onChoose(int x,int y);//确定所选中的位置
void star();//初始化界面
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出句柄
int main()
{
    system("color 7F");//设置控制台界面背景颜色和前景颜色
    system("mode con cols=100 lines=40");//初始化缓冲区大小
    SetConsoleTitle("StathamJ的程序");//设置控制台窗口标题
    cyan_choose();
    cout<<"提示：    1.使用w,a,s,d进行光标控制\n          2.按下空格确定选项       "<<endl;

    blue_border();
    pos(5,5);
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";//上边框
    pos(5,25);
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";//下边框
    for(int i=5,j=6; j<25; j++) //左边框
    {
        pos(i,j);
        cout<<"*";
    }
    for(int i=85,j=6; j<25; j++) //右边框
    {
        pos(i,j);
        cout<<"*";
    }

    cyan_choose();
    pos(65,10);
    cout<<"2. 开始 ";
    pos(25,20);
    cout<<"3. 继续 ";
    pos(65,20);
    cout<<"4. 退出 ";
    on_Select();
    pos(25,10);
    cout<<"1. 开始 ";

//wsad控制光标对进行自由选择
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
//防止超出范围
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
    white_back();//还原默认字体
    CloseHandle(hOut);//关闭标准输出句柄
    return 0;
}
//设置光标位置
void pos(int x,int y)
{
    COORD posPoint = {x,y}; //设置坐标
    SetConsoleCursorPosition(hOut,posPoint);
}
void blue_border()
{
    WORD blue=FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN;//设置字体颜色、背景颜色
    SetConsoleTextAttribute(hOut,blue);//字体样式
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
        cout<<"1. 开始 ";
    }
    else if(x==25&&y==20)
    {
        on_Select();
        cout<<"3. 继续 ";
    }
    else if(x==65&&y==10)
    {
        on_Select();
        cout<<"2. 选择 ";
    }
    else if(x==65&&y==20)
    {
        on_Select();
        cout<<"4. 退出 ";
    }
}
void star()
{
    cyan_choose();
    pos(25,10);
    cout<<"1. 开始1111111111 ";
    pos(65,10);
    cout<<"2. 选择 ";
    pos(25,20);
    cout<<"3. 继续 ";
    pos(65,20);
    cout<<"4. 退出 ";
}

