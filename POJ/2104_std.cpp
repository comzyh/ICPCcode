//POJ 2104 K-th Number  using functional interval tree
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
const int maxn=200001,maxnd=3000000;
int N,M,m,tot;
struct rec
{
	int a,b,l,r,s;
}a[maxnd];
int org[maxn],root[maxn],b[maxn];
int build(int l,int r)
{
	if(l>r){return 0;}
	int k=++tot; a[k].a=l; a[k].b=r; a[k].s=0;
	if(l==r)return k;
	int mid=(l+r)>>1;
	a[k].l=build(l,mid);
	a[k].r=build(mid+1,r);
	return k;
}
int change(int p,int x,int w)
{
	int k=++tot; 
	a[k].a=a[p].a; a[k].b=a[p].b;
	a[k].l=a[p].l; a[k].r=a[p].r; 
	a[k].s=a[p].s+w;
	if(a[p].a==x&&a[p].b==x)return k;
	int mid=(a[p].a+a[p].b)>>1;
	if(x<=mid)a[k].l=change(a[p].l,x,w);
	else a[k].r=change(a[p].r,x,w);
	return k;
}
int query(int p,int q,int k)
{
	if(a[p].a==a[p].b)return a[p].a;
	int t=a[a[p].l].s-a[a[q].l].s;
	if(k<=t)
		return query(a[p].l,a[q].l,k);
	else
		return query(a[p].r,a[q].r,k-t);
} 
inline int bin(int x)
{
	int l=1,r=m,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(b[mid]==x)return mid;
		if(x<b[mid])r=mid-1;else l=mid+1;
	}
	return 1;
}
int main()
{
	int i,x,y,k;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;++i)scanf("%d",&org[i]);
	for(i=1;i<=N;++i)b[i]=org[i];
		std::sort(b+1,b+N+1);
	for(m=1,i=2;i<=N;++i)if(b[m]!=b[i])b[++m]=b[i];
	for(i=1;i<=N;++i)org[i]=bin(org[i]);
	root[0]=build(1,m); 
	for(i=1;i<=N;++i)root[i]=change(root[i-1],org[i],1);
	while(M--)
	{
		scanf("%d%d%d",&x,&y,&k);
		printf("%d\n",b[query(root[y],root[x-1],k)]);
	}
	return 0;
}