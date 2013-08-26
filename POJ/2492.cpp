#include <cstdio>
#include <cstring>
int f[2005],dis[2005];
int T,N,M,ANS;
int getf(int x)
{
	if (f[x]==x)return x;
	int fx=f[x];
	f[x]=getf(f[x]);
	dis[x]^=dis[fx];
	return f[x];
}
inline int add(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy)return (dis[x]!=dis[y]);
	f[fx]=fy;
	dis[fx]=dis[x]^dis[y]^1;
	return 1;
}
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		scanf("%d%d",&N,&M);
		int i,a,b;
		for (i=1;i<=N;i++)
		{
			f[i]=i;
			dis[i]=0;
		}
		ANS=1;
		for (i=1;i<=M;i++)
		{
			scanf("%d%d",&a,&b);
			if (!add(a,b))
				ANS=0;
		}
		printf("Scenario #%d:\n",TT);
		if (ANS)
			puts("No suspicious bugs found!\n");
		else
			puts("Suspicious bugs found!\n");
	}
	return 0;
}