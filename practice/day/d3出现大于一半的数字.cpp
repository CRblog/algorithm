#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1;
    while(cin>>s1)
    {
        int count = 0;
        int maxn = 0;
        string ans;
        for(int i=0;i<s1.size();i++)
        {
            count = 0;
            string tmp;
            while(s1[i]>='0'&&s1[i]<='9')
            {
				tmp+=s1[i];
                count++;
                i++;
                
            }
			if(tmp.size()>=ans.size())
			{
				ans = tmp;
			}
        }
        cout<<ans<<endl;

    }
    return 0;
}
