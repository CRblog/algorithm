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
  //key：共享内存标识符
  //size:共享内存大小
  //shmflg:
  //     IPC_CREAT ->存在则打开，不存在则创建
  //     IPC_EXCL  ->如果已经存在就返回失败
  if(ret < 0)
  {
    perror("shmget");
    return 1;
  }
  printf("%d",ret);
  return ret;
}

