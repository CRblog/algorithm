#include <bits/stdc++.h>
using namespace std;

#define long long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAX_N 200010

int main()
{
     int n;
    while(cin >> n)
    {
	    int ans_1 = 1, ans_2 = 0, ans_3 = 0; // �ֱ���� Ϊ��һ�������ĸ���  �ڶ��������ĸ��� �Լ� >= 3�������ĸ���
    	int ans = 0;
          for(int i = 1; i < n; i++)
            {
            //int tmp = ans_3;
            ans_3 += ans_2;
            ans_2 = ans_1;
            ans_1 = ans_3;
            }
            cout<<ans_1+ans_2+ans_3<<endl;
    }

    return 0;
}
