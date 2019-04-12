/*进程创建*/
#include<stdio.h>
#include<unistd.h>
int gval = 100;
int main()
{
  printf("-------head line------pid:%d val:%d\n",getpid(),gval);
 pid_t pid = fork();
 if(pid<0){
   printf("fork error\n");
   return -1;
 }
 if(pid==0){
    //子进程单独运行这段代码，因为父进程返回的是pid>0
    //所以不会进入这个判断

    gval = 20;
  printf("-------child  line-----pid:%d val:%d-%p\n",getpid(),gval,&gval);
 }
 else{
   //只有父进程进入这个判断
   sleep(1);//保证子进程先运行
  printf("-------parent line-----pid:%d val:%d-%p\n",getpid(),gval,&gval);
 }
  return 0 ;
  //----head----
  //fork()
  //----tail----
  //
}

