#include <cstdio>
#include <cstring>
int N,K,ANS;
int tab[501][501];
int state[501],result[501];
int find(int x);
int main()
{
	int i,x,y;
	scanf("%d%d",&N,&K);
	memset(tab,0,sizeof(tab));
	for (i=1;i<=K;i++)
	{
		scanf("%d%d",&x,&y);
		tab[x][++tab[x][0]]=y;
	}
	ANS=0;
	for (i=1;i<=N;i++)
	{
		memset(state,0,sizeof(state));
		if (find(i))ANS++;
	}
	printf("%d\n",ANS);
}
int find(int x)//匈牙利算法
{
	int i;
	for (i=1;i<=tab[x][0];i++)
	{
		int &t=tab[x][i];
		if (state[t])continue;
		state[t]=1;
		if (result[t]==0 || find(result[t]))
		{
			result[t]=x;
			return 1;
		}
	}
	return 0;
}