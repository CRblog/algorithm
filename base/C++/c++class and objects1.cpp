#include<iostream>
using namespace std;

/*
 * ���ã�
 *    ʹ�ó�����
 *          1.������
 *            void Swap(int& x1,int& x2)
 *            {
 *              int x = x1;
 *              x1 = x2;
 *              x2 = x;
 *            }
 *          2.������ֵ
 *          ����ֵ�����õ����壺
 *          int& TestRefReturn(const int& a)
 *          {�����÷���
 *             a+=10;
 *             return a;//����a�ı���������Ҫ������ʱ����
 *          }
 *          int TestRefReturn(int a)
 *          {��ֵ����
 *            a+=10;
 *            return a;//����a�Ŀ�������Ҫ������ʱ����
 *          }
 *    ָ������õ�����
 *         1.�����ڶ���ʱ�����ʼ����ָ��û��Ҫ��
 *         2.�����ڳ�ʼ��ʱ����һ��ʵ��󣬾Ͳ�������������ʵ�壬��ָ��������κ�ʱ��ָ���κ�һ��ͬ���͵�ʵ�塣
 *         3.û��NULL���ã���NULLָ��
 *         4.��sizeof�к��岻ͬ�����ý��Ϊ�������͵Ĵ�С����ָ��ʼ���ǵ�ַ�ռ���ռ�ֽڸ�����32λƽ̨��ռ4���ֽڣ�
 *         5.�����ԼӼ����õ�ʵ������1��ָ���ԼӼ�ָ�����ƫ��һ�����͵Ĵ�С
 *         6.�ж༶ָ�룬��û�ж༶����
 *         7.����ʵ�巽ʽ��ͬ��ָ����Ҫ��ʽ�����ã����ñ༭���Լ�����
 *         8.���ñ�ָ��ʹ��������Ը���ȫ
 *    ����������
 *         ��inline���εĺ���
 *        1.inline��һ���Կռ任ʱ���������ʡȥ���ú������⿪�������Դ���ܳ�������ѭ��/�ݹ�ĺ���������ʹ����Ϊ��������
 *        2.inline���ڱ�����ֻ��һ�����飬�������ѭ��/�ݹ�ȣ����������Զ����Ե�����
 *
 *
 *        �����ȱ�㣺
 *     ����д����   #define MAX a>b?a:b
 *     ��ȷд����   #define MAX(a,b) ((a)>(b)?(a):(b))
 *
 *     typedef void (*FUNC)();  ����ָ��
 *          �ŵ㣺
 *              1.��ǿ����ĸ�����
 *              2.�������
 *          ȱ�㣺
 *              1.��������Ժ�
 *              2.���´���ɶ��Բ�
 *              3.û�����Ͱ�ȫ�ļ��
 *        �滻�꣺
 *            1.const �滻����
 *            2.enum  �滻����
 *            3.inline �滻�꺯��
 *        inline int Add(int a,int b)
 *         {
 *            int c = a+b;
 *            return c;
 *         }
 *         int main(){
 *         int ret = Add(1,2);
 *         return 0;
 *         }
 *    ��Ͷ���
 *      C������������̵ģ���ע���ǹ���
 *      C++�ǻ����������ģ���ע���Ƕ���֮��Ľ���
 *    ��Ķ���
 *      class className{
 *     }
 *     c�����еĽṹ�壺
 *
 *        struct ListNode{
 *            int _data;
*          struct ListNode* _next;
*          struct ListNode* _prev;
 *       };
*
*     C�У�
*     ���ͣ�struct ListNode
*     C++�У�
*     struct ��������,���ͣ�ListNode
*     struct �����漴���Զ��������Ҳ���Զ��庯��
*
*     class �� struct������
*       class  Ĭ��˽��
*       struct Ĭ�Ϲ���
 *
 *
 *
 */
int main(){

  return 0;
}
