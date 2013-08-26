#include <cstdio>
#include <cstring>
int sum[101][101];
int N,MAX;
int main()
{
	int i,j,x;
	scanf("%d",&N);
	memset(sum,0,sizeof(sum));
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
		{
			scanf("%d",&x);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+x;
		}
	if (0)
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=N;j++)	
			printf("%4d",sum[i][j]);
		printf("\n");
	}
	int x1,y1,x2,y2,s;
	MAX=-999999999;
	for (x1=1;x1<=N;x1++)
		for (y1=1;y1<=N;y1++)
			for (x2=x1;x2<=N;x2++)
				for (y2=y1;y2<=N;y2++)
				{
					s=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
					if (s>MAX)
						MAX=s;
				}
	printf("%d\n",MAX);
}
