#include<cstdio>
#include<cstring>
#include<cassert>
using namespace std;

void reverve_swap(char *left,char *right)
{
	assert(left != NULL);
	assert(right != NULL);
	while(left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
char *reverve(char *p)
{
	int len = strlen(p);
	char *start = p;
    char *end = NULL;
    char *ret = p;
    reverve_swap(p, p + len - 1); 
    while (*p)
    {
        start = p;
        while ((*p != ' ') && (*p != '\0')) 
        {
            p++;
        }
        end = p - 1;
        reverve_swap(start, end);
        if (*p == ' ')
            p++;
    }
    return ret;

}
int main()
{
    char arr[] = "student a am I";
    printf("交换前：%s\n", arr);
    printf("交换后：%s\n", reverve(arr));
    system("pause");
    return 0;
}
