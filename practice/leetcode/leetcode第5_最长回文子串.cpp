#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
	int len = s.length();
	int start = 0;
	int max = 1;
	vector<vector<int>>  dp(len, vector<int>(len));//�����ά��̬����
	if (len == 0 || len == 1)
		return s;
	for (int i = 0; i<len; i++)//��ʼ��״̬     
	{
		dp[i][i] = 1;    //����Ϊ1�Ļ�����1
		if (i<len - 1 && s[i] == s[i + 1])  //ȷ������Ϊ2�Ļ��ģ������ڵ��ַ���
		{
			dp[i][i + 1] = 1;
			max = 2;
			start = i;
		}
	}
	for (int l = 3; l <= len; l++)//�ӳ���Ϊ3���ַ�����ʼ���
	{
		for (int i = 0; i + l - 1<len; i++)
		{
			int j = l + i - 1;//��ֹ�ַ�λ��
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//״̬ת��
			{
				dp[i][j] = 1;
				start = i;
				max = l;
				cout << "dp[" << i << "][" << j <<"]start:"<<start<<"max:"<<max<<endl;
			}
		}
	}
	return s.substr(start, max);//��ȡ������Ӵ�
}
int main()
{
	string s1 = "baabaca";
	cout<<longestPalindrome(s1)<<endl;
	system("pause");
	return 0;

}