#include <cstdio>
#include <cstring>
#define max(a,b) ((a)>(b)?(a):(b))
int num[101][101],sum[101][101];
int N;
int main()
{
	int i,j;
	scanf("%d",&N);
	for (i=1;i<=N;i++)
		for (j=1;j<=i;j++)
			scanf("%d",&num[i][j]);
	memset(sum,0,sizeof(sum));
	for (i=1;i<=N;i++)
		for (j=1;j<=i;j++)
			sum[i][j]=num[i][j]+max(sum[i-1][j-1],sum[i-1][j]);
	int ans=0;
	for (i=1;i<=N;i++)
		if (sum[N][i]>ans)ans=sum[N][i];
	printf("%d",ans);
}
