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
    //����ֵs������Ƕ�ȡ�ַ���Ԫ�ظ���
	if(s>0)
    {
      buf[s] = 0;
      printf("%s",buf);
    }
    if(feof(fp))  //�ļ�������־
	{
      break;
    }
  }
  fclose(fp);
    return 0;
}
