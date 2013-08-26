#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int tab[105][105];
int dis[105];
int N,A,B;
struct element
{
	int p,dis;
	element(){}
	element(int a,int b)
	{
		p=a;dis=b;
	}
	inline int operator < (const element &x)const 
	{
		return dis>x.dis;
	}
};
int DIJ(int x)
{
	priority_queue<element> q;
	q.push(element(x,0));
	static int done[105];
	memset(done,0,sizeof(done));
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	while (!q.empty())
	{
		element t=q.top();
		q.pop();
		if (done[t.p])
			continue;
		done[t.p]=1;
		for (int i=1;i<=tab[t.p][0];i++)
		{
			if (t.dis+1-(i==1)<dis[tab[t.p][i]])
			{
				dis[tab[t.p][i]]=t.dis+1-(i==1);
				q.push(element(tab[t.p][i],t.dis+1-(i==1)));
			}
		}
	}
}
int main()
{
	while (scanf("%d%d%d",&N,&A,&B)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&tab[i][0]);
			for (int j=1;j<=tab[i][0];j++)
				scanf("%d",&tab[i][j]);
		}
		DIJ(A);
		if (dis[B]<0x3f3f3f3f)
			printf("%d\n",dis[B]);
		else
			printf("-1\n");
	}
	return 0;
}
