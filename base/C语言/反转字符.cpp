//反转字符
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
using namespace std;

void move(char *arr,int count){
	int j=0;
	char tmp = arr[0];
	for(j=0;j<count-1;j++){
		arr[j]=arr[j+1];
	}
	arr[j]=tmp;
	count--;
}

char leftMove(char *arr,int sz,int count){
	assert(arr);
	count %= sz;
	while(count--){
		move(arr,sz);
	}
}
int main(){
	char arr[] = "ABCD";
	printf("%s\n",arr);
	int count = 0;
	printf("请输入你要左旋的位数:");
	scanf("%d",&count);
	int sz = sizeof(arr)/sizeof(arr[0])-1;
	leftMove(arr,sz,count);
	printf("旋转后的字符 :\n%s",arr);
	return 0;
}
