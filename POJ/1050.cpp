#include <cstdio>
#include <cstring>
int N,ANS;
int tab[101][101];
int main()
{
	scanf("%d",&N);
	int i,j,k,x;
	memset(tab,0,sizeof(tab));
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
		{
			scanf("%d",&x);
			tab[i][j]=tab[i-1][j]+x;
		}
	ANS=0x80000000;
	int sum,max;
	for (i=1;i<=N;i++)//x1
		for (j=i;j<=N;j++)//x2
		{
			max=0x80000000;
			sum=0;
			for (k=1;k<=N;k++)
			{
				sum+=tab[j][k]-tab[i-1][k];
				if (sum>max)
					max=sum;
				if (sum<0)
					sum=0;
			}
			if (max>ANS)
				ANS=max;
		}
	printf("%d\n",ANS);
}
