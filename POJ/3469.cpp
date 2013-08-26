#include <cstdio>
#include <cstring>
const int MAX=0x3f3f3f3f;
struct T_edge
{
	int t,next,cap;
}edge[660000];
int N,M,ANS;
int head[20005],R;
int dis[20006],q[400000];
int current[20006];
//
inline void AddEdge(int f,int t,int flow);
inline void AddDEdge(int f,int t,int flow);
int BFS();
int dfs(int x,int low);
inline int min(int a,int b);
int main()
{
	int i,j,fr,to,q;
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		R=1;
		memset(head,0,sizeof(head));
		for (i=1;i<=N;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			AddEdge(0,i,a);
			AddEdge(i,N+1,b);
		}
		for (i=1;i<=M;i++)
		{
			scanf("%d%d%d",&fr,&to,&q);
			AddDEdge(fr,to,q);
		}
		//Dinic
		ANS=0;
		while (BFS())
		{
			int tans;
			memset(current,0,sizeof(current));
			while (tans=dfs(0,0x7fffffff))
				ANS+=tans;
		}
		printf("%d\n",ANS);
		
	}
}
inline int min(int a,int b)
{
	return ((a<b)?a:b);
}
inline void AddEdge(int f,int t,int flow)
{
	R++;
	edge[R].t=t;
	edge[R].cap=flow;
	edge[R].next=head[f];
	head[f]=R;
	R++;
	edge[R].t=f;
	edge[R].cap=0;
	edge[R].next=head[t];
	head[t]=R;
}
inline void AddDEdge(int f,int t,int flow)
{
	R++;
	edge[R].t=t;
	edge[R].cap=flow;
	edge[R].next=head[f];
	head[f]=R;
	R++;
	edge[R].t=f;
	edge[R].cap=flow;
	edge[R].next=head[t];
	head[t]=R;
}
int BFS()
{
	int h=0,r=1;
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	q[1]=0;
	while (h<r)
	{
		int t=q[++h];
		for (int i=head[t];i!=0;i=edge[i].next)
			if (edge[i].cap>0 && dis[t]+1<dis[edge[i].t])
			{
				dis[edge[i].t]=dis[t]+1;
				q[++r]=edge[i].t;
			}
	}
	if (dis[N+1]!=MAX)
		return 1;
	else
		return 0;
}
int dfs(int x,int low)
{
	if (x==N+1)
		return low;
	int tans=0;
	if (current[x]==0)
		current[x]=head[x];
	for (int i=current[x];i!=0 && low>0;i=edge[i].next)
	if (edge[i].cap>0 && dis[edge[i].t]>dis[x] && (tans=dfs(edge[i].t,min(low,edge[i].cap)))>0)
	{
		edge[i].cap-=tans;
		edge[i^1].cap+=tans;
		current[x]=i;
		return tans;
	}
	dis[x]=-1;
	//return w;
	return 0;
}
