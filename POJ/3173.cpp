#include <cstdio>
int tab[50][50]={},N,S;
int main()
{
	scanf("%d%d",&N,&S);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=i;j++)
		{
			tab[j][i]=S++;
			if (S==10)S=1;
		}
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=N;j++)
			if (tab[i][j])
				printf("%d ",tab[i][j]);
			else
				printf("  ");
		printf("\n");
	}
	return 0;
}

