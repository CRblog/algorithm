#include<stdio.h>

#define bool int//�Զ���bool����
#define true 1
#define false 0

bool IsLeap(int year);
int GetWeek(int year,int month);
int  main()
{
    int y,m,week,i;
    printf("����yyyy-mm��");
    scanf("%d%d",&y,&m);
    printf("      %d��%d��\n",y,m);
    printf("=====================\n");
    printf(" һ �� �� �� �� �� ��\n");
    week = GetWeek(y,m);
    if(week == 0)
        week = 7;									//��week == 0����������7���Ա������㹻�Ŀո�

    for (i = 1;i < week; i++)
    {
        printf("   ");								//�����ַ�Ϊһ����λ����֤��һ����������Ӧ
    }
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//�����鷽ʽͳ��ÿ���µ�����
    if (IsLeap(y) == true)							//��Ϊ���꣬��2�·ݵ������޸�Ϊ29
        month[1] = 29;
    for(i=1;i<=month[m-1];i++)						//����forѭ���������������������������ͨ������week+i-1%7���ж��Ƿ�û���
    {
        printf("%3d",i);
        if((i+week-1) % 7 == 0)
            printf("\n");
    }
	printf("\n=====================\n");
}

bool IsLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�ж��Ƿ�Ϊ���������
        return true;
    else
        return false;
}

int GetWeek(int year,int month)
{
    int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};			//�������¼ÿ���µ�����
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

