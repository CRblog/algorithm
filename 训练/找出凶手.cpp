#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	for(int s='a';s<='d';s++)
	{
		if((s!='a')+(s=='c')+(s=='d')+(s!='d')==3)
			cout<<(char)s<<"ÊÇÐ×ÊÖ"<<endl;
	}
	return 0;
}
