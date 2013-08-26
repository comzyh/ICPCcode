#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX=0x3f3f3f3f;
struct T_edge
{
	int t,flow,next;
}es[10009];
int head[205],R;
int N,S,T,ANS;
int tab[205][205],dis[202];
inline void addedge(int x,int y)
{
	R++;
	es[R].t=y;
	es[R].flow=1;
	es[R].next=head[x];
	head[x]=R;
	R^=1;
	es[R].t=x;
	es[R].flow=1;
	es[R].next=head[y];
	head[y]=R;
	if (x==S || y==S)
		es[R].flow=es[R^1].flow=MAX;
}
inline int BFS(int s,int t)
{
	queue<int> q;
	q.push(s);
	static int in[202];
	memset(dis,0x3f,sizeof(dis));
	memset(in,0,sizeof(in));
	in[s]=1;
	dis[s]=0;
	while (!q.empty())
	{
		int t=q.front();
		q.pop();
		for (int i=head[t];i!=0;i=es[i].next)
			if (es[i].flow>0 && dis[t]+1<dis[es[i].t])
			{
				dis[es[i].t]=dis[t]+1;
				if (!in[es[i].t])
				{
					in[es[i].t]=1;
					q.push(es[i].t);
				}

			}
		in[t]=0;
	}
	return dis[t]<MAX;
}
int dinic(int x,int minf)
{
	if (x==T)
		return minf;
	for (int i=head[x];i!=0;i=es[i].next)
		if (es[i].flow>0 && dis[es[i].t]>dis[x])
		{
			int f=dinic(es[i].t,min(minf,es[i].flow));
			if (f)
			{
				es[i].flow-=f;
				es[i^1].flow+=f;
				return f;
			}
		}
}
int main()
{
	while (scanf("%d%d%d",&N,&S,&T)!=EOF)
	{
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				scanf("%d",&tab[i][j]);
		memset(head,0,sizeof(head));
		R=1;
		for (int i=1;i<=N;i++)
			for (int j=i+1;j<=N;j++)
			if (tab[i][j])
				addedge(i,j);
		//Dinic
		ANS=0;
		while (BFS(S,T))
			ANS+=dinic(S,MAX);
		printf("%d\n",ANS);

	}
	return 0;
}