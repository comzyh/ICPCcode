#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct T_segment
{
	int l,r;
	int minl,minr,minm;
	int maxl,maxr,maxm;
	int sum;
};
int N,M;
int num[100009];
T_segment segs[400009];
inline void recalc(int s)
{
	T_segment &ss=segs[s],&sl=segs[s<<1],&sr=segs[(s<<1)+1];
	ss.sum=sl.sum+sr.sum;
	ss.minl=min(sl.minl,sl.sum+sr.minl);
	ss.minr=min(sr.minr,sl.minr+sr.sum);
	ss.minm=min(sl.minr+sr.minl,min(sl.minm,sr.minm));
	ss.maxl=max(sl.maxl,sl.sum+sr.maxl);
	ss.maxr=max(sr.maxr,sl.maxr+sr.sum);
	ss.maxm=max(max(sl.sum+sr.sum,sl.maxr+sr.maxl),max(sl.maxm,sr.maxm));
}
void build(int s,int l,int r)
{
	T_segment &ss=segs[s];
	ss.l=l;
	ss.r=r;
	if(l==r)
	{
		ss.sum=ss.minl=ss.minr=ss.minm=ss.maxl=ss.maxr=ss.maxm=num[l];
		return;
	}
	int mid=(l+r)>>1;
	build(s<<1,l,mid);
	build((s<<1)+1,mid+1,r);
	recalc(s);
	//printf("l=%4d,r=%4d,sum=%4d\n",l,r,ss.sum);
}
void update(int s,int p,int v)
{
	T_segment &ss=segs[s];
	if (ss.l==ss.r)
	{
		ss.sum=ss.minl=ss.minr=ss.minm=ss.maxl=ss.maxr=ss.maxm=v;
		return;
	}
	int mid=(ss.l+ss.r)>>1;
	if (p<=mid)
		update(s<<1,p,v);
	else
		update((s<<1)+1,p,v);
	recalc(s);
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
			scanf("%d",&num[i]);
		build(1,1,N);
		//printf("sum=%d\n",segs[1].sum);
		scanf("%d",&M);
		while(M--)
		{
			int p,v;
			scanf("%d%d",&p,&v);
			update(1,p,v);
			printf("%d\n",segs[1].maxm!=segs[1].sum?max(segs[1].maxm,segs[1].sum-segs[1].minm):segs[1].sum-segs[1].minm);
			//printf("sum=%4d,min=%4d,max=%4d\n",segs[1].sum,segs[1].minm,segs[1].maxm);
		}
	}
	return 0;
}