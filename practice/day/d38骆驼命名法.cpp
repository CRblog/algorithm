#include<bits/stdc++.h>
using namespace std;
int main()
{
    string name;
   
    while(getline(cin,name))
    {
    	string res;
        for(int i=0;i<name.length();++i)
        {
            if(name[i]=='_')
            {
                name[i+1]-=32;
            }
            else
            {
            	res+=name[i];
			}
                
        }
        cout<<res<<endl;
    }
    return 0;
}
