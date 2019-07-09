#include <iostream>
#include <string>
#include <math.h>
int main()
{
	int n;
	while(std::cin >> n)
	{
		if (n == 0) break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		std::cout << total << " " << left << std::endl;
	}
return 0;
}
