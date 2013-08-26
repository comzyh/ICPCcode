#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX=100000;
//0left 1up 2right 3down
const int cd[4][2]={{3,1},{0,2},{1,3},{2,0}};
int P;
struct point
{
	int x,y;
	int adj[4];//left up right down
	inline int dis(const point &p)
	{
		return (x>p.x?x-p.x:p.x-x)+(y>p.y?y-p.y:p.y-y);
	}
}ps[MAX+5];
int ANS;
int sortx[MAX+5],sorty[MAX+5];
int in[MAX+5];
inline bool lessx(const int &a,const int &b)
{
	return (ps[a].x<ps[b].x) || (ps[a].x==ps[b].x && ps[a].y<ps[b].y);
}
inline bool lessy(const int &a,const int &b)
{
	return (ps[a].y<ps[b].y) || (ps[a].y==ps[b].y && ps[a].x<ps[b].x);
}
int main()
{	
	while (scanf("%d",&P),P)
	{
		int i,j;
		memset(ps,0,sizeof(ps));
		for (i=1;i<=P;i++)
		{
			scanf("%d%d",&ps[i].x,&ps[i].y);
			sortx[i]=sorty[i]=i;
		}
		sort(sortx+1,sortx+P+1,lessx);
		sort(sorty+1,sorty+P+1,lessy);
		// for (i=1;i<=P;i++)
		// {
			// printf("%4d %4d\n",sortx[i],sorty[i]);
			// printf("(%4d,%4d) (%4d,%4d)\n",ps[sortx[i]].x,ps[sortx[i]].y,ps[sorty[i]].x,ps[sorty[i]].y);
		// } 
		
		for (i=1;i<P;i++)
		{
			//0left 1up 2right 3down
			//纵向
			int &sx=sortx[i],&sx1=sortx[i+1],&sy=sorty[i],&sy1=sorty[i+1];
			if (ps[sx].x==ps[sx1].x)
			{
				ps[sx].adj[1]=sx1;
				ps[sx1].adj[3]=sx;
			}
			//printf("sy=%d,ps[sy].y=%d,ps[sy+1].y=%d\n",sy,ps[sy].y,ps[sy+1].y);
			if (ps[sy].y==ps[sy1].y)
			{
				ps[sy].adj[2]=sy1;
				ps[sy1].adj[0]=sy;
			}
		}
		// for (i=1;i<=P;i++)
			// printf("%4d: %4d %4d %4d %4d\n",i,ps[i].adj[0],ps[i].adj[1],ps[i].adj[2],ps[i].adj[3]);
		//work
		ANS=0;
		memset(in,0,sizeof(in));
		int po=1,d=0;//来源方向向左
		//0left 1up 2right 3down
		while (!in[po])
		{
			in[po]=1;
			//printf("(%4d,%4d)\n",ps[po].x,ps[po].y);
			int next;
			if (ps[po].adj[cd[d][0]])
			{
				next=ps[po].adj[cd[d][0]];
				d=cd[d][0];
			}
			else
			{
				next=ps[po].adj[cd[d][1]];
				d=cd[d][1];
			}
			ANS+=ps[po].dis(ps[next]);
			po=next;
		}
		printf("The length of the fence will be %d units.\n",ANS);
	}
}
