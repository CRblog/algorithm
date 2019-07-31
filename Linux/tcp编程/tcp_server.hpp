#pragma once
#include<functional>
#include "tcp_socket.hpp"

#define CHECK_RET(exp) if(!(exp)) {\
  return false;\
}

typedef std::function<void (const std::string&,std::string*)> Handler;
class TcpServer
{
  private:
      TcpSocket listen_sock_;
public:
    TcpServer()
    {

    }
    bool Start(const std::string& ip,uint16_t port,Handler handler)
    {
    //1.����һ��socket
      CHECK_RET(listen_sock_.Socket());
    //2.�󶨶˿ں�
      CHECK_RET(listen_sock_.Bind(ip,port));
    //3.���м���
    CHECK_RET(listen_sock_.Listen());
    printf("Server Start OK\n");
    //4.������ѭ��
    while(true)
    {
        //5.ͨ��accept ��ȡ��һ������
        TcpSocket client_sock;
        std::string ip;
        uint16_t port;
        bool ret = listen_sock_.Accept(&client_sock,&ip,&port);
        if(!ret)
        {
          continue;
        }
        //6.�Ϳͻ��˽��о���Ĺ�ͨ
      while(true)
      {
        //a)��ȡ����
        std::string req;
        int r = client_sock.Recv(&req);
        if(r < 0)
        {
          continue;
        }
        if(r == 0)
        {
          //�Զ˹ر���socket
          client_sock.Close();
          printf("[%s:%d]�Զ˹ر�������\n",ip.c_str(),port);
          break;
        }
        printf("[%s:%d]�ͻ��˷�����:%s\n",ip.c_str(),port,req.c_str());
        //b)�������������Ӧ
        std::string resp;
        handler(req,&resp);
        //c)����Ӧд�ضԶ�
        client_sock.Send(resp);
      }
    }
    }
};

