#include<bits/stdc++.h>
using namespace std;
int P,Q,N;
void menu()
{
    printf("********* ��ӭʹ�ù�Ʊ����ϵͳ *********\n");
    printf("****************************************\n");
    printf("*      1.��ʼ             0.�˳�       *\n");
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
	printf("��ӭʹ�ù�Ʊ���׾�����������֧��ϵͳ\n");
	printf("�����뽻���ܽ��:\n");
	scanf("%d",&P);
	printf("������ÿ�ɵ��ۼ�\n");
	scanf("%f",&Q);
	printf("�����뽻�׵Ĺ���\n");
	scanf("%d",&N);
	float b_cost;
	float add_cost;
	//P :�����ܽ��   Q��ÿ�ɵ��ۼ�   N�����׵Ĺ���
    //����������
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
	//����������
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
	printf("����Ҫ֧����������Ϊ��");
	printf("%.2f Ԫ\n",add_cost+b_cost);
	
}
