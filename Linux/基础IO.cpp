


		为什么用虚拟地址空间+页表： 保持进程独立性+充分利用内存+内存访问控制
		段页式内存管理              段式内存管理           页式内存管理
		段号+段内页号+页内偏移		段号+段内地址          页号+页内偏移
进程调度O(1)算法：
进程控制：
		进程创建：
			fork()   复制/返回值
			vfork()	 父子共用虚拟地址空间，子进程先运行，退出或者替换后父进程开始运行
							main中  return    释放资源
		进程终止：
			场景：正常退出，结果不符合预期
				  正常退出，结果符合预期
				  异常退出
			终止方式：main ->return   exit()   _exit()
			errno
		进程等待：
				等待子进程退出----避免出现僵尸进程+获取子进程返回值
				wait(int *)  waitpid(int,int *,int opt)  --WNOHANG（将阻塞设置成非阻塞）
				阻塞:	发起调用完成功能，但是如果当前不具备完成功能的条件，则一直等待直到完成后返回
				非阻塞:不具备条件就直接返回
				获取子进程返回值：statu格式
				---低16位中的高8位存储子进程返回值
				---低16位中的低8位中的高1位存储core dump标志  低7位存储异常信号值
		程序替换：替换一个进程正在运行的程序，让进程的虚拟地址空间映射到内存中的另一个程序的代码和数据位置-->
				让子进程执行其他任务(让子进程背锅，自己运行的更稳定)
				execl			execlp      execle
				execv			execvp      execve
				l和v的区别：传参的区别，
				··
						l是程序运行参数使用函数的实参平铺的形式赋予  execl(ls,ls,-l,-a,NULL)
						v是程序运行参数使用字符串指针数组赋予，     argv[0] = ls argv[1] = -1  execl(ls,argv);

				带p和不带p的区别：

					带P：程序名称可以不带路径，直接去PATH环境变量所指定的路径下找程序
						execlp(ls,...)
					不带P：程序名称必须带路径   execl(/bin/ls,...);

				d带e与不带e的区别：

					带e：给进程自定义环境变量       env[0] = "myenv = 100"execle(ls,...,NULL,env)
					不带e：继承原有默认的环境变量   execl(ls,...)


	自主实现一个shell---minishell
			shell:命令行解释器----解释执行用户的输入(完成相应的功能)
			1.获取标准输入中的字符串
			2.对字符串进行解析[ ls -l -a ]
			3.创建子进程
			4.	子进程中进行程序替换
				父进程进行进程等待     ---避免僵尸进程
	基础IO:输入输出---
		回顾标准库IO接口:FILE* ---文件流指针
		系统调用的IO接口学习：int  ---文件描述符
		文件描述符和文件流指针之间的关系
		文件描述符到底是什么---凭什么操作文件



		文件系统---Linux下的ext2
		软链接/硬链接
		静态库/动态库：生成，使用

		回顾标准库IO接口：fopen   fclose   fread    fwrite    fseek(跳转读写位置)
		fgets    printf/fprintf/sprintf           sprintf:可以拼接字符串

		系统调用的IO接口: open close write read   lseek
		文件流指针和文件描述符的关系：
			文件流指针是标准库操作句柄：FILE
			文件描述符是系统调用接口句柄:int
			库函数和系统调用接口的关系？	库函数封装了系统调用接口

			fp = fopen   ->fwrite(fp)


		缓冲区的探讨：

