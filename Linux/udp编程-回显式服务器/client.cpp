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
 //1.�ȴ���һ��socket
  int sock = socket(AF_INET,SOCK_DGRAM,0);
  if(sock < 0)
  {
    perror("socket");
    return 1;
  }
//�ͻ���һ�㲻��Ҫbind
//bind��ζ�ź�ĳ������Ķ˿ں�������һ��
//���û��bind������ϵͳ���������һ���˿ں�
//����Ƿ���������ȥbind���ͻᵼ��ÿ����������Ķ˿ڶ���仯
//�ͻ��˾�û��������
//����ͻ���Ҳbind�˻���ô����
//һ���˿ں�ֻ�ܱ�һ������bind������ͻ���bindһ���˿ںţ������ͻ���Ҳ����bindͬһ���˿�
//���Կͻ��˻�������ò���ϵͳ����������ѧ

//׼���÷�������sockaddr_in �ṹ
  sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(9090);
//4.�ͻ���ֱ�ӷ������ݼ���
  while(1){
  char buf[1024] = {0};
  printf("������һ������:");
  fflush(stdout);
  scanf("%s",buf);
  sendto(sock,buf,strlen(buf),0,
        (sockaddr*)&server_addr,sizeof(server_addr));
  //�ӷ���������һ�·��ؽ��
  char buf_output[1024] = {0};
  //������������NULL��ʾ����ע�Զ˵ĵ�ַ
  recvfrom(sock,buf_output,sizeof(buf_output),0,NULL,NULL);
  printf("server resp: %s\n",buf_output);
  }
  return 0;
}

