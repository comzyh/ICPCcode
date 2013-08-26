#include <cstdio>
#include <cstring>
int N,Q;
int app[101];
int main()
{
	int i,j,M,d,ans;
	while (scanf("%d%d",&N,&Q),N && Q)
	{
		memset(app,0,sizeof(app));
		
		for (i=1;i<=N;i++)
		{	
			scanf("%d",&M);
			for (j=1;j<=M;j++)
			{
				scanf("%d",&d);
				app[d]++;
			}
		}
		ans=0;
		for (i=1;i<=100;i++)
			if (app[i]>app[ans] && app[i]>=Q)
				ans=i;
		printf("%d\n",ans);
	}
}