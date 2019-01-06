#include <bits/stdc++.h>
using namespace std;

int mypow[32];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mypow[0] = 1, mypow[1] = 2;
    for(int i = 2; i<32; i++)
        mypow[i] = mypow[i-1] * 2;
    int T;
    cin >> T;
    while(T--)
    {
        map<int, int> F;
        int n;
        cin >> n;
        int Max = -1;
        for(int i = 0; i<n; i++)
        {
            int tmp;
            cin >> tmp;
            for(int j = 0; j < 32; j++)
            {
                if(mypow[j] == tmp)
                {
                    F[j]++;
                    break;
                }
                else if(mypow[j] > tmp)
                {
                    F[j-1]++;
                    break;
                }
            }
        }
        for(int i = 0; i<32; i++)
        {
            Max = max(Max, F[i]);
        }
        cout<<Max<<endl;
    }
    return 0;
}


