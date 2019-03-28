#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s1 = 'G';
	char s2 = 'P';
	char s3 = 'L';
	char s4 = 'T';
	int m1=0,m2=0,m3=0,m4=0;
	string a;
	cin>>a;
	int len =a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]=='G'||a[i]=='g')
		{
			m1++;
		}
		if(a[i]=='P'||a[i]=='p')
		{
			m2++;
		}
		if(a[i]=='l'||a[i]=='L')
		{
			m3++;
		}
		if(a[i]=='T'||a[i]=='t')
		{
			m4++;
		}
		
	}
//	cout<<m1<<"  "<<m2<<"  "<<m3<<" "<<m4<<endl;
	while(m2||m1||m3||m4)
	{
		if(m1>0)
		{
			m1--;
			cout<<s1;
		}
		if(m2>0)
		{
			m2--;
			cout<<s2;
		}
		if(m3>0)
		{
			m3--;
			cout<<s3;
		}
		if(m4>0)
		{
			m4--;
			cout<<s4;
		}
	}
	cout<<endl;
	return 0;
}
