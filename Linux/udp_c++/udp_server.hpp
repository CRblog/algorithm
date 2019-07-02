#pragma once 
#include<cassert>
#include<functional>
#include"udp_socket.hpp"

//通用的Udp服务器
//1.读取请求
//2.根据请求计算响应
//3.把响应写回到客户端
//typedef void(*Handler)(const std::string& req,
//              std::string* resp);
//c++11---兼容仿函数和函数指针
typedef std::function<void(const std::string&,std::string*)> Handler;

class UdpServer{
public:
  UdpServer(){
    assert(sock_.Socket());

  }
  ~UdpServer(){

  }
  bool Start(const std::string& ip,uint16_t port,
      Handler handler){
    //1.创建socket（上面已经完成）
    //2.绑定端口号
    bool ret = sock_.Bind(ip,port);
    if(!ret){
      return false;
    }

    //3.进入一个死循环
    while(true){
      //处理每个请求
      //1）读取请求
      std::string req;
      std::string peer_ip;
      uint16_t peer_port;
      sock_.RecvFrom(&req,&peer_ip,&peer_port);
      //2）根据请求计算响应
      std::string resp;
      handler(req,&resp);
      //3）把响应返回客户端
      sock_.SendTo(resp,peer_ip,peer_port);
    }

  }
  
private:
  UdpSocket sock_;
};