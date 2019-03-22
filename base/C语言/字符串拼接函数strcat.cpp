#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
using namespace std;

char* my_strcat(char* dest,char* src)
{
	char *cp = dest;
	assert(src && dest);
	while(*dest!='\0')
	{
		dest++;
	}
	while(*dest++ = *src++)
	{
		;
	}
	return cp;
}

int main()
{
	char arr1[123]="abcd";
	char arr2[123]="ef";
	printf("%s\n",my_strcat(arr1,arr2));
	return 0;
	
}
