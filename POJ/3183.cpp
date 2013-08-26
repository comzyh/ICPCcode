#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int N;
int H[50001];
int ans[50001],nans;
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		scanf("%d",&H[i]);
	nans=0;
	H[0]=H[1];
	H[N+1]=H[N];
	for (int i=1;i<=N;i++)
		if (H[i]>=H[i-1] && H[i]>=H[i+1])
			ans[++nans]=i;
	for (int i=1;i<=nans;i++)
		printf("%d\n",ans[i]);
	return 0;
}