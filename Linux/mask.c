
/*�źŵ�����---����źŵĿɿ����ɿ�
 * �Ƚ������ź�����
 * ���س�---�����������
 * �������źŽ������
 * int sigprocmask(int how,const sigset_t *set,ingset_t *oldset);
 * how: ���ź���������Ҫ���еĶ���
 *  SIG_BLOCK         block = block | set    ��set�е��ź���ӵ���������
 *  SIG_UNBLOCK       block = blcok & (~set) ��set�е��źŽ������
 *  SIG_SETMASK       ��������������Ϊset�е��ź�
 *  set
 *  oldset        ���ڱ���ԭ�����źż���
 *
 *
 *
 *
 *
 *
 * */
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void sigcb(int signo)
{
  printf("recv signo:%d\n",signo);
}

int main(int argc,char *argv[])
{
  sigset_t set , oldset;

  signal(SIGINT,sigcb);
  signal(40,sigcb);
  //int sigemptyset(sigset_t,*set);
  //���set�źż���
  sigemptyset(&set);
  //int sigfillset(sigset_t *set);
  //�������ź���ӵ�set������
  //int sigaddset(sigset_t *set,int signum);
  //��signum�ź���ӵ�set������
  //int sigdelset(sigset_t *set,int signum);
  //��signum�źŴ�set�������Ƴ�
  sigfillset(&set);   //�����ź���ӵ�set����
  sigprocmask(SIG_BLOCK,&set,&oldset);//set��������Ϊ����
  printf("press enter to continue\n");
  getchar();
  sigprocmask(SIG_UNBLOCK,&set,NULL);
  sigprocmask(SIG_SETMASK,&oldset,NULL);

  return 0;
}

