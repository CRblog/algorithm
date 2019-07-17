#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int n;
	string str1 = "22233344455566677778889999";   //九宫格中的相应位
	while(cin>>n)
	{
		set<string> st;
		int cnt;
		for(int i=0;i<n;++i)
		{
			cnt = 0;
			string res;
			cin>>s;
			for(int j=0;j<s.length();j++)   //如果是字符就转化为数字放在字符串中（转化过第三个就加上 - ）
			{
				if(s[j]>='A'&&s[j]<='Z')
				{
					res += str1[s[j]-'A'];
					cnt++;
					if(cnt == 3)
					{
						res+="-";
					}
				}
				else if(s[j]>='0'&&s[j]<='9')   //如果是数字就不用转化，直接加到字符串中，count计数到3个就加上 -
				{
					res+=s[j];
					cnt++;
					if(cnt == 3)
					{
						res += "-";
					}
				}
				
			}
			st.insert(res);   //set里是自排序并且不存在重复元素的
		}
		for(set<string>::iterator it = st.begin();it!=st.end();++it)
			{
				cout<<*it<<endl;
			}  //从头到尾输出
			cout<<endl;
	}
	return 0;
}
