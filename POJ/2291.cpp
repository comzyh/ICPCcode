#include <cstdio>
#include <cstring>
#include <iostream>
int T,N;
int rope[1001];
void qsort(int b,int e);
int main()
{
	int i,MAX;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		for (i=1;i<=N;i++)
			scanf("%d",&rope[i]);
		qsort(1,N);
		MAX=0;
		for (i=1;i<=N;i++)
		{
			if (rope[i]*i > MAX)
				MAX=rope[i]*i;
		}
		printf("%d\n",MAX);
	}
}
void qsort(int b,int e)
{
	int i=b,j=e,k=rope[(b+e)>>1];
	while (i<j)
	{
		while (rope[i]>k)i++;
		while (rope[j]<k)j--;
		if (i<=j)
		{
			std::swap(rope[i],rope[j]);
			i++;
			j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}
