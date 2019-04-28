/*
 *自主minishell实现
 1.获取标准输入
 2.解析输入得到[命令名]+[运行参数]
 3.创建子进程
      子进程进行程序替换
 4.进程等待
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
    // %[^\n]    从缓冲区取数据的时候，遇到\n为止：[   ls    -l ]
    // 经过这一步之后，缓冲区中留下了\n，但是\n取不出来，导致scanf非阻塞
    // 但又取不出最后的\n字符
    // %*c   从缓冲区中取出一个字符，丢弃，不做任何存储
    if(scanf("%[^\n]%*c",buf)!=1){
      getchar();
      continue;
    }//   [^\n]   遇到\n结束
    //现在成功获得字符串
    //printf("%s\n",buf);

    int argc=0;
    char *argv[32];
    char *ptr = buf;
    while(*ptr != '\0'){   //遍历到结尾
      if(!isspace(*ptr)){
        //判断是否是空白字符   isspace（）  空白字符包括：  空格，\f,\n,\r,\t,\v
        argv[argc] = ptr;
        argc++;
        while(!isspace(*ptr) && *ptr != '\0'){
          ptr++;
        }
        *ptr = '\0';
       // printf("argv[%d]=[%s]\n",argc-1,argv[argc-1]);
      }
           //字符串解析完毕
      ptr++;
    }
    argv[argc] =NULL;      //命令以NULL结尾
    //实现shell内健命令
    if(strcmp(argv[0],"cd")==0){
      chdir(argv[1]);                    //改变当前工作路径
      continue;
    }

    //创建子进程
    int pid  = fork();
    if(pid < 0){
      perror("fork error");
      return -1;
    }else if(pid == 0){
      execvp(argv[0],argv);
      exit(-1);//替换失败则直接退出
    }
    wait(NULL);
  }
  return 0;
}

