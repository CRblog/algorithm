#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
  //ʹ��pipe��������һ���ļ���������ͨ����һ���ļ����������ܲ����ں��еĹܵ�
  int fd[2];
  int ret = pipe(fd);
  if(ret < 0)
  {
    perror("pipe");
    return 1 ;
  }
  //fd[0] -> ������
  //fd[1] -> д����
  ret = fork();
  if(ret > 0)
  {
    //������
    char buf[1024] = "there is a test!";
    write(fd[1],buf,strlen(buf));
  }
  else if(ret == 0)
  {
    //�ӽ���
    char buf_output[1024] = {0};
    read(fd[0],buf_output,sizeof(buf_output)-1);//�����ռ����'/0'�ı���
    printf("%s\n",buf_output);
  }
  else
  {
    perror("fork");
  }
  //�ܵ�ʹ����֮����Ҫ��ʱ���ļ�������
  close(fd[0]);
  close(fd[1]);
  return 0;
}

