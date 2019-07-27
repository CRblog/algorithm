#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//使用共享内存进行通信r

int main()
{
	//定义变量
	key_t key = 0;
	int shmid = 0;
	char * shmaddr = NULL;

	//创建并且打开共享内存
	key = ftok("/", 13);
	if ( key < 0 )
	{
		perror("ftok error");
		return -1;
	}
	printf("key = 0x%x\r\n", key);

	shmid = shmget( key, 1024, IPC_CREAT | 0666 );
	//映射共享内存
	shmaddr = (char *)shmat( shmid, NULL, 0);
	//读数据从共享内存
	printf("read:%s\r\n", shmaddr);
	
	//分离共享
	shmdt( shmaddr );
	
	//删除共享内存
	shmctl(shmid, IPC_RMID,NULL);
	return 0;
}

