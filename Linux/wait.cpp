//���̵ȴ�
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
    exit(0);//�����Ӻ��ӽ��̳�Ϊ��ʬ����
  }
  //pid_t wait(int *status);
  //�����ȴ�����һ���ӽ����˳�
  //status:���ڻ�ȡ�ӽ��̵��˳���   ����ע���ÿռ���
  //����ֵ���˳����ӽ��̵�pid
 // wait(NULL);
 //pid_t waitpid(pid_t pid,int *status,int options);
 //���Եȴ�����һ���ӽ����˳�/�ȴ�ָ���ӽ����˳�
 //pid: -1:�ȴ������ӽ���   >0:�ȴ�ָ���ӽ���
 //status   ���ڻ�ȡ�ӽ��̵��˳��룬����ע���ÿռ���
 //options:
 //     0:�����ȴ��ӽ����˳�
 //     WNOHANG  ��waispid����λ������
 // ����ֵ��>0:�˳����ӽ��̵�pid   ==0:��ǰû���ӽ����˳�  <0������
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

