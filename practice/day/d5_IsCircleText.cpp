#include<iostream>
#include<string>
using namespace std;

bool IsCircleText(const string& str)  //�ж��ַ����Ƿ��ǻ���
{
  int begin = 0;
  int end = str.size()-1;
  while(begin<end)
  {
    if(str[begin]!=str[end])
    {
      return false;
    }
    ++begin;
    --end;
  }
  return true;
}

int main()
{
  string s1,s2;
  getline(cin,s1);//�����ַ���
  getline(cin,s2);
  size_t count = 0;
  for(size_t i=0;i<=s1.size();i++)
  {
    string str = s1;   //���ַ��������Է�ֹ�ַ����ı䣬Ӱ����һѭ��������
    str.insert(i,s2);  //ѭ�����뵽ÿһ��λ����
    if(IsCircleText(str)) //����������ַ����ǻ��ģ�����+1
    {
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
