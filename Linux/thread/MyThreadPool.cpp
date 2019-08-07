#progma once

//�̳߳��������
class SyncTask{
	public:
	SyncTask():_cli_sock(-1){}
	SyncTask(int sock,Handler handler):_cli_sock(sock),_task(handler){
	}
	bool SetTask(){
		_cli_sock = sock;
		_task = handler;
		return true;
	}
	void Run()
	{
		_task(_cli_sock);
	}
	private:
		Handler _task;
		int sock;
		
};
class ThreadPool{
	//���캯��
	ThreadPool(int thr_num):_max_thr(thr_num),_stop_flag(false){
		pthread_mutex_init(&_mutex,NULL);
		pthread_cond_init(&_cond,NULL);
	}
	~ThreadPool(){  //�����̳߳�
		pthread_mutex_destroy(&_mutex);
		pthread_cond_destroy(&_cond);
	}
	//�̴߳���
	ThreadPoolCreate(){
		pthread_t tid;
		int i,ret;
		for(i = 0;i<max_thr;++i){
			ret = pthread_create(&tid,NULL,thrStart,(void*)this);
			if(ret!=0){
				std::cerr<<"pthread_create error"<<std::endl;
				return false;
			}
			pthread_detach(tid);
		}
	}
    //���̳߳����������
	bool PushTask(SyncQueue& Queue){
		pthread_mutex_lock(&_lock);
		//��������֤�̰߳�ȫ
		while(_stop_flag){
			pthread_mutex_unlock(&_lock);
		}
		_queue.push(Queue);
		pthread_cond_signal(&_empty);
		pthread_mutex_unlock(&_lock);  //��Ӷ�����ɣ�����
		return true;
	}
	//����
	bool PopTask(SyncQueue& Queue){
		Queue = _queue.front();
		_queue.pop();
		return true;
	}
    //�ж϶����Ƿ�Ϊ��
	bool queueIsEmpty(){
		return _queue.empty();
	}

	void idleThread(){
		if(_stop_flag)
		{
			pthread_mutex_unlock(&_mutex);
			_max_thr--;
			pthread_exit((void*)0);
			return ;
		}
		pthread_cont_wait(&_cond,&_mutex);
	}

	void Destory(){
      if(!_stop_flag)
        _stop_flag = true;

      while(_max_thr > 0)
        pthread_cond_broadcast(&_cond);
    }
    private:

    static void* thr_in(void* arg)   //�߳���ں���(static��ֹthis����)
    {
      ThreadPool* tp = (ThreadPool*)arg;
      while(1)
      {
        pthread_mutex_lock(&_mutex);
        while(tp->queueIsEmpty())
        {
          tp->IdleThread();
        }
        SyncTask st;
        tp->PopTask(st);  //����ʹ��
        pthread_mutex_unlock(&mutex);
        st.Run();
      }
    }
	private:
		int _max_thr;
		bool _stop_flag;
		std::queue<SyncTask> _queue;
		pthread_mutex_t _mutex;   //����
		pthread_cond_t _cond;    //ͬ��
};
