#include<bits/stdc++.h>
using namespace std;

const int maxd = 20;
int s[1<<maxd];
int main(){
	int D,I;
	while(scanf("%d%d",&D,&I)==2) {
		memset(s,0,sizeof(s));      //����
		int k,n = (1<<D)-1;         //n�����ڵ���
		for(int i = 0;i<I;i++){     //������I��С������
			k = 1;
			for(;;){
				s[k]=!s[k];
				k = s[k] ? k*2 : k*2+1;     //���ݿ���״̬ѡ�����䷽��
				if(k>n)  break;             //�Ѿ��䡰���硱��
			}
		}
		printf("%d\n",k/2);         //�����족֮ǰ��Ҷ�ӱ��
	}
	return 0;
}
