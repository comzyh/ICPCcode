#include <cstdio>
#include <cstring>
int G,B,M,T;
int tab[201][201];
int result[201],state[201],ans;
int find(int x);
int main()
{
	int i,x,y;
	T=0;
	while (scanf("%d%d%d",&G,&B,&M),G && B &&M)
	{
		memset(tab,0,sizeof(tab));
		for (i=1;i<=M;i++)
		{
			scanf("%d%d",&x,&y);
			tab[x][y]=1;
		}
		ans=0;
		memset(result,0,sizeof(result));
		for (i=1;i<=G;i++)
		{
			memset(state,0,sizeof(state));
			if (find(i))ans++;
		}
		printf("Case %d: %d\n",++T,G+B-ans);
	}
	
}

int find(int x)//匈牙利
{
	int i;
	for (i=1;i<=B;i++)
	if (tab[x][i]==0 && !state[i])
	{
		state[i]=1;
		if (result[i]==0 || find(result[i]))
		{
			result[i]=x;
			return 1;
		}
	}
	return 0;
}
