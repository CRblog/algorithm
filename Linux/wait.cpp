//进程等待
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
  int pid= fork();
  if(pid<0){
    perror("fork error");
    exit(-1);
  }
  else if(pid == 0)
  {
    sleep(5);
    exit(0);//五秒钟后子进程成为僵尸进程
  }
  //pid_t wait(int *status);
  //阻塞等待任意一个子进程退出
  //status:用于获取子进程的退出码   不关注则置空即可
  //返回值：退出的子进程的pid
 // wait(NULL);
 //pid_t waitpid(pid_t pid,int *status,int options);
 //可以等待任意一个子进程退出/等待指定子进程退出
 //pid: -1:等待任意子进程   >0:等待指定子进程
 //status   用于获取子进程的退出码，不关注则置空即可
 //options:
 //     0:阻塞等待子进程退出
 //     WNOHANG  将waispid设置位非阻塞
 // 返回值：>0:退出的子进程的pid   ==0:当前没有子进程退出  <0：出错
 // int ret = waitpid(pid,NULL,0);
 /// if(ret<0){
 //    perror("waitpid error");
   //   return -1;
 // }
  printf("pid:%d-%d\n",ret,pid);
  while(1){
    printf("--------i am parent!!\n");
    sleep(1);
  }
  return 0;
}

