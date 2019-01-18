#include<bits/stdc++.h>
using namespace std;
//STL入门
//
//1.大理石在哪里
//    现在有N个大理石，每个大理石上写了一个非负整数。首先把各数从小到大排序，
//    然后回答Q个问题，每个问题问是否有一个大理石写着某个整数x，如果是，还要回答在那个大理石上写着x
//const int maxn = 10000;
//int main(){
//	int n,q,x,a[maxn],kase = 0;
//	while(scanf("%d%d",&n,&q)==2&&n){
//		printf("CASE# %d:\n",++kase);
//		for(int i=0;i<n;i++)    scanf("%d",&a[i]);
//		sort(a,a+n);//排序
//		while(q--){
//			scanf("%d",&x);
//			int p=lower_bound(a,a+n,x)-a;//在已排序中数组a中寻找x
//			if(a[p]==x)     printf("%d found at %d\n",x,p+1);
//			else    printf("%d not found\n",x);
//		}
//	}
//	return 0;
//}
//
//不定长数组vector
//a.size()  		//大小
//a.resize()  	//改变大小
//a.push_back() 	//向尾部添加元素
//a.pop_back()    //删除最后一个元素
//1.木块问题
//    从左到右有n个木块，编号为0~n-1，要求模拟一下4种操作(下面的a,b都是木块编号)
//    move a onto b    a,b归位，然后把a摞在b上面
//	move a over b    把a上方的木块全部归位，然后把a放在b所在木块堆的顶部
//	pile a onto b    把b上方的木块全部归位，然后把a以及上面的木块整体摞在b上面
//	pile a over b    把a及上面的木块整体摞在b所在木块堆的顶部
//const int maxn = 30;
//int n;
//vector<int> pile[maxn]; //每一个pile[i]是一个vector
////找木块a所在的pile和height，以引用的形式返回调用者
//void find_block(int a,int& p,int& h){
//	for(p=0;p<n;p++)
//		for(h=0;h<pile[p].size();h++)
//			if(pile[p][h]==a) return;
//}
////把第p堆高度为h的木块上方的所有木块移回原位
//void clear_above(int p,int h){
//	for(int i = h+1;i<pile[p].size();i++){
//		int b = pile[p][i];
//		pile[b].push_back(b);   //把木块b放回原位
//	}
//    pile[p].reszie(h+1);
//}
////把第p堆高度为h及其上方的木块整体移动到p2堆的顶部
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
//		if(pa == pb)    continue;//非法指令
//		if(s2 == "onto")    clear_above(pb,hb);
//		if(s1 == "move")    clear_above(pa,ha);
//		pile_onto(pa,ha,pb);
//	}
//	print();
//	return 0;
//}
//3.集合set
//输入一个文本，找出所有不同的单词,按字典序排列
set<string> dict;//set集合

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
