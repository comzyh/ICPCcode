#include <cstdio>
#include <cstring>
#include <cmath>
int N,D;
struct point
{
	int x,y;
	bool near(const point &p)
	{
		return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)<=D*D;
	}
}ps[1002];
int tab[1002][1002];
int open[1002];
int rank[1002];
int f[1002];
int getf(int x);
inline void add(int x,int y);
int main()
{
	int i,j,a,b;
	char c;
	while (scanf("%d%d",&N,&D)!=EOF)
	{
		//memset(tab,0,sizeof(tab));
		for (i=1;i<=N;i++)
			scanf("%d%d",&ps[i].x,&ps[i].y);
		for (i=1;i<=N;i++)
			for (j=i+1;j<=N;j++)
				if (ps[i].near(ps[j]))
				{
					tab[i][++tab[i][0]]=j;
					tab[j][++tab[j][0]]=i;
				}
		/*
		for (i=1;i<=N;i++)
		{
			for (j=1;j<=N;j++)
				printf("%3d",tab[i][j]);
			printf("\n");
		}*/
		//init father
		for (i=0;i<=N;i++)
			f[i]=i,rank[i]=1;
		memset(open,0,sizeof(open));
		while (getchar(),scanf("%c",&c)!=EOF)
		switch (c)
		{
			case 'O':
				scanf("%d",&a);
				open[a]=1;
				for (i=1;i<=tab[a][0];i++)
					if (open[tab[a][i]])add(a,tab[a][i]);
				break;
			case 'S':
				scanf("%d%d",&a,&b);
				if (getf(a)==getf(b))
					printf("SUCCESS\n");
				else
					printf("FAIL\n");
				break;
		}
	}
}
int getf(int x)
{
	if (f[x]==x)return x;
	return f[x]=getf(f[x]);
}
inline void add(int x,int y)
{
	//printf("add %3d %3d\n",x,y);
	int xx=getf(x),yy=getf(y);
	if (xx==yy)return ;
	if (rank[xx]>rank[yy])
	{
		rank[xx]+=rank[yy];
		f[yy]=xx;
	}
	else
	{
		rank[yy]+=rank[xx];
		f[xx]=yy;
	}
}
