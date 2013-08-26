#include <cstdio>
#include <cstring>
const int MAX=100000;
int f[MAX+1],dis[MAX+1],rank[MAX+1];
int T,N,M;
int getf(int x)
{
	if (f[x]==x)return x;
	int fx=f[x];
	f[x]=getf(f[x]);
	dis[x]^=dis[fx];
	return f[x];
}
inline void addd(int x,int y)//add x to y
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy)return ;
	if (rank[fy]>rank[fx])
	{
		rank[fy]+=rank[fx];
		f[fx]=fy;
		//dis[x]^dis[fx]^dis[y]=1 -> dis[fx]=dis[x]^dis[y]^1
		dis[fx]=dis[x]^dis[y]^1;
	}
	else
	{
		rank[fx]+=fy;
		f[fy]=fx;
		dis[fy]=dis[x]^dis[y]^1;
	}
}
//错误,有可能生成环状递归
/*
inline void addd(int x,int y)//add x to y
{
	int fx=getf(x);
	f[fx]=y;
	dis[fx]=(dis[x]+1)%2;
}
*/

inline void ask(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy)
	{
		if (dis[x]==dis[y])
			printf("In the same gang.\n");
		else
			printf("In different gangs.\n");
	}
	else
		printf("Not sure yet.\n");
}
int main()
{
	int i,x,y;
	char c;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&N,&M);
		for (i=1;i<=N;i++)
		{
			f[i]=i;
			dis[i]=0;
			rank[i]=1;
		}
		while (M--)
		{
			getchar();
			scanf("%c%d%d",&c,&x,&y);
			if (c == 'A')
				ask(x,y);
			else
				addd(x,y);
		}
	}
	return 0;
}
