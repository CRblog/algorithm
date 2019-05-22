#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
int ticket = 100;
pthread_mutex_t mutex;  //定义互斥锁

void *ticket_grabbing(void *arg)
{
  while(1){
    pthread_mutex_lock(&mutex);   //加锁
 //   int pthread_mutex_lock(pthread_mutex_t *mutex
 //   阻塞加锁，加不上锁则阻塞
 //   int pthread_mutex_trylock(pthread_mutex_t *mutex);
 //   非阻塞加锁，加不上锁则直接报错返回
 //   pthread_mutex_lock;
 //   限时的阻塞加锁
    if(ticket > 0){
      usleep(1000);    //休眠1000微秒
      printf("bull %d---get a ticket:%d\n",(int)arg,ticket);
      ticket--;
      pthread_mutex_unlock(&mutex);
      //int pthread_mutex_unlock(pthread_mutex_t *mutex);

    }
    else{
      printf("from bull %d :have no tickets , exit\n",(int)arg);
      pthread_mutex_unlock(&mutex);   //加锁之后在任意有可能退出的地方都要解锁
      pthread_exit(NULL); //线程退出

    }
  }
  return NULL;
}

//互斥锁的初始化
int main()
{
   pthread_t tid[4];   //线程定义
   int ret,i;
    /*
     *
     * int pthread_mutex_init(pthread_mutex_t *restrict mutex,
     *                    const pthread_mutexattr_t *restrict attr);
     *  mutex:  互斥锁
     *  attr:   互斥锁属性，一般为NULL;
     *  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
     * */
   pthread_mutex_init(&mutex,NULL);
   for(i = 0;i<4;i++)
   {
     ret = pthread_create(&tid[i],NULL,ticket_grabbing,(void*)i);  //线程创建
     if(ret != 0)
     {
       printf("thread create error\n");   //返回值不为零：失败，返回-1
       return -1;
     }
   }
   for(i = 0;i<4;i++)
   {
     pthread_join(tid[i],NULL);
     //处于joinable状态的线程不会自动回收资源，需要调用pthread_join等待线程对出并进行资源回收
   }
   pthread_mutex_destroy(&mutex);
   return 0;
}

