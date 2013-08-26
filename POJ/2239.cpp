#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N,ANS,I;
int tab[301][84];
int result[84],state[84];
int find(int x)
{
	int n;
	for (int i=1;i<=tab[x][0];i++)
	{
		n=tab[x][i];
		if (state[n]!=I)
		{
			state[n]=I;
			if (!result[n] || find(result[n]))
			{
				result[n]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&tab[i][0]);
			for (int j=1;j<=tab[i][0];j++)
			{
				int p,q;
				scanf("%d%d",&p,&q);
				tab[i][j]=12*(p-1)+q-1;
			}
		}
		fill(result,result+84,0);
		fill(state,state+84,0);
		ANS=0;
		for (I=1;I<=N;I++)
			ANS+=find(I);
		printf("%d\n",ANS);
	}
}