#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  FILE *fp = fopen("readme.txt","w");
  //以写方式打开  readme.txt文件（文件就在当前目录下）
  if(!fp)
  {
    perror("open error\n");
    //失败则报错
  }
  const char *msg = "you see see you, one day day de !\n";
  fwrite(msg,strlen(msg),1,fp);
  // 将上面的字符写入文件中
  fclose(fp);
  //关闭文件
  return 0;
}
