#include<bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 3
int row;
int col;
char arr[ROW][COL]={0};
void menu()
{
	printf("     1.��ʼ��Ϸ     \n");
	printf("     2.�˳���Ϸ     \n");

}
void Init(char arr[ROW][COL])
{
	memset(arr,' ',ROW*COL*sizeof(arr));
}
void Print(char arr[ROW][COL])//��ʼ������ӡ����
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
	cout<<"�������"<<endl;
	int row=0;int col=0;
	
	while(1)
	{
	    scanf("%d %d",&row,&col);
		if(row<0||row>=ROW||col<0||col>=COL)
	{
		//�û����������Ƿ�
		printf("����Ƿ�������������");
	}
	else if(arr[row][col]=='0')
	{
		printf("���Ӵ��ڣ�����������");

	}
	else
		arr[row][col]='x';
		break;
	}
	
		
//Print(arr);
}

void CumputerMove(char arr[ROW][COL])//�������� 0
{
	printf("�������ӣ�\n");
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
			return 'q';//������ˣ����q
		}
		return ' ';
	
}
void game()
{
	char arr[ROW][COL];
	int x=0;
	int y=0;
	char ret = 0;
	Init(arr);//�ȳ�ʼ��һ�����̣�
	Print(arr);//��ӡ����
	printf("\n");
	while(1)
	{
		PlayerMove(arr);//�������
		if ((ret = check(arr)) != ' ')//������������˵��˭Ӯ�˻�ƽ�֣��Ǿ�����ѭ���ж�
            break;
        CumputerMove(arr);//��������
        if ((ret = check(arr)) != ' ')//������������˵��˭Ӯ�˻�ƽ�֣��Ǿ�����ѭ���ж�
            break;
        Print(arr);//��ӡ�������͵��Ե���λ
        printf("\n");
    }
    if (ret == 'x')//����x˵�����Ӯ
    {
        printf("���Ӯ\n");
    }
    if (ret == '0')//����0˵������Ӯ
    {
        printf("����Ӯ\n");
    }
    if (ret == 'q')//��ûӮ˵��ƽ��
    {
        printf("ƽ��\n");
    }
    Print(arr);//��ӡ����Ϸ���
}
int main()
{
	srand((int)time(0));
	int c=0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d",&c);
		cout<<"1111"<<endl;
		switch(c)
		{
			case 1: game();
				break;
			case 0: exit(1);
				break;
			default:
				printf("�����������������\n");
				break;
		}
	}while(1);
	system("pause");
	return 0;
//	Print();

//	PlayerMove();
//	char winner = CheckWinner();
//	if(winner != ' '){
//		printf("��Ϸ������Ӯ���ǣ�%c\n",winner);
//		return 0;
//	}
//	ComputerMove();
//x��ʾ��ҵ��ַ���o��ʾ���Ե��ַ�
//	���������������
//		�ж���Ϸ�Ƿ����
//		  1�����Ի�ʤ
//        2����һ�ʤ
//        3������
//        4����Ϸ����
//	����������ӣ�������� ���ܺ����������ظ�
//    	�ж���Ϸ�Ƿ����
//        1�����Ի�ʤ
//        2����һ�ʤ
//        3������
//        4����Ϸ����
	

}
