#include <cstdio>
#include <iostream>
struct node 
{
	int f,t,l;
}tab[15001];
int ans[1001];
int f[1001];
int getf(int x);
inline void add(int x,int y);
int N,M,r,MAX,IN;
void qsort(int b,int e);
int main()
{
	int i,j;
	scanf("%d%d",&N,&M);
	for (i=1;i<=M;i++)
		scanf("%d%d%d",&tab[i].f,&tab[i].t,&tab[i].l);
	qsort(1,M);
	for (i=1;i<=N;i++)
		f[i]=i;
	r=MAX=0;
	for (i=1;i<=M;i++)
	if (getf(tab[i].f)!=getf(tab[i].t))
	{
		ans[++r]=i;
		add(tab[i].f,tab[i].t);
		if (tab[i].l>MAX)MAX=tab[i].l;
		if (++IN==N-1)break;
	}
	//Output
	printf("%d\n",MAX);
	printf("%d\n",r);
	for (i=1;i<=r;i++)
		printf("%d %d\n",tab[ans[i]].f,tab[ans[i]].t);
}
void qsort(int b,int e)
{
	int i=b,j=e,k=tab[(b+e)>>1].l;
	while (i<=j)
	{
		while (tab[i].l<k)i++;
		while (tab[j].l>k)j--;
		if (i<=j)
		{
			std::swap(tab[i],tab[j]);
			i++;
			j--;
		}
	}
	if (b<j)qsort(b,j);
	if (i<e)qsort(i,e);
}
int getf(int x)
{
	if (f[x]==x)return x;
	return f[x]=getf(f[x]);
}
inline void add(int x,int y)
{
	if (getf(x)==getf(y))
		return ;
	f[getf(x)]=getf(y);
}
