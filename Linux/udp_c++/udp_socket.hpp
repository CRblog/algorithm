#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
class UdpSocket {
public:
UdpSocket() : fd_(-1) {}
 //1.�����׽���
bool Socket() {
	fd_ = socket(AF_INET,SOCK_DGRAM,0)
	/*
  socket������int socket(int domain, int type, int protocol);
	domain��IPЭ�飺ѡ��IPv4---AF_INET
	type��ָsocket����
		SOCK_STREAM�������ֽ���---TCP
		SOCK_DGRAM: �������ݱ�----UDP
	protocol:
        ��Ϊָ����type����������һ��ȡ��
	*/
	if(fd_ < 0)
	{
		//�жϷ���ֵ�Ƿ�Ϊ��
		perror("socket error");
		return false;
	}
	return true;
}
//�ر��׽���
bool Close(){
	close(fd_);
	//�ر��׽��֣�������socket������
	return true;
}
//�󶨶˿���Ϣ(��ת��ip�ֽ���)
bool Bind(const std::string& ip,uint16_t port){
	sockaddr_in addr;
	addr.sin_family = AF_INET;  //�������������ֵ�ַ��
    addr.sin_addr.s_addr = inet_addr(ip.c_str());  //����ip��ַ��Ϣ��32λ����
    addr.sin_port = htons(port);   //����˿ں�
    int ret = bind(fd_,(sockaddr*)&addr,sizeof(addr));
	/*
    ����ԭ�ͣ�
        int bind(int socket, const struct sockaddr *address,
    socklen_t address_len);
	*/
	if(ret < 0)
	{
		perror("bind");
		return false;
	}
	return true;
}
//������Ϣ
bool RecvFrom(std::string* buf,std::string* ip = NULL,uint16_t* port = NULL){
	char tmp[1024*10] = {0};
	sockaddr_in peer;
	socklen_t len = sizeof(peer);
	ssize_t read_size = recvfrom(fd_,tmp,sizeof(tmp)-1,0,(sockaddr*)&peer,&len);
	/*
	����ԭ�ͣ�
	int recvfrom(int s, void *buf, int len, unsigned int flags,
struct sockaddr *from, int *fromlen);

		s:socket������
		buf���������ݻ�����
		len:�������ĳ���
		flags�����ò�����ʽ
		from������Դip��ַ
		fromlen��from�������ĳ���
		
	*/
	if(read_size < 0){  //û������
		perror("recvfrom");
		return false;
	}
	buf->assign(tmp,read_size);
	if(ip!=NULL)
	{
		*ip = inet_ntoa(peer.sin_addr);
		//��Դip��ַ��32λ�����ֽ���Ķ�����IP��ת���̵��ʮ����
	}
	if(port!=NULL)
	{
		*port = ntohs(peer.sin_port);
		//�������ֽ���ת���������ֽ���
		/*
			htonl()--"Host to Network Long"
    		ntohl()--"Network to Host Long"
    		htons()--"Host to Network Short"
    		ntohs()--"Network to Host Short"
		*/
	}
	return true;
}
//������Ϣ
bool SendTo(const std::string& buf,const std::string& ip,uint16_t port){
	sockaddr_in addr;
	
	addr.sin_family = AF_INET;   //IPЭ���
	addr.sin_addr.s_addr = inet_addr(ip.c_str());
	addr.sin_port = htons(port);
	//�������ֽ���ת�������ֽ���
	ssize_t write_size = sendto(fd_,buf.data(),buf.size(),0,(sockaddr*)&addr,sizeof(addr));
    /*
         int sendto (int s, const void *buf, int len,unsigned int flags,
    const struct sockaddr *to, int tolen);
	  buf.data()---������һ���ַ���ָ��
	  buf.size()--->��С
	*/
	if(write_size < 0)
	{
		perror("sendto");
		return false;
	}
	return true;
}
private:
	int fd_;
};
