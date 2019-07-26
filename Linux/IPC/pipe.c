#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
  //使用pipe函数创建一对文件描述符，通过这一对文件描述符就能操作内核中的管道
  int fd[2];
  int ret = pipe(fd);
  if(ret < 0)
  {
    perror("pipe");
    return 1 ;
  }
  //fd[0] -> 读数据
  //fd[1] -> 写数据
  ret = fork();
  if(ret > 0)
  {
    //父进程
    char buf[1024] = "there is a test!";
    write(fd[1],buf,strlen(buf));
  }
  else if(ret == 0)
  {
    //子进程
    char buf_output[1024] = {0};
    read(fd[0],buf_output,sizeof(buf_output)-1);//留出空间便于'/0'的保存
    printf("%s\n",buf_output);
  }
  else
  {
    perror("fork");
  }
  //管道使用完之后需要及时关文件描述符
  close(fd[0]);
  close(fd[1]);
  return 0;
}

