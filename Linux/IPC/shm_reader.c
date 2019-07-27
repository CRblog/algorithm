#include"myshm.h"
int main()
{
  //从共享内存中读数据
  int shmid = CreateShm();
  char *p = (char*)shmat(shmid,NULL,0);
  printf("reader: %s\n",p);
  return 0;
}

