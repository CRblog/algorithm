#include"myshm.h"
#include<string.h>
int main()
{
  //1.����/�򿪹����ڴ�
  int shmid = CreateShm();
  //���ӵ������ڴ������
  printf("shmid = %d",shmid);
  if(shmid == -1)
  {
    perror("shmget error");
    return -1;
  }

  char* p = (char*)shmat(shmid,NULL,0);
  //ʹ��
  printf("%s",p);
  strcpy(p,"o\n");
  return 0;
}

