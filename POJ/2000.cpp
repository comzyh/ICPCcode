#include <cstdio>
const int MAX=10000;
int sum[10005];
int T;
int main()
{
	int i,j,k;
	i=0;
	sum[0]=0;
	for (k=1;i<MAX;k++)
	{
		for (j=1;j<=k && i<MAX;j++)
		{
			i++;
			if (i>MAX)continue;
			sum[i]=sum[i-1]+k;
		}
	}
	while (scanf("%d",&T),T!=0)
	{
		printf("%d %d\n",T,sum[T]);
	}
	return 0;
}
