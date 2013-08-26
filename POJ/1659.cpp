#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct Frog
{
	int link,index;
	inline bool operator <(const Frog &x)const
	{
		return link>x.link;
	}
}e[11];
int T,N;
int tab[11][11];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int i,j;
		scanf("%d",&N);
		for (i=1;i<=N;i++)
		{
			scanf("%d",&e[i].link);
			e[i].index=i;
		}
		memset(tab,0,sizeof(tab));
		int haveans=1;
		for (i=1;i<=N && haveans;i++)
		{
			std::sort(e+1,e+N+1);
			if (!e[1].link)
				break;
			for (j=2;j<=N && e[1].link;j++)
				if (e[j].link)
				{
					e[1].link--;
					e[j].link--;
					tab[e[1].index][e[j].index]=tab[e[j].index][e[1].index]=1;
				}
				else
				{
					haveans=0;
					break;
				}
		}
		if (haveans)
		{
			printf("YES\n");
			for (i=1;i<=N;i++)
			{
				for (j=1;j<=N;j++)
					printf("%d ",tab[i][j]);
				printf("\n");
			}
		}
		else
			printf("NO\n");
		printf("\n");
	}
}
