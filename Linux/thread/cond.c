/*
 * 条件变量：
 *
 *
 * */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int have_noodle = 0;
pthread_cond_t cond;
pthread_mutex_t mutex;
void *eat_noodle(void *arg)
{
      //因为条件不满足陷入休眠，另一方促使条件满足，因此条件也是一个临界资源，需要受保护
  while(1){
    pthread_mutex_lock(&mutex);
    if(have_noodle == 0){
      //因为没有面，不满足吃的条件，所以等待
      //

      //但是如果条件不满足陷入休眠，休眠之前就必须解锁，因为不解锁
      //另一方就无法修改条件，因此先解锁再休眠
      //但是如果解锁和休眠并非原子操作，另一方有可能获取到锁并且做了一碗面，进行唤醒，
      //关键是这边还没来得及陷入休眠，导致白唤醒了一次，等到cpu轮转回来的时候，陷入休眠，
      //不会再有第二次唤醒程序卡死
      //因此解锁和休眠必须是原子操作
      pthread_cond_wait(&cond,&mutex);//此时条件变量和锁一起使用了，因为需要保证原子操作
      // 上面函数中集合了三步操作，分别是：解锁，休眠，加锁操作
    }
    printf("delicious~~~~~~\n");
    have_noodle = 0;
    //int pthread_cond_broadcast(pthread_cond_t *cond);
    //唤醒所有等待
    //int pthread_cond_signal(pthread_cond_t *cond);
    //至少唤醒一个等待
    pthread_cond_signal(&cond); //唤醒
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}
void *make_noodle(void *arg)
{
  while(1){
    pthread_mutex_lock(&mutex);
    if(have_noodle==1)
    {
      //已经有面了，所以等待
      pthread_cond_wait(&cond,&mutex);
    }
    printf("make~~~~~~\n");
    have_noodle = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}



int main(int argc,char *argv[])
{
  pthread_t etid,mtid;
  /*
   *int pthread_cond_init(pthread_cond_t *restrict cond,
                 const pthread_condattr_t *restrict attr);
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
  cond:   条件变量
attr:     条件变量属性，通常置空
   * */
  pthread_cond_init(&cond,NULL);
  pthread_mutex_init(&mutex,NULL);
  int ret;
  ret = pthread_create(&etid,NULL,eat_noodle,NULL);
  if(ret!=0)
  {
    printf("thread create error\n");
    return -1;
  }
  ret = pthread_create(&mtid,NULL,make_noodle,NULL);
  if(ret!=0){
    printf("thread create error\n");
    return -1;
  }
  pthread_join(etid,NULL);
  pthread_join(mtid,NULL);
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);
  return 0;
}

