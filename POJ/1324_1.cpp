#include <cstdio>
#include <cstring>
int N,M,L,K;
struct point
{
	int x,y;
	inline int h()
	{
		return (x-1)+(y-1);
	}
};
struct node
{
	point p[9];
	int head,g;
	inline int gh()
	{
		return p[head].h()+g;
	}
	
}q[100000];
node* heap[100000];
int rq,rh;
int map[50][50];
int add(node* n);
int main()
{
	int i,x,y;
	while (scanf("%d%d%d",&N,&M,&L),N && M && L)
	{
		memset(q,0,sizeof(q));
		rh=rq=1;
		for (i=0;i<L;i++)
		{
			scanf("%d%d",&x,&y);
			q[1].p[i].x=x;
			q[1].p[i].y=y;
		}
		heap[1]=&q[1];
		//
		
		
		scanf("%d",&K);
		memset(map,0,sizeof(map));
		for (i=1;i<=K;i++)
		{
			scanf("%d%d",&x,&y);
			map[x][y]=1;
		}
		
	}
}
int add(node* n)
{
	
}