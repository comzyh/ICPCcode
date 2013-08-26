#include <cstdio>
#include <cstring>
#include <iostream>
#define MS(a) memset(a,0,sizeof(a))
using namespace std;
//const int MAXX=101;
int F,D,N,ANS;
int food[101][101],drink[101][101],rf[101],rd[101],sf[101],sd[101];
int findf(int x);
int findd(int x);

int main()
{
	while (scanf("%d%d%d",&N,&F,&D)!=EOF)
	{
		int i,j;
		MS(food);
		MS(drink);
		for (i=1;i<=N;i++)
		{
			int fi,di,a;
			scanf("%d%d",&fi,&di);
			for (j=1;j<=fi;j++)
			{
				scanf("%d",&a);
				food[a][++food[a][0]]=i;
			}
			for (j=1;j<=di;j++)
			{
				scanf("%d",&a);
				drink[i][++drink[i][0]]=a;
			}
		}
		//变种匈牙利
		MS(rf);MS(rd);
		ANS=0;
		for (i=1;i<=F;i++)
		{
			MS(sf);MS(sd);
			if (findf(i))
				ANS++;
			//printf("--------------\n");
		}
		printf("%d\n",ANS);
	}
}
int findf(int x)
{
	int i;
	for (i=1;i<=food[x][0];i++)
	{
		int &t=food[x][i];
		if (!sf[t])
		{
			sf[t]=1;
			if (rf[t]==x)continue;
			//printf("F:x=%4d,t=%4d\n",x,t);
			if ((!rf[t] && findd(t))  || findf(rf[t]))
			{
				rf[t]=x;
				//printf("food %4d->cow %4d\n",x,t);
				return 1;
			}
		}
	}
	return 0;
}
int findd(int x)
{
	int i;
	for (i=1;i<=drink[x][0];i++)
	{
		int &t=drink[x][i];
		if (!sd[t])
		{
			sd[t]=1;
			//printf("D:x=%4d,t=%4d\n",x,t);
			if (!rd[t]  || findd(rd[t]) || ( (/*sf[rd[t]]=1,*/findf(rf[rd[t]])) && (rf[rd[t]]=0,1) ) )
			{
				rd[t]=x;
				//printf("cow %4d->drink %4d\n",x,t);
				return 1;
			}
		}
	}
	return 0;
}
