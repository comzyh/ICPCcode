#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MOD=0xfffff;
int q[MOD],h,r;
int dis[200005],in[200005];
int N,K;
inline void addq(int x)
{
	if(!in[x])
	{
		in[x]=1;
		q[(++r)&MOD]=x;
	}
}
int main()
{
	while (scanf("%d%d",&N,&K)!=EOF)
	{
		memset(dis,0x3f,sizeof(dis));
		memset(in,0,sizeof(in));
		q[1]=N;in[N]=1;
		dis[N]=0;
		h=0;r=1;
		while(h<r)
		{
			int t=q[(++h)&MOD];
			//printf("t=%4d\n",t);
			if (t==K)
			{
				printf("%d\n",dis[t]);
				break;
			}
			if (t<K && dis[t]+1<dis[t<<1])//*2
			{
				dis[t<<1]=dis[t]+1;
				addq(t<<1);
			}
			if (t>0 && dis[t]+1<dis[t-1])//-1
			{
				dis[t-1]=dis[t]+1;
				addq(t-1);
			}
			if (t<K && dis[t]+1<dis[t+1])//+1
			{
				dis[t+1]=dis[t]+1;
				addq(t+1);
			}
			in[t]=0;
		}
	}
	return 0;
}
