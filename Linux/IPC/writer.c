#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{
  int fd = open("./fifo1",O_WRONLY);
  if(fd < 0)
  {
    perror("open");
    return 1;
  }
  while(1)
  {
    printf("-> ");
    fflush(stdout);
    char buf[1024] = {0};
    read(0,buf,sizeof(buf)-1);
    write(fd,buf,strlen(buf));
  }
  close(fd);
  return 0;
}
