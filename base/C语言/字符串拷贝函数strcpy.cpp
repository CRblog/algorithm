#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cassert>
using namespace std;

char* my_strcpy(char *dest,const char *src)
{
	char *cp = dest;
	assert(src && dest);//еп©у
	while(*dest++ = *src++)
	{
		;
	}
	return cp;
}
int main()
{
	char arr[80] = {0};
	printf("%s\n",my_strcpy(arr,"hello world"));
	return 0;
}
