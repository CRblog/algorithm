#pragma once
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
int CreateShm()
{
  key_t key=ftok(".",0x2);
  if(key==-1)
  {
    perror("ftok");
    return 1;
  }
  printf("key = %d\n",key);
  int ret = shmget(key,1024,IPC_CREAT);
  //key�������ڴ��ʶ��
  //size:�����ڴ��С
  //shmflg:
  //     IPC_CREAT ->������򿪣��������򴴽�
  //     IPC_EXCL  ->����Ѿ����ھͷ���ʧ��
  if(ret < 0)
  {
    perror("shmget");
    return 1;
  }
  printf("%d",ret);
  return ret;
}

