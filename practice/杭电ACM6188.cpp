#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
int s[maxn];

int main(){
    int n, a;
    while( ~scanf("%d",&n) ){
        memset(s, 0, sizeof(s));
        int mmax = -1;
        for( int i = 0; i < n; i++ ){
            scanf("%d",&a);
            mmax = max(mmax, a);//maxҪ��ͷ�ļ�algorithm
			//�����������ֵ����ֵ
            s[a]++;   //aԪ�صĸ���++
        }
        int ans = 0;
        for( int i = 1; i <= mmax; i++ ){//�����mmax������
            if( s[i] >= 2 ){
                ans += s[i] / 2;
                s[i] %= 2;
            }
            if( s[i] == 1 && s[i+1] % 2 != 0 && s[i+2] ){
                ans++;
                s[i]--, s[i+1]--, s[i+2]--;//ȡ��˳�ӣ����ݸ���1
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
