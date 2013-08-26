#include <cstdio>
#include <cstring>
struct edge
{
	int t,l;
	void set(int a,int b)
	{
		t=a;
		l=b;
	}
}tab[2][1001][1001];
int N,M,X;
int q[1000000],h,r,in[1001],dis[2][1001],ANS;
int main()
{
	scanf("%d%d%d",&N,&M,&X);
	memset(tab,0,sizeof(tab));
	int i;
	for (i=1;i<=M;i++)
	{
		int f,t,l;
		scanf("%d%d%d",&f,&t,&l);
		tab[0][f][++tab[0][f][0].l].set(t,l);
		tab[1][t][++tab[1][t][0].l].set(f,l);
	}
	i=2;
	memset(dis,0x3f,sizeof(dis));
	while (i)
	{
		i--;
		h=0;
		r=1;
		dis[i][X]=0;
		q[1]=X;
		memset(in,0,sizeof(in));
		in[X]=1;
		while (h<r)
		{
			int t=q[++h];
			edge *tit=tab[i][t];
			for (int j=1;j<=tab[i][t][0].l;j++)
			if (tit[j].l<dis[i][tit[j].t]-dis[i][t])
			{
				dis[i][tit[j].t]=dis[i][t]+tit[j].l;
				if (!in[tit[j].t])
				{
					in[tit[j].t]=1;
					q[++r]=tit[j].t;
				}
			}
			in[t]=0;
		}
	}
	for (i=1;i<=N;i++)
		if (i!=X && dis[0][i]+dis[1][i]>ANS)
			ANS=dis[0][i]+dis[1][i];
	printf("%d\n",ANS); 
}
