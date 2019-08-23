#include<bits/stdc++.h>
using namespace std;
bool check(string str, string name)
{
	int count = 0;
	int length = name.size();
	for (int i = 0; i<name.size(); ++i)
	{
		for (int j = 0; j<str.size(); ++j)
		{
			if (name[i] == str[j])
			{
				i++;
				count++;
				if (count == str.size())
					return true;
			}
			else
				count = 0;
		}
	}
	return false;
}
int main()
{

	long long int n, number;  //×ÜÊý
	cin >> n;
	string s[5];
	vector<string> animal_name(100005);
	//string animal_name[100005];
	for (int i = 1; i <= 3; ++i)
	{
		cin >> s[i];
	}
	for (long long int i = 1; i <= n; ++i)
	{
		cin >> animal_name[i] >> number;
		if (check(s[number], animal_name[i]) == false)
		{
			if (number == 2)
			{
				animal_name[i] = animal_name[i] + s[number];
			}
			else
				animal_name[i] = s[number] + animal_name[i];
		}
		cout << animal_name[i] << endl;
	}
	for (long long int i = 1; i <= n; ++i)
	{
		cout << animal_name[i] << endl;
	}
	system("pause");
	return 0;
}
