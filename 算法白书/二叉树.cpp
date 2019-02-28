#include<bits/stdc++.h>
using namespace std;

const int maxd = 20;
int s[1<<maxd];
int main(){
	int D,I;
	while(scanf("%d%d",&D,&I)==2) {
		memset(s,0,sizeof(s));      //开关
		int k,n = (1<<D)-1;         //n是最大节点编号
		for(int i = 0;i<I;i++){     //连续让I个小球下落
			k = 1;
			for(;;){
				s[k]=!s[k];
				k = s[k] ? k*2 : k*2+1;     //根据开关状态选择下落方向
				if(k>n)  break;             //已经落“出界”了
			}
		}
		printf("%d\n",k/2);         //“出届”之前的叶子编号
	}
	return 0;
}
