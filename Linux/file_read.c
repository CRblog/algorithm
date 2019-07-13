#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
  FILE *fp = fopen("readme.txt","r");
  if(!fp)
  {
    perror("open error!");
  }
  char buf[1024];
  const char *msg = "you see see you ,one day dat de !";
  while(1)
  {
    ssize_t s = fread(buf,1,strlen(msg),fp);
    //返回值s代表的是读取字符的元素个数
	if(s>0)
    {
      buf[s] = 0;
      printf("%s",buf);
    }
    if(feof(fp))  //文件结束标志
	{
      break;
    }
  }
  fclose(fp);
    return 0;
}
