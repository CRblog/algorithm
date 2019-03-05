#include<stdio.h>
unsigned int reverse_bit(unsigned int value)
{
	unsigned int sum = 0;
	int i=0;
	for(i=0;i<32;i++)
	{
		sum+=((value>>i)&1)<<(31-i);
	}
	return sum;
}
int main()
{
	unsigned int num = 25;
	printf("·´×ªºó:%u\n",reverse_bit(num));
	return 0;
}
