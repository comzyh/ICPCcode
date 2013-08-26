#include <cstdio>
int pri[100000],sum[100000];
int main()
{
	int i,j;
	for (i=2;i<=9999;i++)
	if (!pri[i])
	{
		for (j=2;i*j<=9999;j++)
			pri[i*j]=1;
	}
	sum[1]=sum[0]=0;
	for (i=2;i<=9999;i++)
	if (!pri[i])
		sum[i]=sum[i-1]+1;
	else
		sum[i]=sum[i-1];
	int a,b;
	while (scanf("%d%d",&a,&b),a!=-1 && b!=-1)
	{
		if (a<1)
			a=1;
		if (b<1)
			b=1;
		printf("%d\n",sum[b]-sum[a-1]);
	}
}