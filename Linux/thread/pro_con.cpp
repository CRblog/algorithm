/*
 *生产者与消费者模型
 实现：
 1.实现线程安全的队列，对外提供线程安全的数据入队和出队操作
 2.创建线程，分别作为生产者与消费者数据入队或数据出队
 *
 * */
#include<iostream>
#include<queue>
#include<pthread.h>
using namespace std;

#define MAX_QUEUE 10

class BlockQueue
{
    public:
      BlockQueue(int cap = MAX_QUEUE):_capacity(cap) {
        pthread_mutex_init(&_mutex,NULL);
        pthread_cond_init(&_cond_con,NULL);
        pthread_cond_init(&_cond_pro,NULL);
      }
      ~BlockQueue(){
      pthread_mutex_destroy(&_mutex);
      pthread_cond_destroy(&_cond_con);
      pthread_cond_destroy(&_cond_pro);
      }
      void QueuePush(int data){      
        QueueLock();
        while(QueueIsFull()){
          ProWait();
        }
        _queue.push(data);
        ConWakeUp();
        QueueUnLock();
      }
      void QueuePop(int *data){
        QueueLock();
        while(QueueIsEmpty()){
          ConWait();
        }
        *data = _queue.front();
        _queue.pop();
        ConWakeUp();
        QueueUnLock();


      }
    private:
      void QueueLock(){
        pthread_mutex_lock(&_mutex);
      }         //加锁
      void QueueUnLock(){
        pthread_mutex_unlock(&_mutex);
      }       //解锁
      void ConWait(){
        pthread_cond_wait(&_cond_con,&_mutex);
      }           //消费者等待
      void ConWakeUp(){
        pthread_cond_signal(&_cond_con);
      }         //唤醒消费者
      void ProWait(){
        pthread_cond_wait(&_cond_pro,&_mutex);
      }           //生产者等待
      void ProWakeUp(){
        pthread_cond_signal(&_cond_pro);
      }         //唤醒生产者
      bool QueueIsFull(){
        return (_capacity == _queue.size());// 容量等于元素大小则表示队列满了
      }       //判断队列是否满了
      bool QueueIsEmpty(){
        return _queue.empty();
      }      //判断队列是否为空
    private:
      queue<int> _queue;
      int _capacity;
      pthread_mutex_t _mutex;
      pthread_cond_t _cond_pro;
      pthread_cond_t _cond_con;
};
void *thr_consumer(void *arg)
{
  BlockQueue *q = (BlockQueue*)arg;
  while(1)
  {
    int data;
    q->QueuePop(&data);
    cout<<"consummer get data:"<<data<<endl;
  }
  return NULL;

}
int i = 0;
pthread_mutex_t mutex;
void *thr_productor(void *arg){
  BlockQueue *q = (BlockQueue*)arg;
  pthread_mutex_init(&mutex,NULL);
  while(1){
    pthread_mutex_lock(&mutex);
    q->QueuePush(i++);
    cout<<"productor:"<<pthread_self()<<" put data:"<<i<<endl;
    pthread_mutex_unlock(&mutex);

  }
  return NULL;
}
int main(int argc,char *argv[])
{
  BlockQueue q;
  pthread_t ctid[4],ptid[4];
  int i,ret;
  pthread_mutex_init(&mutex,NULL);
  for(i = 0;i<4;i++){
    ret = pthread_create(&ctid[i],NULL,thr_consumer,(void*)&q);
    if(ret!=0)
    {
      cout<<"pthread create error\n";
      return -1;
    }
  }
  for(i = 0;i<4;i++)
  {
    ret = pthread_create(&ptid[i],NULL,thr_productor,(void*)&q);
    if(ret!=0){
      cout<<"pthread create error\n";
      return -1;
    }
  }
  for(i=0;i<4;i++){
    pthread_join(ctid[i],NULL);
  }
  for(i=0;i<4;i++)
  {
    pthread_join(ptid[i],NULL);
  }
  return 0;
}
