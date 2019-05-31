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

#define MAX_QUEUE 10          //最大节点

class BlockQueue
{
    public:
      BlockQueue(int cap = MAX_QUEUE):_capacity(cap) {
        pthread_mutex_init(&_mutex,NULL);
        pthread_cond_init(&_cond_con,NULL);
        pthread_cond_init(&_cond_pro,NULL);
      }
      ~BlockQueue(){
      pthread_mutex_destroy(&_mutex);      //销毁锁
      pthread_cond_destroy(&_cond_con);   //消费者销毁
      pthread_cond_destroy(&_cond_pro);   //生产者销毁
      }
      void QueuePush(int data){         //入队列
        QueueLock();                    //操作前先加锁
        while(QueueIsFull())       //首先判断队列有没有满，满了的话就需要生产者一直等待
		{
          ProWait();
        }
        _queue.push(data);          //如果没满，就开始生产，将数据入队
        ConWakeUp();               //操作完成，唤醒消费者
        QueueUnLock();             //解锁
      }
      void QueuePop(int *data){          //出队列的情况
        QueueLock();                 //执行之前加锁
        while(QueueIsEmpty()){     //队列为空就先等待
          ConWait();
        }
        *data = _queue.front();   //不为空-->将数据保存下来，出队列
        _queue.pop();
        ProWakeUp();     //唤醒生产者（需要生产产品了）
        QueueUnLock();   //解锁


      }
    private:
      void QueueLock(){            //加锁
        pthread_mutex_lock(&_mutex);
      }
      void QueueUnLock(){           //解锁
        pthread_mutex_unlock(&_mutex);
      }
      void ConWait(){              //消费者等待
        pthread_cond_wait(&_cond_con,&_mutex);
      }
      void ConWakeUp(){                   //唤醒消费者
        pthread_cond_signal(&_cond_con);
      }
      void ProWait(){                       //生产者等待
        pthread_cond_wait(&_cond_pro,&_mutex);
      }
      void ProWakeUp(){       //唤醒生产者
        pthread_cond_signal(&_cond_pro);
      }
      bool QueueIsFull(){          //判断队列是否满了
        return (_capacity == _queue.size());// 容量等于元素大小则表示队列满了
      }
      bool QueueIsEmpty(){               //判断队列是否为空
        return _queue.empty();
      }
    private:
      queue<int> _queue;              //定义队列
      int _capacity;                  //队列节点的最大数量
      pthread_mutex_t _mutex;        //定义锁
      pthread_cond_t _cond_pro;      //定义生产者
      pthread_cond_t _cond_con;      //定义消费者
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
      cout<<"pthread create error"<<endl;
      return -1;
    }
  }
  for(i = 0;i<4;i++)
  {
    ret = pthread_create(&ptid[i],NULL,thr_productor,(void*)&q);
    if(ret!=0){
      cout<<"pthread create error"<<endl;
      return -1;
    }
  }
  for(i = 0;i<4;i++){
    pthread_join(ctid[i],NULL);
  }
  for(i=0;i<4;i++)
  {
    pthread_join(ptid[i],NULL);
  }
  return 0;
}

