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
 //1.创建套接字
bool Socket() {
	fd_ = socket(AF_INET,SOCK_DGRAM,0)
	/*
  socket函数：int socket(int domain, int type, int protocol);
	domain：IP协议：选择IPv4---AF_INET
	type：指socket类型
		SOCK_STREAM：面向字节流---TCP
		SOCK_DGRAM: 面向数据报----UDP
	protocol:
        因为指定了type，所以这里一般取零
	*/
	if(fd_ < 0)
	{
		//判断返回值是否为真
		perror("socket error");
		return false;
	}
	return true;
}
//关闭套接字
bool Close(){
	close(fd_);
	//关闭套接字，参数是socket描述符
	return true;
}
//绑定端口信息(先转换ip字节序)
bool Bind(const std::string& ip,uint16_t port){
	sockaddr_in addr;
	addr.sin_family = AF_INET;  //用来定义是哪种地址簇
    addr.sin_addr.s_addr = inet_addr(ip.c_str());  //保存ip地址信息，32位整数
    addr.sin_port = htons(port);   //保存端口号
    int ret = bind(fd_,(sockaddr*)&addr,sizeof(addr));
	/*
    函数原型：
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
//接收消息
bool RecvFrom(std::string* buf,std::string* ip = NULL,uint16_t* port = NULL){
	char tmp[1024*10] = {0};
	sockaddr_in peer;
	socklen_t len = sizeof(peer);
	ssize_t read_size = recvfrom(fd_,tmp,sizeof(tmp)-1,0,(sockaddr*)&peer,&len);
	/*
	函数原型：
	int recvfrom(int s, void *buf, int len, unsigned int flags,
struct sockaddr *from, int *fromlen);

		s:socket描述符
		buf：接收数据缓冲区
		len:缓冲区的长度
		flags：调用操作方式
		from：数据源ip地址
		fromlen：from缓冲区的长度
		
	*/
	if(read_size < 0){  //没有数据
		perror("recvfrom");
		return false;
	}
	buf->assign(tmp,read_size);
	if(ip!=NULL)
	{
		*ip = inet_ntoa(peer.sin_addr);
		//将源ip地址（32位网络字节序的二进制IP）转换程点分十进制
	}
	if(port!=NULL)
	{
		*port = ntohs(peer.sin_port);
		//将网络字节序转化成主机字节序
		/*
			htonl()--"Host to Network Long"
    		ntohl()--"Network to Host Long"
    		htons()--"Host to Network Short"
    		ntohs()--"Network to Host Short"
		*/
	}
	return true;
}
//发送消息
bool SendTo(const std::string& buf,const std::string& ip,uint16_t port){
	sockaddr_in addr;
	
	addr.sin_family = AF_INET;   //IP协议簇
	addr.sin_addr.s_addr = inet_addr(ip.c_str());
	addr.sin_port = htons(port);
	//将主机字节序转化网络字节序
	ssize_t write_size = sendto(fd_,buf.data(),buf.size(),0,(sockaddr*)&addr,sizeof(addr));
    /*
         int sendto (int s, const void *buf, int len,unsigned int flags,
    const struct sockaddr *to, int tolen);
	  buf.data()---》返回一个字符串指针
	  buf.size()--->大小
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
