/*
 *����minishellʵ��
 1.��ȡ��׼����
 2.��������õ�[������]+[���в���]
 3.�����ӽ���
      �ӽ��̽��г����滻
 4.���̵ȴ�
 *
 * */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<ctype.h>


int main()
{
  while(1){
    char buf[1024] = {0};
    printf("[user@localhost]$ ");
    fflush(stdout);
    // ls   -l\n
    // %[^\n]    �ӻ�����ȡ���ݵ�ʱ������\nΪֹ��[   ls    -l ]
    // ������һ��֮�󣬻�������������\n������\nȡ������������scanf������
    // ����ȡ��������\n�ַ�
    // %*c   �ӻ�������ȡ��һ���ַ��������������κδ洢
    if(scanf("%[^\n]%*c",buf)!=1){
      getchar();
      continue;
    }//   [^\n]   ����\n����
    //���ڳɹ�����ַ���
    //printf("%s\n",buf);

    int argc=0;
    char *argv[32];
    char *ptr = buf;
    while(*ptr != '\0'){   //��������β
      if(!isspace(*ptr)){
        //�ж��Ƿ��ǿհ��ַ�   isspace����  �հ��ַ�������  �ո�\f,\n,\r,\t,\v
        argv[argc] = ptr;
        argc++;
        while(!isspace(*ptr) && *ptr != '\0'){
          ptr++;
        }
        *ptr = '\0';
       // printf("argv[%d]=[%s]\n",argc-1,argv[argc-1]);
      }
           //�ַ����������
      ptr++;
    }
    argv[argc] =NULL;      //������NULL��β
    //ʵ��shell�ڽ�����
    if(strcmp(argv[0],"cd")==0){
      chdir(argv[1]);                    //�ı䵱ǰ����·��
      continue;
    }

    //�����ӽ���
    int pid  = fork();
    if(pid < 0){
      perror("fork error");
      return -1;
    }else if(pid == 0){
      execvp(argv[0],argv);
      exit(-1);//�滻ʧ����ֱ���˳�
    }
    wait(NULL);
  }
  return 0;
}

