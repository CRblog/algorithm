#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int n;
	string str1 = "22233344455566677778889999";   //�Ź����е���Ӧλ
	while(cin>>n)
	{
		set<string> st;
		int cnt;
		for(int i=0;i<n;++i)
		{
			cnt = 0;
			string res;
			cin>>s;
			for(int j=0;j<s.length();j++)   //������ַ���ת��Ϊ���ַ����ַ����У�ת�����������ͼ��� - ��
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
				else if(s[j]>='0'&&s[j]<='9')   //��������־Ͳ���ת����ֱ�Ӽӵ��ַ����У�count������3���ͼ��� -
				{
					res+=s[j];
					cnt++;
					if(cnt == 3)
					{
						res += "-";
					}
				}
				
			}
			st.insert(res);   //set�����������Ҳ������ظ�Ԫ�ص�
		}
		for(set<string>::iterator it = st.begin();it!=st.end();++it)
			{
				cout<<*it<<endl;
			}  //��ͷ��β���
			cout<<endl;
	}
	return 0;
}
