#progma once

//线程池任务队列
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
	//构造函数
	ThreadPool(int thr_num):_max_thr(thr_num),_stop_flag(false){
		pthread_mutex_init(&_mutex,NULL);
		pthread_cond_init(&_cond,NULL);
	}
	~ThreadPool(){  //销毁线程池
		pthread_mutex_destroy(&_mutex);
		pthread_cond_destroy(&_cond);
	}
	//线程创建
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
    //向线程池中添加任务
	bool PushTask(SyncQueue& Queue){
		pthread_mutex_lock(&_lock);
		//加锁，保证线程安全
		while(_stop_flag){
			pthread_mutex_unlock(&_lock);
		}
		_queue.push(Queue);
		pthread_cond_signal(&_empty);
		pthread_mutex_unlock(&_lock);  //添加队列完成，解锁
		return true;
	}
	//出队
	bool PopTask(SyncQueue& Queue){
		Queue = _queue.front();
		_queue.pop();
		return true;
	}
    //判断队列是否为空
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

    static void* thr_in(void* arg)   //线程入口函数(static防止this调用)
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
        tp->PopTask(st);  //出队使用
        pthread_mutex_unlock(&mutex);
        st.Run();
      }
    }
	private:
		int _max_thr;
		bool _stop_flag;
		std::queue<SyncTask> _queue;
		pthread_mutex_t _mutex;   //互斥
		pthread_cond_t _cond;    //同步
};
