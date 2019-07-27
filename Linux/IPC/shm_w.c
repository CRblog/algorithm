#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//使用共享内存进行通信

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
	//绑定对象
	shmid = shmget( key, 1024, IPC_CREAT | 0666 );
	if ( shmid < 0 )
	{
		perror("shmget error");
		return -1;
	}

	printf("shmid = %d\r\n", shmid);
	//映射共享内存
	shmaddr = (char *)shmat( shmid, NULL, 0 );
	if ( (void * )-1 == shmaddr )
	{
		perror("shm at error");
		shmctl( shmid , IPC_RMID, NULL );
		return -1;
	}
	//写数据到共享内存
	memset( shmaddr, 0, 1024 );
	memcpy( shmaddr, "shared memory ok", 50 );

	//分离共享
	shmdt( shmaddr );
	shmaddr = NULL;
	return 0;
}

