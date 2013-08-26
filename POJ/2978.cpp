#include <cstdio>
#include <cstring>
int pr[100001],sum[100001];
int A,B;
int main()
{
	int i,j;
	memset(pr,0,sizeof(pr));
	for (i=2;i<=100000;i++)
	{
		while (pr[i])i++;
		for (j=2;(double)i*j<=(double)100000;j++)
			pr[i*j]=1;
	}
	sum[0]=sum[1]=sum[2]=0;
	for (i=2;i<=100000;i++)
		if (pr[i])
			sum[i]=sum[i-1];
		else
			sum[i]=sum[i-1]+1;
	while (scanf("%d%d",&A,&B),!(A==-1 && B==-1))
	{
		if (A<=0)A=1;
		if (B<=0)B=1;
		printf("%d\n",sum[B]-sum[A-1]);
	}
}
