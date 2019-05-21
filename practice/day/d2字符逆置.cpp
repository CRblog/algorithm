#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	stack<string> s;
	while(cin>>str)
	{
		s.push(str);
		if(*(str.rbegin())=='.')
			break;
	}
	cout<<s.top();
	s.pop();
	while(!s.empty())
	{
		cout<<" "<<s.top();
		s.pop();
	}
	cout<<endl;
}
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int n = 0;
//	int p = 0;
//	string s[str.size()+1];
//	for(int i=0;i<str.size();i++)
//	{
//		if((str[i]==' ')||i==str.size()-1)
//		{
//			for(int j=i-1;j>=n;j--)
//			{
//				s[p]= str[j];
//				cout<<s[p]<<endl;
//			}
//			p++;
//			//s[p]=' ';
//			//cout<<"--"<<p<<"--"<<s[p]<<endl;
//			n = i+1;
//			p++;
//		}
//	}
////	int w = 0;
////	int f = 0;
////	for(int i=0;i<str.size();i++)
////	{
////		if((str[i]==' ')||i==str.size()-1)
////		{
////			for(int j=w;j<=w;j--)
////			{
////				s[f][j]= str[j];
////				cout<<s[f][j]<<endl;
////			}
////			w = i+1;
////			f++;
////		}
////	}
//	return 0;
//}


