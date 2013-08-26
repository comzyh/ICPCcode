#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct T_cow
{
	int index,va,vb;
}cs[50001];
int N,K;
inline int cmpa(const T_cow &a,const T_cow &b)
{
	return a.va>b.va;	
}
inline int cmpb(const T_cow &a,const T_cow &b)
{
	return a.vb>b.vb;	
}

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++)
	{
		scanf("%d%d",&cs[i].va,&cs[i].vb);
		cs[i].index=i;
	}
	sort(cs+1,cs+N+1,cmpa);
	sort(cs+1,cs+K+1,cmpb);
	printf("%d\n",cs[1].index);
	return 0;
	
	
}