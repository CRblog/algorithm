#include<stdio.h>
int main()
{
	int e[10][10],k,i,j,n,m,t1,t2,t3;
	int inf=99999999;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j)    e[i][j]=0;  //i=j������
			else    e[i][j]=inf;    //���������Ϊ�����
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);//t1��t2��ȨֵΪt3
		e[t1][t2]=t3;
	}
	//����
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(e[i][j]>e[i][k]+e[k][j])
				//����ҵ��м�ֵ��ʹ����·����������ֵС��ֱ�ӵ���ֵ����ô���滻
					e[i][j]=e[i][k]+e[k][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
				printf("%10d",e[i][j]);
		printf("\n");
	return 0;
}
