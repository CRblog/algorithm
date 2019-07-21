#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
	int len = s.length();
	int start = 0;
	int max = 1;
	vector<vector<int>>  dp(len, vector<int>(len));//定义二维动态数组
	if (len == 0 || len == 1)
		return s;
	for (int i = 0; i<len; i++)//初始化状态     
	{
		dp[i][i] = 1;    //长度为1的回文置1
		if (i<len - 1 && s[i] == s[i + 1])  //确定长度为2的回文（即相邻的字符）
		{
			dp[i][i + 1] = 1;
			max = 2;
			start = i;
		}
	}
	for (int l = 3; l <= len; l++)//从长度为3的字符串开始检查
	{
		for (int i = 0; i + l - 1<len; i++)
		{
			int j = l + i - 1;//终止字符位置
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//状态转移
			{
				dp[i][j] = 1;
				start = i;
				max = l;
				cout << "dp[" << i << "][" << j <<"]start:"<<start<<"max:"<<max<<endl;
			}
		}
	}
	return s.substr(start, max);//获取最长回文子串
}
int main()
{
	string s1 = "baabaca";
	cout<<longestPalindrome(s1)<<endl;
	system("pause");
	return 0;

}