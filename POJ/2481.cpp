#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N,T;
struct point
{
	int pos,segment,begin;
	inline int operator <(const point &x)const
	{
		return pos<x.pos || (pos==x.pos && begin <x.begin);
	}
}ps[200009];
int ans[100005];
int r,S;
int main()
{	
	int i;
	while (scanf("%d",&N),N)
	{
		r=0;
		for (i=1;i<=N;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			r++;
			ps[r].pos=a;
			ps[r].segment=i;
			ps[r].begin=1;
			r++;
			ps[r].pos=b;
			ps[r].segment=i;
			ps[r].begin=0;
		}
		sort(ps+1,ps+2*N+1);
		S=0;
		fill(ans+1,ans+N+1,0);
		for (i=1;i<=2*N;i++)
		{
			printf("i=%4d,%4d %4d %4d\n",i,ps[i].pos,ps[i].segment,ps[i].begin);
			if (ps[i].begin==1)
				S++;
			else
			{
				int j;
				printf("S=%d ",S);
				for(j=i;ps[j].pos==ps[i].pos && ps[j].begin==0;j++)
					S--;
				printf("S=%d\n",S);
				for(j=i;ps[j].pos==ps[i].pos && ps[j].begin==0;j++)
					ans[ps[j].segment]=S;
				i=j-1;
				
			}
		}
		for (i=1;i<=N;i++)
			printf("%d ",ans[i]);

		printf("\n");
	}
}