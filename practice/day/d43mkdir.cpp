#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		vector<string> str(n);
		vector<bool> flag(n,true);
		for(int i=0;i<n;++i)
		{
			cin>>str[i];
		}
		sort(str.begin(),str.end());
		for(int i=0;i<str.size()-1;++i)
		{
			if(str[i]==str[i+1])
			{
				flag[i] = false;
			}
			else if (str[i].size() < str[i + 1].size() && str[i] == str[i + 1].substr(0, str[i].size()) && str[i + 1][str[i].size()] == '/')
                flag[i] = false;
		}
		for(int i=0;i<str.size();++i)
		{
			if(flag[i])
			{
				cout<<"mkdir -p "<<str[i]<<endl;
			}

		} cout<<endl;
	}
	return 0;
}

