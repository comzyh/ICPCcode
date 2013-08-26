#include <cstdio>
#include <cstring>
#include <cstdlib>
int tab[2001][2001];
char str[2001][10];
int dis[2001],disn[2001],in[2001];
int N,ANS;
inline int distance(char* x,char *y);
inline void updisn(int k);
int main()
{
	
	int i,j;
	while (scanf("%d",&N),N!=0)
	{
		ANS=0;
		getchar();
		for (i=1;i<=N;i++)
		{
			gets(str[i]);
			for (j=1;j<i;j++)
				tab[i][j]=tab[j][i]=distance(str[i],str[j]);
		}
		memset(dis,0x3f,sizeof(dis));
		memset(disn,0x3f,sizeof(disn));
		memset(in,0,sizeof(in));
		dis[1]=0;in[1]=1;
		disn[0]=0x7fffffff;
		int min;
		updisn(1);
		while (1)
		{
			min=0;
			for (i=1;i<=N;i++)
				if (!in[i] && disn[i]<disn[min])min=i;
			if(min)
			{
				in[min]=1;
				ANS+=disn[min];
				updisn(min);
			}
			else break;
		}
		printf("The highest possible quality is 1/%d.\n",ANS);
		
	}
}
inline int distance(char* x,char *y)
{
	int i,ans=0;
	for (i=0;i<7;i++)if (x[i]!=y[i])ans++;
	return ans;
}
inline void updisn(int k)
{
	for (int i=1;i<=N;i++)
		if (tab[k][i]<disn[i])disn[i]=tab[k][i];
}
