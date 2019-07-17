#include<bits/stdc++.h>
using  namespace std;

string reverse(string s,int start,int end)
{
    string tmp;
    for(int i = end;i>=start;--i)
    {
        tmp+=s[i];
    }
    return tmp;
}
int main()
{
    string str1;
    while(getline(cin,str1))
    {
        str1 = reverse(str1,0,str1.length()-1);
        //cout<<str1<<endl;
        string tp;
		int start = 0;
        int end = 0;
        int flag = 0;
        for(int i=0;i<str1.length();++i)
        {

			if(str1[i]>='a' && str1[i]<='z' || str1[i]>='A' && str1[i]<='Z')
			{
				end++;
				flag = 0;
			}
			
			else
            {
                tp += reverse(str1,start,end-1);
				if(flag==0)
				{
					tp+=' ';
					flag = 1;
				}
				
                start = i+1;
                end = i+1;
            }
			if(i==str1.length()-1)
			{
				tp+=reverse(str1,start,i);
			}
        }
		cout<<tp<<endl;
    }
    return 0;
}
