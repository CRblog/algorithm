#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  FILE *fp = fopen("readme.txt","w");
  //��д��ʽ��  readme.txt�ļ����ļ����ڵ�ǰĿ¼�£�
  if(!fp)
  {
    perror("open error\n");
    //ʧ���򱨴�
  }
  const char *msg = "you see see you, one day day de !\n";
  fwrite(msg,strlen(msg),1,fp);
  // ��������ַ�д���ļ���
  fclose(fp);
  //�ر��ļ�
  return 0;
}
