#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#if 0
int main()
{
  FILE* fp = fopen("readme.txt","rw");
  if(!fp)
  {
    perror("open error!");
  }
  const char *msg = "You see see you , one day day de!";
  int count = 10;
  while(count--)
  {
    fwrite(msg,strlen(msg),1,fp);
  }
  fclose(fp);
  return 0;
}
#endif
#if 0
int main()
{
 //printf("stdout: %d\n",stdin->_fileno);
 //printf("stdout: %d\n",stdout->_fileno);
 //printf("stderr: %d\n",stderr->_fileno);

  //���ļ�����ȡ�ļ�������
  //int open(cosnt char *pathname,int flags);
  //int open(const char *pathname,int flags,mode_t mode);
  int fd = open("./readme.txt",O_RDWR);
  // printf("fd = %d\n",fd);
  // fd = 3   3->���������±�
  if(fd < 0){
    perror("open error!");
    return 1;
  }
  char buf[1024] = {0};
  //���ļ�
  ssize_t n = read(fd,buf,sizeof(buf));   //���ļ��е����ݶ���buf
  // ����ֵn�Ƕ���Ԫ�صĸ���
  buf[n] = '\0';   //�ֶ����� \0 ���߸�sizeof(buf) - 1
  printf("%s\n",buf);
  close(fd);
  return 0;
}
#endif

#if 0
int main()
{
  int fd = open("./readme.txt",O_RDWR);
  if(fd < 0)
  {
    perror("open error!");
    return 1;
  }
  char buf[1024]="hahahahahahahahhahihiahahhahaha";
  //д�ļ�
  ssize_t n = write(fd,buf,strlen(buf));
  close(fd);
  return 0;
}
#endif
#if
int main()
{
  return 0;
}

