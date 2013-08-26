#include <cstdio>
#include <cstring>
int tab[101][101];
int N,M,ANS;
int main()
{
	int i,j,k;
	scanf("%d%d",&N,&M);
	memset(tab,0,sizeof(tab));
	int f,t;
	for (i=1;i<=M;i++)
	{
		scanf("%d%d",&f,&t);
		tab[f][t]=1;
		tab[t][f]=-1;
	}
	//Floyd
	for (k=1;k<=N;k++)
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
				if ((tab[i][k] && tab[k][j]) &&(
					(tab[i][k]>0 && tab[k][j]>0 && tab[i][k]+tab[k][j]>tab[i][j]) ||
					(tab[i][k]<0 && tab[k][j]<0 && tab[i][k]+tab[k][j]<tab[i][j])
					))
				tab[i][j]=tab[i][k]+tab[k][j];
	
	for (i=1;i<=N,0;i++)
	{
		for (j=1;j<=N;j++)
			printf("%4d",tab[i][j]);
		printf("\n");
	}
	for (i=1;i<=N;i++)
	{
		int sum=0;
		for (j=1;j<=N;j++)
			if (tab[i][j])
				sum++;
		if (sum==N-1)
			ANS++;
	}
	printf("%d\n",ANS);
}

