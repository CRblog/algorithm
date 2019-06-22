#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
	for (int i = 0; i < num; ++i)
		cin >> table[i];
		while (k--)
		{
		vector<int> n1(table.begin(), table.end());
		for (int i = 0; i < n; ++i)
		{
			//如果当前数小于等于n（即在左手），则他下次出现的位置是 2*当前位置
			//与之对应的当前位置 + n（即在右手）的牌,则他下次出现的位置是 2*当前位置 + 1
			table[2 * i] = n1[i];
			table[2 * i + 1] = n1[i + n];
		}
		}
	for (int i = 0; i < num - 1; ++i)
		cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
return 0;
}
