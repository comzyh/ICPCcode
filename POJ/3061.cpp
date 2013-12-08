#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T;
int N,S;
int arr[1000009];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&N,&S);
		int l=1,ans=0x3f3f3f3f;
		long long sum=0;
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
			while (sum-arr[l]>=S)
			{
				sum-=arr[l];
				l++;
			}
			if (sum>=S)
				ans=min(ans,i-l+1);
		}
		if (ans==0x3f3f3f3f)
			printf("0\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}