#include"myshm.h"
int main()
{
  //�ӹ����ڴ��ж�����
  int shmid = CreateShm();
  char *p = (char*)shmat(shmid,NULL,0);
  printf("reader: %s\n",p);
  return 0;
}

