#include<bits/stdc++.h>
using namespace std;
int P,Q,N;
void menu()
{
    printf("********* 欢迎使用股票交易系统 *********\n");
    printf("****************************************\n");
    printf("*      1.开始             0.退出       *\n");
    printf("****************************************\n");
}

    
int main()
{
	int n=0;
	menu();
	scanf("%d",n);
	if(n==1)
	{
		start;
	}
	printf("欢迎使用股票交易经纪人手续费支付系统\n");
	printf("请输入交易总金额:\n");
	scanf("%d",&P);
	printf("请输入每股的售价\n");
	scanf("%f",&Q);
	printf("请输入交易的股数\n");
	scanf("%d",&N);
	float b_cost;
	float add_cost;
	//P :交易总金额   Q：每股的售价   N：交易的股数
    //基本手续费
	if (P<1000)
	{
		b_cost = 0.084*P;
	}  
	else if (P>=1000&&P<10000)
	{
		b_cost = 0.05*P;
	}
	else if (P>=10000)
	{
		b_cost = 0.04*P+134;
	}
	//cout<<b_cost<<endl;
	//附加手续费
	if(Q<14)
	{
		if(N%100==0)
		{
			add_cost = b_cost*0.05;
		}
		else
			add_cost = b_cost*0.09;
	}
	else if(Q>=14&&Q<25)
	{
		if(N%100==0)
		{
			add_cost = b_cost*0.02;
		}
		else
			add_cost = b_cost*0.06;
	}
	else if(Q>=25)
	{
		if(N%100==0)
		{
			add_cost = b_cost*0.01;
		}
		else
			add_cost = b_cost*0.04;
	}
	//cout<<add_cost<<endl;
	float cost;
	cost =
	printf("您需要支付的手续费为：");
	printf("%.2f 元\n",add_cost+b_cost);
	
}
