#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,F,D;
int R;
struct T_edge
{
	int b,e,flow;
	inline void set(int b,int e,int flow)
	{
		this->b=b;
		this->e=e;
		this->flow=flow;
	}
}es[40000];//1000
int current[405];
vector<int> tab[405];
inline void addedge(int b,int e,int flow)
{
	es[++R].set(b,e,flow);
	tab[b].push_back(R);
	es[++R].set(e,b,0);
	tab[e].push_back(R);
}
int dis[405];
inline int BFS(int b,int e)
{
	queue<int>q;
	static int in[405];
	q.push(b);
	memset(in,0,sizeof(in));
	in[b]=1;
	memset(dis,0x3f,sizeof(dis));
	dis[b]=0;
	while (!q.empty())
	{
		int h=q.front();
		q.pop();
		for (int i=0;i<tab[h].size();i++)
			if (es[tab[h][i]].flow && dis[h]+1<dis[es[tab[h][i]].e])
			{
				dis[es[tab[h][i]].e]=dis[h]+1;
				if (!in[es[tab[h][i]].e])
				{
					q.push(es[tab[h][i]].e);
					in[es[tab[h][i]].e]=1;
				}
			}
		in[h]=0;
	}
	return dis[e]<0x3f3f3f3f;
}
int dinic(int x,int flow)
{
	//printf("x=%4d,dis=%4d,flow=%4d\n",x,dis[x],flow);
	if (x==F+D+2*N+1)
		return flow;
	int ans=0,i;
	for (i=current[x];i<tab[x].size();i++)
		if (flow && es[tab[x][i]].flow && dis[es[tab[x][i]].e]>dis[x])
		{
			//printf("--%4d %4d %4d\n",x,flow,i);
			int tans=dinic(es[tab[x][i]].e,min(flow,es[tab[x][i]].flow));
			ans+=tans;
			flow-=tans;
			es[tab[x][i]].flow-=tans;
			es[tab[x][i]^1].flow+=tans;
			if (tans)
				current[x]=i;
		}
	return ans;
}
int main()
{
	scanf("%d%d%d",&N,&F,&D);
	R=1;
	//0,1~F,F+1~F+D,F+D+1~F+D+2N,F+D+2N+1;
	for (int i=0;i<=F+D+2*N+1;i++)
		tab[i].clear();
	for (int i=1;i<=F;i++)
		addedge(0,i,1);
	for (int i=F+1;i<=F+D;i++)
		addedge(i,F+D+2*N+1,1);
	for (int i=F+D+1;i<=F+D+N;i++)
		addedge(i,i+N,1);
	for (int i=1;i<=N;i++)
	{
		int f,d,x;
		scanf("%d%d",&f,&d);
		for (int j=1;j<=f;j++)//F->C
		{
			scanf("%d",&x);
			addedge(x,F+D+i,1);
		}
		for (int j=1;j<=d;j++)
		{
			scanf("%d",&x);
			addedge(F+D+N+i,F+x,1);
		}
	}
	//dinic
	int ans=0,tans;
	while(BFS(0,F+D+2*N+1))
	{
		memset(current,0,sizeof(current));
		while(tans=dinic(0,0x3f3f3f3f))
			ans+=tans;
	}
	printf("%d\n",ans);
	return 0;
}