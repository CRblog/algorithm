#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//ʹ�ù����ڴ����ͨ��

int main()
{
	//�������
	key_t key = 0;
	int shmid = 0;
	char * shmaddr = NULL;
	//�������Ҵ򿪹����ڴ�
	key = ftok("/", 13);
	if ( key < 0 )
	{
		perror("ftok error");
		return -1;
	}
	printf("key = 0x%x\r\n", key);
	//�󶨶���
	shmid = shmget( key, 1024, IPC_CREAT | 0666 );
	if ( shmid < 0 )
	{
		perror("shmget error");
		return -1;
	}

	printf("shmid = %d\r\n", shmid);
	//ӳ�乲���ڴ�
	shmaddr = (char *)shmat( shmid, NULL, 0 );
	if ( (void * )-1 == shmaddr )
	{
		perror("shm at error");
		shmctl( shmid , IPC_RMID, NULL );
		return -1;
	}
	//д���ݵ������ڴ�
	memset( shmaddr, 0, 1024 );
	memcpy( shmaddr, "shared memory ok", 50 );

	//���빲��
	shmdt( shmaddr );
	shmaddr = NULL;
	return 0;
}

