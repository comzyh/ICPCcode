#include <cstdio>
#include <cstring>
#include<algorithm>
int N;
int L[100],SUM,MAX,MIN;
int H[100],M,K;
int used[100];
int DFS(int k,int b,int bb);
void qsort(int b,int e);
int stack[100];
inline void pri(int x)
{
	for (int i=N;i>=x;i--)
		printf("%d ",L[stack[i]]);
	printf("\n");
}
int main()
{
	int i,j;
	while (scanf("%d",&N),N)
	{
		MAX=SUM=0;
		MIN=0x3fffffff;
		for (i=1;i<=N;i++)
		{
			scanf("%d",&L[i]);
			SUM+=L[i];
			if (L[i]>MAX)
				MAX=L[i];
			if (L[i]<MIN)
				MIN=L[i];
		}
		std::sort(L+1,L+N+1);
		for (i=MAX;i<=SUM;i++)
		if (SUM % i ==0)
		{
			memset(H,0,sizeof(H));
			memset(used,0,sizeof(used));
			M=i;
			K=SUM/i;
			if(DFS(N,1,N))
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}
int DFS(int k,int b,int bb)
{
	if (k==0)
		return 1;
	for (int i=bb;i>=1;i--)
	if (!used[i]  && L[i]<=M-H[b] )
	{
		used[i]=1;
		H[b]+=L[i];
		stack[k]=i;
		if (H[b]==M)
		{
			//printf("b=%d,k=%d\n",b,k);
			//pri(k);
			if (DFS(k-1,b+1,N))	
			return 1;
		}
		else
			if (DFS(k-1,b,i-1))
				return 1;
		used[i]=0;
		H[b]-=L[i];
		if (H[b]==0)
			break;
		//while (L[i-1]==L[i])i--;
	}
	return 0;
}
