#include<cstdio>
#include<cstring>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
// .client 127.0.0.1
int main(int argc,char* argv[])
{
 //1.先创建一个socket
  int sock = socket(AF_INET,SOCK_DGRAM,0);
  if(sock < 0)
  {
    perror("socket");
    return 1;
  }
//客户端一般不需要bind
//bind意味着和某个具体的端口号连接在一起
//如果没有bind，操作系统会随机分配一个端口号
//如果是服务器程序不去bind，就会导致每次启动服务的端口都会变化
//客户端就没法连接了
//如果客户端也bind了会怎么样？
//一个端口号只能被一个进程bind，如果客户端bind一个端口号，其他客户端也可能bind同一个端口
//所以客户端还是最好让操作系统随机分配更科学

//准备好服务器的sockaddr_in 结构
  sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(9090);
//4.客户端直接发送数据即可
  while(1){
  char buf[1024] = {0};
  printf("请输入一段内容:");
  fflush(stdout);
  scanf("%s",buf);
  sendto(sock,buf,strlen(buf),0,
        (sockaddr*)&server_addr,sizeof(server_addr));
  //从服务器接收一下返回结果
  char buf_output[1024] = {0};
  //后两个参数填NULL表示不关注对端的地址
  recvfrom(sock,buf_output,sizeof(buf_output),0,NULL,NULL);
  printf("server resp: %s\n",buf_output);
  }
  return 0;
}

