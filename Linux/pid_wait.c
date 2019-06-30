#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  pid_t ret = fork();
  if(ret > 0){
    //father
    printf("father %d\n",getpid());
    int status = 0;
    //����ʽ�ĺ���
    pid_t result = wait(&status);   //status��һ������ͱ���
    printf("result %d\n",result);
  }
  else if(ret == 0){
    //child
    int count = 3;
    while(count > 0){
      printf("child %d\n",getpid());
      sleep(1);
      --count;
    }
    exit(0);
  }
    else{
      perror("fork");
  }
  return 0;
}

