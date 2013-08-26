#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN=10005;
struct T_poster
{
	int b,e;
}ps[MAXN];
struct T_segment
{
	int l,r,mid,p;
}seg[MAXN*4*6];
int appear[MAXN];
int LSH[MAXN*6],R;
int T,N,ANS;
int NOW;
//
inline int bin(int x);
void build(int s,int l,int r);
void set(int s,int l,int r,int p);
void query(int s);
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		int i,j;
		R=0;
		for (i=1;i<=N;i++)
		{
			scanf("%d%d",&ps[i].b,&ps[i].e);
			LSH[++R]=ps[i].b;
			LSH[++R]=ps[i].b+1;
			LSH[++R]=ps[i].b-1;
			LSH[++R]=ps[i].e;
			LSH[++R]=ps[i].e+1;
			LSH[++R]=ps[i].e-1;
		}
		sort(LSH+1,LSH+6*N+1);
		//判重
		j=0;
		for (i=1;i<=6*N;i++)
			if (LSH[i]!=LSH[i-1])
				LSH[++j]=LSH[i];
		R=j;
		build(1,1,R);
		memset(appear,0,sizeof(appear));
		for (i=1;i<=N;i++)
			set(1,bin(ps[i].b),bin(ps[i].e),i);
		query(1);
		ANS=0;
		for (i=1;i<=N;i++)
			ANS+=appear[i];
		printf("%d\n",ANS);
		
	}
	return 0;
}
void build(int s,int l,int r)
{
	seg[s].l=l;
	seg[s].r=r;
	seg[s].p=0;
	if (l==r)
		return ;
	seg[s].mid=(l+r)>>1;
	build(s<<1,l,seg[s].mid);
	build((s<<1)+1,seg[s].mid+1,r);
}
void set(int s,int l,int r,int p)
{
	if (l>seg[s].r || r<seg[s].l)
		return ;
	if (l<=seg[s].l && r>=seg[s].r)
	{
		seg[s].p=p;
		return ;
	}
	if (seg[s].p>=0)
	{
		set(s<<1,seg[s].l,seg[s].mid,seg[s].p);
		set((s<<1)+1,seg[s].mid+1,seg[s].r,seg[s].p);
		seg[s].p=-1;
	}
	if (l<=seg[s].mid)
		set(s<<1,l,r,p);
	if (r>seg[s].mid)
		set((s<<1)+1,l,r,p);
}
inline int bin(int x)
{
	int b=1,e=R,k;
	while (b<e)
	{
		k=(b+e)>>1;
		if (LSH[k]<x)
			b=k+1;
		else
		{
			if (LSH[k]>=x && LSH[k-1]>=x)
				e=k-1;
			else
				return k;
		}
	}
	return b;
}
void query(int s)
{
	if (seg[s].p>=0)
	{
		appear[seg[s].p]=1;
		return ;
	}
	if (seg[s].l==seg[s].r)
		return ;
	query(s<<1);
	query((s<<1)+1);
}
