#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N,T;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		int minp=0x3fffffff,maxp=0,p;
		while(N--)
		{
			scanf("%d",&p);
			minp=min(minp,p);
			maxp=max(maxp,p);
		}
		printf("%d\n", (maxp-minp)*2);
	}
	return 0;
}