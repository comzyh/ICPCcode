#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int N,S;
int arr[20009];
int main()
{
	scanf("%d%d",&N,&S);
	for (int i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+N+1);
	int i=1,j=N;
	long long ans=0;
	while (i<j)
	{
		while (arr[j]+arr[i]>S && i<j)j--;
		ans+=j-i;
		i++;
	}
	printf("%lld\n",ans);
	return 0;
}