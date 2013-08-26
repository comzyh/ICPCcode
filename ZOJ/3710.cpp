#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T;
int N,M,K;
int tab[105][105];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&N,&M,&K);
		memset(tab,0,sizeof(tab));
		for (int i=1;i<=M;i++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			tab[f][t]=tab[t][f]=1;
		}
		int detla,i,j,k,ANS=0;
		do
		{
			detla=0;
			for (i=0;i<N;i++)
				for (j=i+1;j<N;j++)
				if (!tab[i][j])
				{
					int com=0;
					for (k=0;k<N;k++)
					if (i!=k && j!=k && tab[i][k] && tab[k][j] && !tab[i][j])
						com++;
					if (com>=K)
					{
						tab[i][j]=tab[j][i]=1;
						detla++;
					}
				}
			ANS+=detla;
		}while (detla);
		printf("%d\n",ANS);
	}
}