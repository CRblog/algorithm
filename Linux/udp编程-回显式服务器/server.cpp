//UDP版本的
#include<sys/socket.h>
#include<sys/types.h>
#include<error.h>
#include<cstdio>
#include<cstring>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
  //1.先创建一个socket
  //AF_INET 是 一个宏，表示使用ipv4协议
  //SOCK_DGRAM表示使用UDP协议
 //int socket(int domain, int type, int protocol);
  int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0) {  //创建失败
      perror("socket");
      return 1;
    }
  //2.把当前的socket绑定上一个ip + 端口号
  sockaddr_in addr;   //这是一个结构体
  addr.sin_family = AF_INET;
  //ip地址也是一个整数，也需要转成网络字节序，但是inet_addr帮我们转好了
  addr.sin_addr.s_addr  = inet_addr("0.0.0.0");   //这个是可以接收的IP地址，0代表所有的IP地址
 //主机字节序的数字转成网络字节序
  addr.sin_port = htons(9090);                   //9090端口无特殊含义，比较不常用
  int ret = bind(sock,(sockaddr*)&addr,sizeof(addr));
  if(ret < 0){
    perror("bind");
    return 1;
  }
  printf("sever start ok!\n");
  //3.处理服务器收到的请求
  while(true){
    //a)读取客户端的请求
    //面向数据报的函数接口
    sockaddr_in peer;
    socklen_t len = sizeof(peer);  //输入输出参数
    char buf[1024] = {0};   //缓冲区
    ssize_t n=recvfrom(sock,buf,sizeof(buf)-1,0,
        (sockaddr*)&peer,&len);
    if( n < 0)
    {
      perror("recvfrom");
      continue;
    }
    buf[n] = '\0';
    //b) 根据请求计算响应
    //响应和请求相同
    //c) 把响应写回客户端
    n = sendto(sock,buf,strlen(buf),0,(sockaddr*)&peer,len);
    if(n < 0)
    {
      perror("sendto");
      continue;
    }
    printf("[%s:%d] buf: %s\n",inet_ntoa(peer.sin_addr),
        ntohs(peer.sin_port),buf);
  }
  close(sock);
  return 0;
}


