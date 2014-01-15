#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int T,N,K;
int arr[1024];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&N,&K);
		for (int i=0;i<N;i++)
			scanf("%d",&arr[i]);
		while (K--)
			next_permutation(arr,arr+N);
		for (int i=0;i<N;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
	return 0;
}