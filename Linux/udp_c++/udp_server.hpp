//udp_server

//过程：
//1.创建socket
//2.绑定地址信息，端口，ip确定，以便于客户端能够连接到指定的服务器
//3.进入主循环，循环接收，recvfrom
//4.sendto--->响应客户端发来的信息
//5.关闭socket
#pragma once
#include "udp_socket.hpp"
#include<functional>

typedef std::function<void (const std::string&,std::string* resp)> Handler;
//typedef void (*Handler)(const std::string& req,std::string* resp);

class UdpServer{
public:
	UdpServer()
	{
		assert(sock_.Socket());//创建socket
	}
   ~UdpServer()
	{
		sock_.Close();
	}
bool Start(const std::string& ip,uint16_t port,Handler handler){
	//1.创建socket
	//2.绑定端口号
	bool ret = socket_Bind(ip,port);
	//绑定地址信息
	if(!ret){
		return false;
	}
	//3.进入事件循环
	for(;;){
		//4.循环接收请求()
		std::string req;
		std::string remote_ip;
		uint16_t remote_port = 0;

		bool ret = sock_.RecvFrom(&req,&remote_ip,&remote_port);
		//接收请求
		if(!ret){
			continue;
		}
		std::string resp;
		//5.根据请求计算响应（响应的处理）
		handler(req,&resp);

		//6.返回响应给客户端
		sock_.SendTo(resp,remote_ip,remote_port);
		printf("[%s:%d] req: %s \n",remote_ip.c_str(),remote_port,
			req.c_str(),resp.c_str());
	}
	sock_.Close();
	//关闭连接
	return true;
}
private:
	UdpSocket sock_;

};


