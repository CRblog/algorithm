#include<vector>
#include<iterator>
#include<cctype>
#include<iostream>
#include<string>
using namespace std;

void printfvector(const vector<int>& v)
{
  for(auto& e : v)
  {
    cout<<e<<" ";
  }
  cout<<endl;
}
int main()
{
  vector<int> v1(5,2);
  vector<int> v2(5,9);
  cout<<"��ʼ��v1-v2"<<endl;
  printfvector(v1);
  printfvector(v2);
  swap(v1,v2);//ȫ�ֽ�������
  cout<<"ȫ���޸�v1-v2"<<endl;
  printfvector(v1);
  printfvector(v2);
  v1.swap(v2);//��������
  cout<<"�����޸�v1-v2"<<endl;

  //���ַ�ʽ����������ͬ�����ǵ���v1.swap(v2)
  //ͨ��ȫ�ֺ�����swap(T& v1,T& v2)---->{T temp = v1; v1 = v2; v2 = temp}
  //�ͷſռ䣺
  //1��{
  //    vector<int> v2;
  //    v2.swap(v1);
  //   }�����ŵ������ǵ�����������,�൱�ڽ��ֲ�������ȫ�ֱ�������������������֮���������������v2�ͷ�
  //2:v1.shrink_to_fit();
  printfvector(v1);
  printfvector(v2);
  return 0;
}

