#include<iostream>
#include<string>
using namespace std;

bool IsCircleText(const string& str)  //判断字符串是否是回文
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
  getline(cin,s1);//输入字符串
  getline(cin,s2);
  size_t count = 0;
  for(size_t i=0;i<=s1.size();i++)
  {
    string str = s1;   //将字符串接收以防止字符串改变，影响下一循环的输入
    str.insert(i,s2);  //循环插入到每一个位置上
    if(IsCircleText(str)) //如果插入后的字符串是回文，计数+1
    {
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
