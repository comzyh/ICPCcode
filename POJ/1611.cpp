#include <cstdio>
#include <cstring>
int f[30001],rank[30001];
int N,M,K;
int getf(int x);
inline void add(int x,int y);
int main()
{
	int i,j,x,y;
	while (scanf("%d%d",&N,&M),N || M)
	{
		for (i=0;i<N;i++)
		{
			f[i]=i;
			rank[i]=1;
		}
		for (i=1;i<=M;i++)
		{
			scanf("%d",&K);
			if (K)
				scanf("%d",&y);
			for (j=1;j<K;j++)
			{
				scanf("%d",&x);
				add(x,y);
				y=x;
			}
		}
		printf("%d\n",rank[getf(0)]);
	}
}
int getf(int x)
{
	if (f[x]==x)return x;
	return f[x]=getf(f[x]);
}
inline void add(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy)return ;
	if (rank[fx]>rank[fy])
	{
		f[fy]=fx;
		rank[fx]+=rank[fy];
	}
	else
	{
		f[fx]=fy;
		rank[fy]+=rank[fx];
	}
}
