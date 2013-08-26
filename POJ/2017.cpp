#include <cstdio>
#include <iostream>
using namespace std;
int N;
int main()
{
	while (scanf("%d",&N),N>0)
	{
		int ans=0,l=0;
		while (N--)
		{
			int v,t;
			scanf("%d%d",&v,&t);
			ans+=v*(t-l);
			l=t;
		}
		printf("%d miles\n",ans);
	}
	return 0;
}
