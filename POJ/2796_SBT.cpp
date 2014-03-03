#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
struct Node
{
	int l,r,val,size;
}ns[200000];
int N,Root,R=0;
int num[100009],minorder[100009];
long long sum[100009];
inline void left_rotate(int &T)
{
	int k=ns[T].r;
	ns[T].r=ns[k].l;
	ns[k].l=T;
	ns[k].size=ns[T].size;
	ns[T].size=ns[ns[T].l].size+ns[ns[T].r].size+1;
	T=k;
}
inline void right_rotate(int &T)
{
	int k=ns[T].l;
	ns[T].l=ns[k].r;
	ns[k].r=T;
	ns[k].size=ns[T].size;
	ns[T].size=ns[ns[T].l].size+ns[ns[T].r].size+1;
	T=k;
}
void Maintain(int &T,int left)
{
	if (left)
	{
		if (ns[ns[ns[T].l].l].size>ns[ns[T].r].size)
			right_rotate(T);
		else if (ns[ns[ns[T].l].r].size>ns[ns[T].r].size)
		{
			left_rotate(ns[T].l);
			right_rotate(T);
		}
		else
			return;
	}
	else
	{
		if (ns[ns[ns[T].r].r].size>ns[ns[T].l].size)
			left_rotate(T);
		else if (ns[ns[ns[T].r].l].size>ns[ns[T].l].size)
		{
			right_rotate(ns[T].r);
			left_rotate(T);
		}
		else return;
	}
	Maintain(ns[T].l,1);
	Maintain(ns[T].r,0);
	Maintain(T,0);
	Maintain(T,1);
}
void insert(int &T,int val)
{
	if (T==0)
	{
		T=++R;
		ns[T].l=ns[T].r=0;
		ns[T].size=1;
		ns[T].val=val;
		return;
	}
	ns[T].size++;
	if (val<=ns[T].val)
		insert(ns[T].l,val);
	else
		insert(ns[T].r,val);
	Maintain(T,val<ns[T].val);
}
inline int lower_index(int val)
{
	int t=Root,ans=0;
	while(t)
		if (ns[t].val<val)
		{
			ans+=ns[ns[t].l].size+1;
			t=ns[t].r;
		}
		else
			t=ns[t].l;
	return ans;
}
inline int upper_index(int val)
{
	int t=Root,ans=0;
	while(t)
		if (ns[t].val>val)
		{
			ans+=ns[ns[t].r].size+1;
			t=ns[t].l;
		}
		else
			t=ns[t].r;
	return ns[Root].size-ans+1;
}
inline int getk(int rank)
{
	//printf("getk:%4d\n",rank);
	int t=Root;
	while (rank)
	{
		if (rank<=ns[ns[t].l].size)
			t=ns[t].l;
		else if (rank==ns[ns[t].l].size+1)
			return ns[t].val;
		else
		{
			rank-=ns[ns[t].l].size+1;
			t=ns[t].r;
		}
		//printf("rank=%4d\n",rank);
	}
}
inline int mincmp(const int &a,const int &b)
{
	return num[a]<num[b];
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		R=Root=0;
		ns[0].l=ns[0].r=ns[0].size=0;
		sum[0]=0;
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&num[i]);
			sum[i]=sum[i-1]+num[i];
			minorder[i]=i;
		}
		sort(minorder+1,minorder+N+1,mincmp);
		insert(Root,0);
		insert(Root,N+1);
		int ansl,ansr;
		long long ans=0;
		for (int i=1;i<=N;i++)
		{
			int m=minorder[i],
				l=getk(lower_index(m))+1,
				r=getk(upper_index(m))-1;
			// printf("m=%4d,num[m]=%4d,l=%4d,r=%4d\n",m,num[m],l,r);
			// printf("li=%4d,ri=%4d\n",lower_index(m),upper_index(m));
			if (num[m]*(long long)(sum[r]-sum[l-1])>=ans)
			{
				ans=num[m]*(long long)(sum[r]-sum[l-1]);
				ansl=l;
				ansr=r;
			}
			insert(Root,m);
		}
		printf("%lld\n%d %d\n",ans,ansl,ansr);
	}
	return 0;
}