#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[109];
int N;
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+N+1);
	double ans=arr[N];
	for (int i=N-1;i>=1;i--)
	{
		ans*=arr[i];
		ans=sqrt(ans);
		ans*=2.0;
	}
	printf("%.3lf",ans);
	return 0;
}