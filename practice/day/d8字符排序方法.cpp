#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int n;
	cin>>n;
        int flag1 = 1;
        int flag2 = 1;
        string str[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
			if(i>0)
			{
				if(str[i-1]>str[i])   //��ط��ַ�������ֱ�ӱȽϵģ��տ�ʼֻ�Ƚ��˵�һ����ĸ��
            	{
              	  	flag1 = 0;
           		}
            	if(str[i-1].size()>str[i].size())
            	{
            	    flag2 = 0;
            	}
			}
        }
        //cout<<flag1<<flag2<<endl;
		if(flag1==0&&flag2==1)   //���ȷ���Ҫ��
        {
            cout<<"lengths"<<endl;
        }
		else if(flag1==1&&flag2==0)   //�ֵ������Ҫ��
        {
            cout<<"lexicographically"<<endl;
        }
		else if(flag1&&flag2)    //������Ҫ��
        {
            cout<<"both"<<endl;
        }
        else
            cout<<"none"<<endl;
    return 0;
}
