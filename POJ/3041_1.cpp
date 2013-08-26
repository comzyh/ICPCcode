#include <cstdio>
#include <cstring>
int N,K,ANS;
int tab[501][501];
int main()
{
	int i,j,x,y;
	scanf("%d%d",&N,&K);
	memset(tab,0,sizeof(tab));
	for (i=1;i<=K;i++)
	{
		scanf("%d%d",&x,&y);
		tab[x][0]++;
		tab[0][y]++;
		tab[x][y]=1;
	}
	int mx,my;
	ANS=0;
	do
	{
		mx=0;
		my=0;
		for (i=1;i<=N;i++)
		{
			if (tab[i][0]>tab[mx][0])
				mx=i;
			if (tab[0][i]>tab[0][my])
				my=i;
		}
		if (mx==0 && my==0)
			break;
		if (tab[mx][0]>tab[0][my])
		{
			for (i=1;i<=N;i++)
				if (tab[mx][i])
				{
					tab[mx][i]=0;
					tab[mx][0]--;
					tab[0][i]--;
				}
		}
		else
		{
			for (i=1;i<=N;i++)
				if (tab[i][my])
				{
					tab[i][my]=0;
					tab[i][0]--;
					tab[0][my]--;
				}
		}
		ANS++;
	}while (mx || my);
	printf("%d\n",ANS);
	
}
