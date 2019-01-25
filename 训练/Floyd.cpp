#include<stdio.h>
int main()
{
	int e[10][10],k,i,j,n,m,t1,t2,t3;
	int inf=99999999;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j)    e[i][j]=0;  //i=j则置零
			else    e[i][j]=inf;    //不相等则置为无穷大
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);//t1到t2的权值为t3
		e[t1][t2]=t3;
	}
	//核心
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(e[i][j]>e[i][k]+e[k][j])
				//如果找到中间值，使两个路径加起来的值小于直接到的值，那么就替换
					e[i][j]=e[i][k]+e[k][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
				printf("%10d",e[i][j]);
		printf("\n");
	return 0;
}
