#include"myshm.h"
#include<string.h>
int main()
{
  //1.创建/打开共享内存
  int shmid = CreateShm();
  //附加到共享内存对象上
  printf("shmid = %d",shmid);
  if(shmid == -1)
  {
    perror("shmget error");
    return -1;
  }

  char* p = (char*)shmat(shmid,NULL,0);
  //使用
  printf("%s",p);
  strcpy(p,"o\n");
  return 0;
}

