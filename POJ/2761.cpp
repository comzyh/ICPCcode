#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int DS=100000;//Data size
int N,M,T,R;
struct segment
{
	int l,r,lc,rc,n;
}seg[30*DS];
int history[DS+5];
int num[DS+5],lsh[DS+5],rlsh[DS+5];
inline int cmp(const int &a,const int &b)
{
	return num[a]<num[b];
}
void build(int &s,int l,int r)
{
	if (s==0)
	{
		s=++R;
		seg[s].l=l;
		seg[s].r=r;
		seg[s].lc=seg[s].rc=seg[s].n=0;
	}
	if (l==r)
		return ;
	int mid=(l+r)>>1;
	build(seg[s].lc,l,mid);
	build(seg[s].rc,mid+1,r);
}
void change(int os,int &s,int x)//在x处+1
{
	s=++R;
	seg[s]=seg[os];
	seg[s].n++;
	if (seg[s].l==seg[s].r)
		return ;
	int mid=(seg[s].l+seg[s].r)>>1;
	if (x<=mid)
		change(seg[os].lc,seg[s].lc,x);
	else
		change(seg[os].rc,seg[s].rc,x);
}
int query(int s1,int s2,int k)
{
	if (seg[s2].l==seg[s2].r)
		return num[lsh[seg[s2].l]];
	int ln=seg[seg[s2].lc].n-seg[seg[s1].lc].n;
	if (k<=ln)
		return query(seg[s1].lc,seg[s2].lc,k);
	else
		return query(seg[s1].rc,seg[s2].rc,k-ln);
}
int main()
{ 
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&num[i]);
			lsh[i]=i;
		}
		sort(lsh+1,lsh+N+1,cmp);
		for (int i=1;i<=N;i++)
			rlsh[lsh[i]]=i;
		//
		T=R=0;
		memset(history,0,sizeof(history));
		build(history[0],1,N);
		for (int i=1;i<=N;i++)
			change(history[i-1],history[i],rlsh[i]);
		for (int i=1;i<=M;i++)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",query(history[l-1],history[r],k));
		}
	}
	return 0;
}
