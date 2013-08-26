#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int tab[20009];
int N,T;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
			scanf("%d",&tab[i]);
		sort(tab+1,tab+N+1);
		int sum=0;
		for (int i=N-2;i>=1;i-=3)
			sum+=tab[i];
		printf("%d\n",sum);
	}
	return 0;
}
