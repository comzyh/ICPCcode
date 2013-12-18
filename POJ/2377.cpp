#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct T_edge
{
	int f,t,l;
	T_edge(int f,int t,int l)
	{
		this->f=f;
		this->t=t;
		this->l=l;
	}
	inline int operator < (const T_edge x)const
	{
		return l>x.l;
	}
};
int N,M;
int f[1009];
vector<T_edge> es;
int getf(int x)
{
	if (f[x]==x)return x;
	return f[x]=getf(f[x]);
}
inline void add(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy)return ;
	f[fx]=fy;
}
int main()
{
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		es.clear();
		for (int i=1;i<=M;i++)
		{
			int f,t,l;
			scanf("%d%d%d",&f,&t,&l);
			es.push_back(T_edge(f,t,l));
		}
		sort(es.begin(),es.end());
		int ANS=0,used=0;
		for (int i=1;i<=N;i++)
			f[i]=i;
		for (int i=0;i<M;i++)
			if (getf(es[i].f)!=getf(es[i].t))
			{
				add(es[i].f,es[i].t);
				ANS+=es[i].l;
				used++;
			}
		if (used==N-1)
			printf("%d\n",ANS);
		else
			printf("-1\n");
	}
	return 0;
}