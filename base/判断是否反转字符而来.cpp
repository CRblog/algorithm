#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

void reverse(char* start,char* end)
{
	while(start < end){
		char temp = *start;
		*start = *end ;
		*end = temp;
		start++;
		end--;
	}
}

void left_rotate(char* str,int k)
{
	int len = strlen(str);
	reverse(str,str + k - 1);
	reverse(str + k,str + len - 1);
	reverse(str,str + len - 1);
}
int is_rotate(char* dest,char* src)
{
	if(strlen(dest) != strlen(src)){
		return 0;
	}
	if(!strcmp(dest,src)){
		return 1;
	}
	int k = strlen(dest);
	k--;
	while(k--){
		left_rotate(src,1);
		if(!strcmp(dest,src)){
			return 1;
		}
	}
	return 0;
}
int main()
{
	char dest[100];
	char src[100];
	scanf("%s",&dest);
	scanf("%s",&src);
	if(is_rotate(dest,src)==0)
	{
		printf("不是由前面的字符串旋转得到的");
	}
	else
		printf("是旋转得到的！");
	return 0;
}
