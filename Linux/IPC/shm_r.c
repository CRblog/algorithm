#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//ʹ�ù����ڴ����ͨ��r

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

	shmid = shmget( key, 1024, IPC_CREAT | 0666 );
	//ӳ�乲���ڴ�
	shmaddr = (char *)shmat( shmid, NULL, 0);
	//�����ݴӹ����ڴ�
	printf("read:%s\r\n", shmaddr);
	
	//���빲��
	shmdt( shmaddr );
	
	//ɾ�������ڴ�
	shmctl(shmid, IPC_RMID,NULL);
	return 0;
}

