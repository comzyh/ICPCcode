#include <cstdio>
#include <cstring>
const int SIZE=100000+1;
int N,MAX;
int tab[SIZE],fl[SIZE],fr[SIZE];
int main()
{
	int i,j,k,sum,max;
	while (scanf("%d",&N),N)
	{
		
		for (i=1;i<=N;i++)
			scanf("%d",&tab[i]);
		//Left
		max=0x80000000;
		sum=0;
		for (i=1;i<=N;i++)
		{
			sum+=tab[i];
			if (sum>max)
				max=sum;
			fl[i]=max;
			if (sum<0)
				sum=0;
		}
		//Right
		max=0x80000000;
		sum=0;
		for (i=N;i>=1;i--)
		{
			sum+=tab[i];
			if (sum>max)
				max=sum;
			fr[i]=max;
			if (sum<0)
				sum=0;
		}
		//Scan
		/* for (i=1;i<=N;i++)
			printf("%4d ",fl[i]);
		printf("\n");
		for (i=1;i<=N;i++)
			printf("%4d ",fr[i]);
		printf("\n");
		for (i=1;i<N;i++)
			printf("%4d ",fl[i]+fr[i+1]);
		printf("\n"); */
		MAX=0x80000000;
		for (i=1;i<N;i++)
			if (fl[i]+fr[i+1]>MAX)
				MAX=fl[i]+fr[i+1];
		printf("%d\n",MAX);
	}
}
