#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
int ticket = 100;
pthread_mutex_t mutex;  //���廥����

void *ticket_grabbing(void *arg)
{
  while(1){
    pthread_mutex_lock(&mutex);   //����
 //   int pthread_mutex_lock(pthread_mutex_t *mutex
 //   �����������Ӳ�����������
 //   int pthread_mutex_trylock(pthread_mutex_t *mutex);
 //   �������������Ӳ�������ֱ�ӱ�����
 //   pthread_mutex_lock;
 //   ��ʱ����������
    if(ticket > 0){
      usleep(1000);    //����1000΢��
      printf("bull %d---get a ticket:%d\n",(int)arg,ticket);
      ticket--;
      pthread_mutex_unlock(&mutex);
      //int pthread_mutex_unlock(pthread_mutex_t *mutex);

    }
    else{
      printf("from bull %d :have no tickets , exit\n",(int)arg);
      pthread_mutex_unlock(&mutex);   //����֮���������п����˳��ĵط���Ҫ����
      pthread_exit(NULL); //�߳��˳�

    }
  }
  return NULL;
}

//�������ĳ�ʼ��
int main()
{
   pthread_t tid[4];   //�̶߳���
   int ret,i;
    /*
     *
     * int pthread_mutex_init(pthread_mutex_t *restrict mutex,
     *                    const pthread_mutexattr_t *restrict attr);
     *  mutex:  ������
     *  attr:   ���������ԣ�һ��ΪNULL;
     *  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
     * */
   pthread_mutex_init(&mutex,NULL);
   for(i = 0;i<4;i++)
   {
     ret = pthread_create(&tid[i],NULL,ticket_grabbing,(void*)i);  //�̴߳���
     if(ret != 0)
     {
       printf("thread create error\n");   //����ֵ��Ϊ�㣺ʧ�ܣ�����-1
       return -1;
     }
   }
   for(i = 0;i<4;i++)
   {
     pthread_join(tid[i],NULL);
     //����joinable״̬���̲߳����Զ�������Դ����Ҫ����pthread_join�ȴ��̶߳Գ���������Դ����
   }
   pthread_mutex_destroy(&mutex);
   return 0;
}

