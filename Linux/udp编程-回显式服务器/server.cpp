//UDP�汾��
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
  //1.�ȴ���һ��socket
  //AF_INET �� һ���꣬��ʾʹ��ipv4Э��
  //SOCK_DGRAM��ʾʹ��UDPЭ��
 //int socket(int domain, int type, int protocol);
  int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0) {  //����ʧ��
      perror("socket");
      return 1;
    }
  //2.�ѵ�ǰ��socket����һ��ip + �˿ں�
  sockaddr_in addr;   //����һ���ṹ��
  addr.sin_family = AF_INET;
  //ip��ַҲ��һ��������Ҳ��Ҫת�������ֽ��򣬵���inet_addr������ת����
  addr.sin_addr.s_addr  = inet_addr("0.0.0.0");   //����ǿ��Խ��յ�IP��ַ��0�������е�IP��ַ
 //�����ֽ��������ת�������ֽ���
  addr.sin_port = htons(9090);                   //9090�˿������⺬�壬�Ƚϲ�����
  int ret = bind(sock,(sockaddr*)&addr,sizeof(addr));
  if(ret < 0){
    perror("bind");
    return 1;
  }
  printf("sever start ok!\n");
  //3.����������յ�������
  while(true){
    //a)��ȡ�ͻ��˵�����
    //�������ݱ��ĺ����ӿ�
    sockaddr_in peer;
    socklen_t len = sizeof(peer);  //�����������
    char buf[1024] = {0};   //������
    ssize_t n=recvfrom(sock,buf,sizeof(buf)-1,0,
        (sockaddr*)&peer,&len);
    if( n < 0)
    {
      perror("recvfrom");
      continue;
    }
    buf[n] = '\0';
    //b) �������������Ӧ
    //��Ӧ��������ͬ
    //c) ����Ӧд�ؿͻ���
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


