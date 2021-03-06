2019 04  10
系统编程
进程概念：
    冯诺依曼体系结构--现代计算机硬件体系结构
        计算机五大硬件单元：
			输入设备，
			输出设备，
			存储器，
			运算器，
			控制器
    操作系统：一个软件安装在计算机硬件上
        目的：为了让计算机更加好用--功能：合理统筹管理计算机上的软硬件资源
        管理：先描述，再组织
    进程概念---
        进行中的程序
                在操作系统角度，操作系统通过PCB来控制一个进程的运行，这个pcb叫进程描述符
            描述了一个运行的程序，在操作系统角度，进程就是pcb-task_struct
            
            PCB：内存指针，程序计数器，上下文数据，标识符PID，进程状态，优先级，IO状态信息
                记账信息（进程运行时间），
            
		CPU分时机制：切换调度进程，每个进程只运行很短一段时间（时间片）
		交互式进程：和用户交互的程序
		批处理进程：后台自主运行程序
	进程查看：
     		ps -ef  aux   查看所有进程信息
     		/proc          保存系统中正在运行的程序信息
     		pid_t getpid() 获取调用进程的pid
    进程创建
		fork() -create a child process//创建一个子进程
              通过复制调用进程(父进程)创建一个新的进程(子进程)
              复制：复制了父进程的PCB，意味着和父进程拥有一样的内存指针，程序计数器，上下文数据。
                    和父进程运行相同的代码，相同的运行位置，处理一样的数据
                父子进程代码共享，数据独有
            创建一个子进程的意义：
                1.分摊父进程的压力,CPU资源足够的情况父子进程同时处理数据，效率高
                2.处理其他事务（通过返回值进行代码分流）
            如何分辨父子进程：
                父进程：返回子进程的pid，pid>0
                子进程：返回0
                失败：返回-1
    进程状态:就绪，运行，阻塞
		linux进程状态:
			运行态(R):
            可中断睡眠态(S):
            不可中断睡眠态(D):等待调用过程就是一个不可中断的睡眠态
            停止态(T):
            僵死态(Z):
            死亡态(X):进程退出后
            追踪态(t):
            僵尸进程：处于僵死态的进程---进程退出后，资源没有完全释放(没有完全退出)
            僵尸进程如何产生：子进程先于父进程退出，将自己的退出原因保存在pcb中，操作系统检测到子进程退出，
        因为父进程有可能关注退出原因，所以不能随意释放所有资源，通知父进程子进程的退出，但这时候
        父进程可能正在处理事务，没有关注到这个通知，导致子程序退出了，但是资源一直没有完全释放，处于僵死状态，成为僵尸进程
            僵尸进程的危害：资源泄露，一个用户能够创建的进程是有限的，可能导致新进程创建失败
            处理：杀掉父进程
            如何避免：进程等待
            孤儿进程：父进程先于子进程退出，子进程成为孤儿进程，运行在后台,父进程成为1号进程
            守护进程/精灵进程：特殊的孤儿进程
		kill kid //杀死进程(非停止态)
		kill -9 kid //强制杀死进程

    
    进程优先级
    环境变量
    程序地址空间
    进程的O(1)调度算法
