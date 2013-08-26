#include <cstdio>
#include <cstring>
const int COUNT=100000;
struct node
{
	int count,c1,state,neg;
}ns[COUNT+5];
struct edge
{
	int t,next;
}es[COUNT+5];
int head[COUNT+5],R;
int fa[COUNT+5];
int N,M;
int makecount(int x);
int count(int x);
void fresh(int x);
void operate(int x);
int negate(int x);
int main()
{
	int i,j;
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		memset(head,0,sizeof(head));
		R=0;
		for (i=2;i<=N;i++)
		{
			int f;
			scanf("%d",&f);
			fa[i]=f;
			//edge
			R++;
			es[R].next=head[f];
			es[R].t=i;
			head[f]=R;
		}
		makecount(1);
		// s
		//
		for (i=1;i<=M;i++)
		{	
			int c,x;
			getchar();
			scanf("%c %d",&c,&x);
			if (c=='q')
				printf("%d\n",count(x));
			else
				operate(x);
		}
		printf("\n");
	}
}
//计数
int makecount(int x)
{
	ns[x].neg=ns[x].state=ns[x].c1=0;
	ns[x].count=1;
	for (int i=head[x];i!=0;i=es[i].next)
			ns[x].count+=makecount(es[i].t);
	return ns[x].count;
}
int count(int x)
{
	fresh(x);
	return ns[x].c1;
}
void fresh(int x)
{
	if (!x)
		return ;
	fresh(fa[x]);
	if (ns[x].neg)
	{
		ns[x].neg=0;
		negate(x);
	}
}
void operate(int x)
{
	fresh(x);
	int d=negate(x),father=x;
	if (d)
		while(father=fa[father])
			ns[father].c1+=d;
}
int negate(int x)//反转一个点
{
	if (ns[x].neg==0)
	{
		int old=ns[x].c1;
		ns[x].c1=ns[x].count-ns[x].c1;
		for (int i=head[x];i!=0;i=es[i].next)
				ns[es[i].t].neg^=1;
		return ns[x].c1-old;
	}
	else
	{
		ns[x].neg=0;
		return 0;
	}
}
