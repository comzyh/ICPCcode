#include <cstdio>
#include <algorithm>
#include <cmath>
struct body
{
	int begin,speed,end;
	bool operator <(const body &x)const
	{
		return end<x.end;
	}
	inline void read()
	{
		scanf("%d%d",&speed,&begin);
		end=(int)ceil(4500*3.6/speed)+begin;
	}
}bs[10006];
int N;
int main()
{
	int i,j;
	while(scanf("%d",&N),N)
	{
		for (i=1;i<=N;i++)
			bs[i].read();
		std::sort(bs+1,bs+1+N);
		int ans;
		for (i=1;i<=N;i++)
			if (bs[i].begin>=0)
			{
				ans=bs[i].end;
				break;
			}
		printf("%d\n",ans);
	}
		
}