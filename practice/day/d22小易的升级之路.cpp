#include<vector>
#include<iostream>
using namespace std;
int GCD(int a, int b)
{
int c;
while (c = a % b)
{
a = b;
b = c;
}
return b;
}
int main()
{
int n, power;
vector<int> num;
while (cin >> n >> power)
{
num.resize(n);
for (int i = 0; i < n; i++)
{
cin >> num[i];
}
for (int k = 0; k < n; k++)
{
if (num[k] < power)
{
power += num[k];
}
else
{
power += GCD(power, num[k]);
}
}
cout << power << endl;
}
return 0;

