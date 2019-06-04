#include<stdio.h>

#define bool int//自定义bool类型
#define true 1
#define false 0

bool IsLeap(int year);
int GetWeek(int year,int month);
int  main()
{
    int y,m,week,i;
    printf("输入yyyy-mm：");
    scanf("%d%d",&y,&m);
    printf("      %d年%d月\n",y,m);
    printf("=====================\n");
    printf(" 一 二 三 四 五 六 日\n");
    week = GetWeek(y,m);
    if(week == 0)
        week = 7;									//若week == 0，将其视作7，以便留下足够的空格

    for (i = 1;i < week; i++)
    {
        printf("   ");								//三个字符为一个单位，保证第一行与周数对应
    }
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//以数组方式统计每个月的天数
    if (IsLeap(y) == true)							//若为闰年，将2月份的天数修改为29
        month[1] = 29;
    for(i=1;i<=month[m-1];i++)						//利用for循环，依次输出日数，并且若加上通过计算week+i-1%7来判断是否该换行
    {
        printf("%3d",i);
        if((i+week-1) % 7 == 0)
            printf("\n");
    }
	printf("\n=====================\n");
}

bool IsLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//判断是否为闰年的条件
        return true;
    else
        return false;
}

int GetWeek(int year,int month)
{
    int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};			//以数组记录每个月的天数
    int day=0,week,i;
    switch (month)
    {
        case 1:
            day = 1;
            break;
        case 2:
            day = m[0] + 1;
            break;
        case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
            if (IsLeap(year) == true)
                m[1] = 29;
            for (i=0;i<month-1;i++)
            {
                day = day + m[i];
            }
            day = day + 1;
            break;

    }
    week = ((year-1) + (year-1)/4 - (year-1)/100 + (year-1)/400 + day) % 7;
    return week;
}

