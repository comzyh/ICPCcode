#include <cstdio>
#include <iostream>
#include <algorithm>
//#include <functional>
using namespace std;
int T,N,S;
int give[10001];
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		scanf("%d%d",&S,&N);
		int i,SUM=0;
		for (i=1;i<=N;i++)
			scanf("%d",&give[i]);
		sort(give+1,give+N+1,greater<int>());
		for (i=1;i<=N;i++)
		{
			SUM+=give[i];
			if (SUM>=S)
				break;
		}
		printf("Scenario #%d:\n",TT);
		if (i<=N)
			printf("%d\n\n",i);
		else
			printf("impossible\n\n");	
	}
	return 0;
}