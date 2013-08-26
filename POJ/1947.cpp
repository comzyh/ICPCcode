#include <cstdio>
#include <cstring>
const int MAX=200;
int tab[MAX][MAX];
int N,P,ANS;
int size[MAX];
int dfs(int x);
int main()
{
	scanf("%d%d",&N,&P);
	int i,j,fr,to;
	memset(tab,0,sizeof(tab));
	for (i=1;i<N;i++)
	{
		scanf("%d%d",&fr,&to);
		tab[fr][++tab[fr][0]]=to;
	}
	dfs(1);
	ANS=0;
	for (i=1;i<=N;i++)
	{
		printf("%4d\n",size[i]);
		if (size[i]==P || size[i]==N-P)
			ANS++;
	}
	printf("%d\n",ANS);
}
int dfs(int x)
{
	int ans=1;
	for (int i=1;i<=tab[x][0];i++)
	{
		ans+=dfs(tab[x][i]);
	}
	return size[x]=ans;
}
