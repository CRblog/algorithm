#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    
    while(getline(cin,str))
    {
    	string num;
        for(int i=0;i<str.size();++i)
        {
            if((str[i]-'0')<=9&&(str[i]-'0')>=0)
            {
                num+=str[i];
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
