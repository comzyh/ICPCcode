/*
用ZKW线段树实现动态RMQ,优化Dijkstra
Program:POJ3159
Author:comzyh
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAX=0x3f3f3f3f;
struct T_link
{
	int t,next,dis;
}es[160000];
int head[32768],tail;
struct T_data
{
	int f,min,n;
}near[65537];
int in[32768],dis[32768];
int N,M;
int added;
//
inline void update(int k,int n,int f);//设置
inline void update_by_point(int k);
inline int getmin_and_delete();//取最近节点并删除
int main()
{
	int i,j,f,k;
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		for (added=1;added<N;added<<=1);
		added--;
		memset(head,0,sizeof(head));
		tail=0;
		for (i=1;i<=M;i++)
		{
			tail++;
			scanf("%d%d%d",&f,&es[tail].t,&es[tail].dis);
			es[tail].next=head[f];
			head[f]=tail;
		}
		for (i=added+1,j=1;j<=N;i++,j++)
			near[i].n=j;
		for (i=1;i<=added+added+2;i++)
			near[i].min=MAX;
		memset(dis,0x3f,sizeof(dis));
		memset(in,0,sizeof(in));
		dis[1]=0;in[1]=1;
		update(1,MAX,0);
		update_by_point(1);
		for (i=1;i<N;i++)
			update_by_point(getmin_and_delete());
		printf("%d\n",dis[N]);	
		//for (i=1;i<=N;i++)
		//	printf("dis[%4d]=%4d\n",i,dis[i]);
	}
}
inline void update(int k,int n,int f)
{
	int x=added+k;
	near[x].min=n;
	near[x].f=f;
	do
	{
		x>>=1;
		if (near[x<<1].min<near[(x<<1)+1].min)
			near[x]=near[x<<1];
		else 
			near[x]=near[(x<<1)+1];
		
	}while (x>1);
}
inline void update_by_point(int k)
{
	for (int i=head[k];i!=0;i=es[i].next)//可以删除链表优化
		if (!in[es[i].t] && es[i].dis<near[added+es[i].t].min)
			update(es[i].t,es[i].dis,k);
}
inline int getmin_and_delete()
{
	T_data ans=near[1];
	dis[ans.n]=dis[ans.f]+ans.min;
	in[ans.n]=1;
	update(ans.n,MAX,0);
	return ans.n;
}