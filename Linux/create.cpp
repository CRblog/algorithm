/*���̴���*/
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
    //�ӽ��̵���������δ��룬��Ϊ�����̷��ص���pid>0
    //���Բ����������ж�

    gval = 20;
  printf("-------child  line-----pid:%d val:%d-%p\n",getpid(),gval,&gval);
 }
 else{
   //ֻ�и����̽�������ж�
   sleep(1);//��֤�ӽ���������
  printf("-------parent line-----pid:%d val:%d-%p\n",getpid(),gval,&gval);
 }
  return 0 ;
  //----head----
  //fork()
  //----tail----
  //
}

