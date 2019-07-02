//创建一个中英文翻译的服务器
//用户输入一个英文单词，返回一个翻译出来的中文结果
#include "udp_server.hpp"
#include<unordered_map>
//1.什么样的对象能放到vector中： a)能拷贝  b) 支持移动语义
//2.什么样的对象能放到list中：和vector相同
//3.什么样的对象能放到deque中：和vector相同
//4.什么样的对象能放到std::array中：和vector相同
//5.什么样的对象能放到std::set中：a）能拷贝  b）能够比较
//6.什么样的对象能放到std::map中: key a)能拷贝   b）能比较 value a)能拷贝
//7.什么样的对象能放到std::unordered_map : key a)能拷贝   b)能比较相等  c)能哈希 
//value  a)能拷贝
int main(){
      std::unordered_map<std::string,std::string> dict; 
      dict.insert(std::make_pair("hello","你好"));
      dict.insert(std::make_pair("world","世界"));
      dict.insert(std::make_pair("bit","比特"));
  UdpServer server; 
  server.Start("0.0.0.0",9090,[dict](const std::string& req,
        std::string* resp){
      auto it = dict.find(req);
      if(it == dict.end()){
        *resp = "未找到结果";
        }else{
        *resp = it->second;   //it->second表示值  it->first
        }
      });
  return 0;
}
