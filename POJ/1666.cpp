#include <cstdio>
#include <cstring>
int N,ANS;
int can[10000],add[10000];
int main()
{
	int i,j,min,max;
	while (scanf("%d",&N),N)
	{
		min=0x7fffffff;
		max=0;
		for (i=1;i<=N;i++)
		{
			scanf("%d",&can[i]);
			if (can[i]>max)max=can[i];
			if (can[i]<min)min=can[i];
		}
		ANS=0;
		while (max!=min)
		{
			for (i=1;i<=N;i++)
			{
				can[i]>>=1;
				add[(i%N)+1]=can[i];
			}
			min=0x7fffffff;
			max=0;
			for (i=1;i<=N;i++)
			{
				can[i]+=add[i];
				if (can[i]& 1)can[i]++;
				if (can[i]>max)max=can[i];
				if (can[i]<min)min=can[i];
			}
			ANS++;
		}
		printf("%d %d\n",ANS,can[1]);
	}
}
