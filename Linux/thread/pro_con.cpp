/*
 *��������������ģ��
 ʵ�֣�
 1.ʵ���̰߳�ȫ�Ķ��У������ṩ�̰߳�ȫ��������Ӻͳ��Ӳ���
 2.�����̣߳��ֱ���Ϊ��������������������ӻ����ݳ���
 *
 * */
#include<iostream>
#include<queue>
#include<pthread.h>
using namespace std;

#define MAX_QUEUE 10          //���ڵ�

class BlockQueue
{
    public:
      BlockQueue(int cap = MAX_QUEUE):_capacity(cap) {
        pthread_mutex_init(&_mutex,NULL);
        pthread_cond_init(&_cond_con,NULL);
        pthread_cond_init(&_cond_pro,NULL);
      }
      ~BlockQueue(){
      pthread_mutex_destroy(&_mutex);      //������
      pthread_cond_destroy(&_cond_con);   //����������
      pthread_cond_destroy(&_cond_pro);   //����������
      }
      void QueuePush(int data){         //�����
        QueueLock();                    //����ǰ�ȼ���
        while(QueueIsFull())       //�����ж϶�����û���������˵Ļ�����Ҫ������һֱ�ȴ�
		{
          ProWait();
        }
        _queue.push(data);          //���û�����Ϳ�ʼ���������������
        ConWakeUp();               //������ɣ�����������
        QueueUnLock();             //����
      }
      void QueuePop(int *data){          //�����е����
        QueueLock();                 //ִ��֮ǰ����
        while(QueueIsEmpty()){     //����Ϊ�վ��ȵȴ�
          ConWait();
        }
        *data = _queue.front();   //��Ϊ��-->�����ݱ���������������
        _queue.pop();
        ProWakeUp();     //���������ߣ���Ҫ������Ʒ�ˣ�
        QueueUnLock();   //����


      }
    private:
      void QueueLock(){            //����
        pthread_mutex_lock(&_mutex);
      }
      void QueueUnLock(){           //����
        pthread_mutex_unlock(&_mutex);
      }
      void ConWait(){              //�����ߵȴ�
        pthread_cond_wait(&_cond_con,&_mutex);
      }
      void ConWakeUp(){                   //����������
        pthread_cond_signal(&_cond_con);
      }
      void ProWait(){                       //�����ߵȴ�
        pthread_cond_wait(&_cond_pro,&_mutex);
      }
      void ProWakeUp(){       //����������
        pthread_cond_signal(&_cond_pro);
      }
      bool QueueIsFull(){          //�ж϶����Ƿ�����
        return (_capacity == _queue.size());// ��������Ԫ�ش�С���ʾ��������
      }
      bool QueueIsEmpty(){               //�ж϶����Ƿ�Ϊ��
        return _queue.empty();
      }
    private:
      queue<int> _queue;              //�������
      int _capacity;                  //���нڵ���������
      pthread_mutex_t _mutex;        //������
      pthread_cond_t _cond_pro;      //����������
      pthread_cond_t _cond_con;      //����������
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

