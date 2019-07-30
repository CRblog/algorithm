//udp_server

//���̣�
//1.����socket
//2.�󶨵�ַ��Ϣ���˿ڣ�ipȷ�����Ա��ڿͻ����ܹ����ӵ�ָ���ķ�����
//3.������ѭ����ѭ�����գ�recvfrom
//4.sendto--->��Ӧ�ͻ��˷�������Ϣ
//5.�ر�socket
#pragma once
#include "udp_socket.hpp"
#include<functional>

typedef std::function<void (const std::string&,std::string* resp)> Handler;
//typedef void (*Handler)(const std::string& req,std::string* resp);

class UdpServer{
public:
	UdpServer()
	{
		assert(sock_.Socket());//����socket
	}
   ~UdpServer()
	{
		sock_.Close();
	}
bool Start(const std::string& ip,uint16_t port,Handler handler){
	//1.����socket
	//2.�󶨶˿ں�
	bool ret = socket_Bind(ip,port);
	//�󶨵�ַ��Ϣ
	if(!ret){
		return false;
	}
	//3.�����¼�ѭ��
	for(;;){
		//4.ѭ����������()
		std::string req;
		std::string remote_ip;
		uint16_t remote_port = 0;

		bool ret = sock_.RecvFrom(&req,&remote_ip,&remote_port);
		//��������
		if(!ret){
			continue;
		}
		std::string resp;
		//5.�������������Ӧ����Ӧ�Ĵ���
		handler(req,&resp);

		//6.������Ӧ���ͻ���
		sock_.SendTo(resp,remote_ip,remote_port);
		printf("[%s:%d] req: %s \n",remote_ip.c_str(),remote_port,
			req.c_str(),resp.c_str());
	}
	sock_.Close();
	//�ر�����
	return true;
}
private:
	UdpSocket sock_;

};


