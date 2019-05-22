/*
 * ����������
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
      //��Ϊ�����������������ߣ���һ����ʹ�������㣬�������Ҳ��һ���ٽ���Դ����Ҫ�ܱ���
  while(1){
    pthread_mutex_lock(&mutex);
    if(have_noodle == 0){
      //��Ϊû���棬������Ե����������Եȴ�
      //

      //������������������������ߣ�����֮ǰ�ͱ����������Ϊ������
      //��һ�����޷��޸�����������Ƚ���������
      //����������������߲���ԭ�Ӳ�������һ���п��ܻ�ȡ������������һ���棬���л��ѣ�
      //�ؼ�����߻�û���ü��������ߣ����°׻�����һ�Σ��ȵ�cpu��ת������ʱ���������ߣ�
      //�������еڶ��λ��ѳ�����
      //��˽��������߱�����ԭ�Ӳ���
      pthread_cond_wait(&cond,&mutex);//��ʱ������������һ��ʹ���ˣ���Ϊ��Ҫ��֤ԭ�Ӳ���
      // ���溯���м����������������ֱ��ǣ����������ߣ���������
    }
    printf("delicious~~~~~~\n");
    have_noodle = 0;
    //int pthread_cond_broadcast(pthread_cond_t *cond);
    //�������еȴ�
    //int pthread_cond_signal(pthread_cond_t *cond);
    //���ٻ���һ���ȴ�
    pthread_cond_signal(&cond); //����
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
      //�Ѿ������ˣ����Եȴ�
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
  cond:   ��������
attr:     �����������ԣ�ͨ���ÿ�
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

