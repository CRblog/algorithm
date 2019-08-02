#include<bits/stdc++.h>
using namespace std;
void test(int *arr){
	arr[0] = 9;
}
int main()
{
	int arr[] = {0,1,2,3,4};
	char a1[] = {'a','b','c'};
	const char *str = "asdasd";
	char b[10] = {1,2,3,4};
	char a[10];
	cout<<strlen(a)<<endl;
	strcpy(a,b);
	cout<<strlen(a)<<endl;
	strcat(a,b);
	cout<<strlen(a)<<endl;
	int ret = strcmp(a,b);
	cout<<ret<<endl;
	strncpy(a,b,3);
	cout<<strlen(a)<<endl;
	strncat(a,b,3);
	cout<<strlen(a)<<endl;
	cout<<pow(2,4)<<endl;
	
	union Un
	{
		char c;
		int i;
	}u;
	printf("%d\n",&(u.i));
	printf("%d\n",&(u.c));
	return 0;
int arr[] = {1,2,3,4,5,6,7};
int *p = arr;
cout<<*p<<endl;
*(p++)+=89;

printf("%d,%d\n",*p,*(++p));
return 0;
}

