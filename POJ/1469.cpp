#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int tab[301][301];
int status[301],result[301];
int T,N,P,ANS,TI;
int find(int x)
{
	for(int i=1;i<=tab[x][0];i++)
	if(status[tab[x][i]]!=TI)
	{
		status[tab[x][i]]=TI;
		if (result[tab[x][i]]==0 || find(result[tab[x][i]]))
		{
			result[tab[x][i]]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&P,&N);
		for (int i=1;i<=P;i++)
		{
			scanf("%d",&tab[i][0]);
			for (int j=1;j<=tab[i][0];j++)
				scanf("%d",&tab[i][j]);
		}
		//
		fill(result,result+N+1,0);
		fill(status,status+N+1,0);
		ANS=0;
		for(TI=1;TI<=P;TI++)
			if(find(TI))
				ANS++;
			else
				break;
		if(ANS==P)
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	return 0;
}