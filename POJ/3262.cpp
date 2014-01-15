#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct T_cow
{
	int t,d;
	double td;
	void read()
	{
		scanf("%d%d",&t,&d);
		td=(double)t/d;
	}
	inline int operator < (const T_cow &x)const
	{
		return td<x.td;
	}
}cs[100009];
int N;
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		cs[i].read();
	sort(cs+1,cs+N+1);
	long long ans=0,sumt=0;
	for (int i=1;i<=N;i++)
	{
		ans+=sumt*cs[i].d;
		sumt+=cs[i].t*2;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
d1 t1	d2*t1 
d2 t2	d1*t2
同除d1 d2
*/