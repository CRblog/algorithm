#include<bits/stdc++.h>
#include<string>
using namespace std;
int dia_root(string s)
{
    int sum = 0;
    for(int i = 0;i<s.size();++i)
    {
		sum += s[i]-'0';
	}
	s = to_string(sum);
	while(s.size()>1)
    {
        sum = 0;
        for(int j = 0;j<s.size();++j)
        {
            sum += s[j]-'0';
        }
        s = to_string(sum);
    }
    return sum;
}
int main()
{
    string str1;
    while(cin>>str1)
    {
		cout<<dia_root(str1)<<endl;
	}
    return 0;
}
