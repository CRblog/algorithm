#include<bits/stdc++.h>
using namespace std;
//STL����
//
//1.����ʯ������
//    ������N������ʯ��ÿ������ʯ��д��һ���Ǹ����������ȰѸ�����С��������
//    Ȼ��ش�Q�����⣬ÿ���������Ƿ���һ������ʯд��ĳ������x������ǣ���Ҫ�ش����Ǹ�����ʯ��д��x
//const int maxn = 10000;
//int main(){
//	int n,q,x,a[maxn],kase = 0;
//	while(scanf("%d%d",&n,&q)==2&&n){
//		printf("CASE# %d:\n",++kase);
//		for(int i=0;i<n;i++)    scanf("%d",&a[i]);
//		sort(a,a+n);//����
//		while(q--){
//			scanf("%d",&x);
//			int p=lower_bound(a,a+n,x)-a;//��������������a��Ѱ��x
//			if(a[p]==x)     printf("%d found at %d\n",x,p+1);
//			else    printf("%d not found\n",x);
//		}
//	}
//	return 0;
//}
//
//����������vector
//a.size()  		//��С
//a.resize()  	//�ı��С
//a.push_back() 	//��β�����Ԫ��
//a.pop_back()    //ɾ�����һ��Ԫ��
//1.ľ������
//    ��������n��ľ�飬���Ϊ0~n-1��Ҫ��ģ��һ��4�ֲ���(�����a,b����ľ����)
//    move a onto b    a,b��λ��Ȼ���a����b����
//	move a over b    ��a�Ϸ���ľ��ȫ����λ��Ȼ���a����b����ľ��ѵĶ���
//	pile a onto b    ��b�Ϸ���ľ��ȫ����λ��Ȼ���a�Լ������ľ����������b����
//	pile a over b    ��a�������ľ����������b����ľ��ѵĶ���
//const int maxn = 30;
//int n;
//vector<int> pile[maxn]; //ÿһ��pile[i]��һ��vector
////��ľ��a���ڵ�pile��height�������õ���ʽ���ص�����
//void find_block(int a,int& p,int& h){
//	for(p=0;p<n;p++)
//		for(h=0;h<pile[p].size();h++)
//			if(pile[p][h]==a) return;
//}
////�ѵ�p�Ѹ߶�Ϊh��ľ���Ϸ�������ľ���ƻ�ԭλ
//void clear_above(int p,int h){
//	for(int i = h+1;i<pile[p].size();i++){
//		int b = pile[p][i];
//		pile[b].push_back(b);   //��ľ��b�Ż�ԭλ
//	}
//    pile[p].reszie(h+1);
//}
////�ѵ�p�Ѹ߶�Ϊh�����Ϸ���ľ�������ƶ���p2�ѵĶ���
//void pile_onto(int p,int h,int p2){
//	for(int i=h;i<pile[p].size();i++)
//		pile[p2].push_back(pile[p][i]);
//	pile[p].resize(h);
//}
//void print(){
//	for(int i=0;i<n;i++){
//		printf("%d:",i);
//		for(int j=0;j<pile[i].size();j++)   printf(" %d",pile[i][j]);
//		printf("\n");
//	}
//}
//int main(){
//	int a,b;
//	cin>>n;
//	string s1,s2;
//	for(int i=0;i<n;i++)    pile[i].push_back(i);
//	while(cin>>s1>>a>>s2>>b) {
//		int pa,pb,ha,hb;
//		find_block(a,pa,ha);
//		find_block(b,pb,hb);
//		if(pa == pb)    continue;//�Ƿ�ָ��
//		if(s2 == "onto")    clear_above(pb,hb);
//		if(s1 == "move")    clear_above(pa,ha);
//		pile_onto(pa,ha,pb);
//	}
//	print();
//	return 0;
//}
//3.����set
//����һ���ı����ҳ����в�ͬ�ĵ���,���ֵ�������
set<string> dict;//set����

int main(){
	string s,buf;
	while(cin>>s){
		for(int i=0;i<s.length();i++)
			if(isalpha(s[i])) s[i] = tolower(s[i]); else    s[i] = ' ';
			stringstream ss(s);
			while(ss>>buf) dict.insert(buf);
	}
	for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
		cout<< *it<<"\n";
		return 0;
}
