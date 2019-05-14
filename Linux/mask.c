
/*信号的阻塞---体会信号的可靠不可靠
 * 先将所有信号阻塞
 * 按回车---程序继续运行
 * 将所有信号解除阻塞
 * int sigprocmask(int how,const sigset_t *set,ingset_t *oldset);
 * how: 对信号阻塞集合要进行的动作
 *  SIG_BLOCK         block = block | set    将set中的信号添加到阻塞集合
 *  SIG_UNBLOCK       block = blcok & (~set) 对set中的信号解除阻塞
 *  SIG_SETMASK       将阻塞集合设置为set中的信号
 *  set
 *  oldset        用于保存原来的信号集合
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
  //清空set信号集合
  sigemptyset(&set);
  //int sigfillset(sigset_t *set);
  //将所有信号添加到set集合中
  //int sigaddset(sigset_t *set,int signum);
  //将signum信号添加到set集合中
  //int sigdelset(sigset_t *set,int signum);
  //将signum信号从set集合中移除
  sigfillset(&set);   //所有信号添加到set集合
  sigprocmask(SIG_BLOCK,&set,&oldset);//set集合设置为阻塞
  printf("press enter to continue\n");
  getchar();
  sigprocmask(SIG_UNBLOCK,&set,NULL);
  sigprocmask(SIG_SETMASK,&oldset,NULL);

  return 0;
}

