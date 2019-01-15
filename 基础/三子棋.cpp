#include<bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 3
int row;
int col;
char arr[ROW][COL]={0};
void menu()
{
	printf("     1.开始游戏     \n");
	printf("     2.退出游戏     \n");

}
void Init(char arr[ROW][COL])
{
	memset(arr,' ',ROW*COL*sizeof(arr));
}
void Print(char arr[ROW][COL])//初始化并打印棋盘
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%c",arr[i][j]);
			//cout<<"00000"<<endl;
			if(j<COL-1)
				printf("  |");
		}
		printf("\n");
		if(i<ROW-1)
		{
			for(j=0;j<COL;j++)
			{
				printf("---");
				if(j<COL-1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char arr[ROW][COL])
{
	cout<<"玩家落子"<<endl;
	int row=0;int col=0;
	
	while(1)
	{
	    scanf("%d %d",&row,&col);
		if(row<0||row>=ROW||col<0||col>=COL)
	{
		//用户输入的坐标非法
		printf("坐标非法！请重新输入");
	}
	else if(arr[row][col]=='0')
	{
		printf("棋子存在，请重新输入");

	}
	else
		arr[row][col]='x';
		break;
	}
	
		
//Print(arr);
}

void CumputerMove(char arr[ROW][COL])//电脑落子 0
{
	printf("电脑落子！\n");
	while(1)
	{
	int row=rand()%ROW;
	int col=rand()%COL;
	//cout<<"1"<<arr[row][col]<<"1"<<endl;
	if(arr[row][col]==' ')
	{
		//cout<<"12345678"<<endl;
		arr[row][col]='0';
		break;
	}
	}
	//cout<<"asdasd"<<endl;
	//Print(arr);
	
}
int is_full(char arr[ROW][COL])
{
	int i=0;
	int j=0;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(arr[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char check(char arr[ROW][COL])
{
	int i = 0;
	for(i=0;i<ROW;i++)
	{
		if(arr[i][0] == arr[i][1]&&arr[i][1]==arr[i][2]&&arr[i][0]!=' ')
		{
			return arr[i][0];
		}
	}
	for(i=0;i<COL;i++)
	{
		if(arr[0][i] == arr[1][i]&&arr[1][i]==arr[2][i]&&arr[0][i]!=' ')
		{
			return arr[0][i];
		}
	}

		if(arr[0][0] == arr[1][1]&&arr[1][1]==arr[2][2]&&arr[0][0]!=' ')
		{
			return arr[0][0];
		}
		if(arr[0][2] == arr[1][1]&&arr[1][1]==arr[2][0]&&arr[0][2]!=' ')
		{
			return arr[0][2];
		}
		if(is_full(arr))
		{
			return 'q';//如果满了，输出q
		}
		return ' ';
	
}
void game()
{
	char arr[ROW][COL];
	int x=0;
	int y=0;
	char ret = 0;
	Init(arr);//先初始化一下棋盘，
	Print(arr);//打印棋盘
	printf("\n");
	while(1)
	{
		PlayerMove(arr);//玩家走棋
		if ((ret = check(arr)) != ' ')//里面条件成立说明谁赢了或平局，那就跳出循环判断
            break;
        CumputerMove(arr);//电脑下棋
        if ((ret = check(arr)) != ' ')//里面条件成立说明谁赢了或平局，那就跳出循环判断
            break;
        Print(arr);//打印出这次你和电脑的走位
        printf("\n");
    }
    if (ret == 'x')//三个x说明玩家赢
    {
        printf("玩家赢\n");
    }
    if (ret == '0')//三个0说明电脑赢
    {
        printf("电脑赢\n");
    }
    if (ret == 'q')//都没赢说明平局
    {
        printf("平局\n");
    }
    Print(arr);//打印出游戏结果
}
int main()
{
	srand((int)time(0));
	int c=0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&c);
		cout<<"1111"<<endl;
		switch(c)
		{
			case 1: game();
				break;
			case 0: exit(1);
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}
	}while(1);
	system("pause");
	return 0;
//	Print();

//	PlayerMove();
//	char winner = CheckWinner();
//	if(winner != ' '){
//		printf("游戏结束，赢家是：%c\n",winner);
//		return 0;
//	}
//	ComputerMove();
//x表示玩家的字符，o表示电脑的字符
//	玩家输入坐标下棋
//		判定游戏是否结束
//		  1，电脑获胜
//        2，玩家获胜
//        3，和棋
//        4，游戏继续
//	电脑随机落子（随机数） 不能和已有坐标重复
//    	判定游戏是否结束
//        1，电脑获胜
//        2，玩家获胜
//        3，和棋
//        4，游戏继续
	

}
