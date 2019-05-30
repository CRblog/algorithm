#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    string str;
    while(cin>>str)
    {
    	int num_count = 0;
    	int abc_count = 0;
    	int ABC_count = 0;
    	int se_length = 0;
    	int str_count = 0;
    	int score = 0;
	
    se_length = str.size();
	for(int i=0;i<se_length;i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            num_count++;
        }
        else if(str[i]>='a'&&str[i]<='z')
        {
            abc_count++;
        }
        else if(str[i]>='A'&&str[i]<='Z')
        {
            ABC_count++;
        }
        else
            str_count++;
    }
    if(se_length<=4)
    {
        score+=5;
        //cout<<"长度小于4个+5分"<<endl;
    }
    if(se_length>=5&&se_length<=7)
    {
        score+=10;
        //cout<<"长度5-7个，+10分"<<endl;
    }
    if(se_length>=8)
    {
        score+=25;
        //cout<<"长度大于8个+25分"<<endl;
    }
    if(abc_count==0&&ABC_count==0)
    {
        score+=0;
        //cout<<"大小写都没有+0分"<<endl;
    }
    if((abc_count==0&&ABC_count!=0)||(abc_count!=0&&ABC_count==0))
    {
        score+=10;
        //cout<<"只有大写或者只有小写+10分"<<endl;
    }
    if(abc_count!=0&&ABC_count!=0)
    {
        score+=20;
        //cout<<"大小写都有+20分"<<endl;
    }
    if(num_count==0)
    {
        score+=0;
        //cout<<"没有数字+10分"<<endl;
    }
    if(num_count==1)
    {
        score+=10;
        //cout<<"有一个数字+10分"<<endl;
    }
    if(num_count>1)
    {
        score+=20;
        //cout<<"有好多数字+20分"<<endl;
    }
    if(str_count==0)
    {
        score+=0;
        //cout<<"没有字符+0分"<<endl;
    }
    if(str_count==1)
    {
        score+=10;
        //cout<<"有1个字符+10分"<<endl;
    }
    if(str_count>1)
    {
        score+=25;
        //cout<<"有多个字符+25分"<<endl;
    }
    if(((abc_count!=0&&ABC_count==0)||(ABC_count!=0&&abc_count==0))&&(num_count!=0)&&(str_count==0))
    {
        score+=2;
        //cout<<"有大写或者小写字母，有数字，没有字符+2分"<<endl;
    }
    if(((abc_count!=0&&ABC_count==0)||(ABC_count!=0&&abc_count==0))&&(num_count!=0)&&(str_count!=0))
    {
        score+=3;
	//	cout<<"有大写或者小写字母，有数字，有字符+3分"<<endl;
    }
    if((abc_count!=0)&&(ABC_count!=0)&&(num_count!=0)&&(str_count!=0))
    {
        score+=5;
       // cout<<"有大写和小写字母，有数字，没有字符+5分"<<endl;
    }

    if(score>=90)
    {
    	cout<<"VERY_SECURE"<<endl;
	}
	else if(score>=80)
	{
		cout<<"SECURE"<<endl;
	}
	else if(score>=70)
	{
		cout<<"VERY_STRONG"<<endl;
	}
	else if(score>=60)
	{
		cout<<"STRONG"<<endl;
	}
	else if(score>=50)
	{
		cout<<"AVERAGE"<<endl;
	}
	else if(score>25)
	{
		cout<<"WEAK"<<endl;
	}
	else
		cout<<"VERY_WEAK"<<endl;
//	switch(score/10)
//	{
//
//		   case 9:cout<<"VERY_SECURE"<<endl;break;
//           case 8:cout<<"SECURE"<<endl;break;
//           case 7:cout<<"VERY_STRONG"<<endl;break;
//           case 6:cout<<"STRONG"<<endl;break;
//           case 5:cout<<"AVERAGE"<<endl;break;
//           default:
//           {
//               if(score>=25)cout<<"WEAK"<<endl;
//               else cout<<"VERY_WEAK"<<endl;
//           }
//	}
}
    return 0;
}
