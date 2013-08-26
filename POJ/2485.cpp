#include <cstdio>
#include <cstdlib>
#include <cstring>
struct T_edge
{
	int f,t,dis;
	void init(int tf,int tt,int tdis)
	{
		f=tf;t=tt;dis=tdis;
	}
}es[250000],t;
int f[501];
inline int getf(int x);
inline void add(int x,int y);
void qsort(int b,int e);
int N,T,e,ANS,count;
int main()
{
	int i,j,dis;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		e=0;
		count=0;
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
			{
				scanf("%d",&dis);
				if (j<i)
					es[++e].init(i,j,dis);		
			}
		qsort(1,e);
		for (i=1;i<=N;i++)
			f[i]=i;
		for (i=1;count<N-1;i++)
			if (getf(es[i].f)!=getf(es[i].t))
			{	
				add(es[i].f,es[i].t);
				count++;
				ANS=es[i].dis;
			}
		printf("%d\n",ANS);
	}
	return 0;
}
inline int getf(int x)
{
	if (x==f[x])return x;
	return f[x]=getf(f[x]);
}
inline void add(int x,int y)
{
	if (getf(x)==getf(y))return ;
	f[getf(x)]=getf(y);
}
void qsort(int b,int e)
{
	int i=b,j=e,k=es[(b+e)>>1].dis;
	while (i<j)
	{
		while (es[i].dis<k)i++;
		while (es[j].dis>k)j--;
		if (i<=j)
		{
			t=es[i];es[i]=es[j];es[j]=t;
			i++;j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}
