#include<unordered_map>
#include"tcp_server.hpp"

int main()
{
  std::unordered_map<std::string,std::string> dict;
  dict.insert(std::make_pair("hello","你好")); 
  dict.insert(std::make_pair("everyone","所有人"));
  dict.insert(std::make_pair("byte","字节"));
  dict.insert(std::make_pair("tencent","腾讯"));
  TcpServer server;
    server.Start("0.0.0.0",9090,[&dict](const std::string& req,std::string* resp){
    auto it = dict.find(req);
    if(it == dict.end()){
      *resp = "未找到相应词汇";
    }
    else{
     *resp = it->second;
    }
  });
    return 0;
}
