#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N,arr[200];
int main()
{
	while (scanf("%d",&N),N)
	{
		for (int i=1;i<=N;i++)
			scanf("%d",&arr[i]);
		sort(arr+1,arr+N+1);
		printf("%d",arr[1]);
		for (int i=2;i<=N;i++)
			if (arr[i]!=arr[i-1])
			printf(" %d",arr[i]);
		printf("\n");
	}
	return 0;
}