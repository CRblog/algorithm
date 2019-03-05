#include<bits/stdc++.h>
using namespace std;
//A:  B第二，A第三
//B： A第二，E第四
//C： C第一，D第二
//D： C第五，D第三
//E： E第四，A第一
int main()
{
	for(int a=1;a<=5;a++){
		for(int b=1;b<=5;b++){
			for(int c=1;c<=5;c++){
				for(int d=1;d<=5;d++){
					for(int e=1;e<=5;e++){
						if(((b==2&&a!=3)||(b!=2&&a==3))==1)
						{
							if(((a==2&&e!=4)||(a!=2&&e==4))==1)
							{
								if(((c==1&&d!=2)||(c!=1&&d==2))==1)
								{
									if(((c==5&&d!=3)||(c!=5&&a==3))==1)
									{
										if(((e==4&&a!=1)||(e!=4&&a==1))==1)
										{
											if(a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&
											c!=d&&c!=e&&d!=e)
											cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
										}
									}
								}
							}
						}
						
					}
				}
			}
		}
	}
	return 0;
}
