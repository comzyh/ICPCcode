#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int TT=0,arr[7],dp[120001];
int main()
{
	while (1)
	{
		int orsum=0,sum=0;
		for (int i=1;i<=6;i++)
		{
			scanf("%d",&arr[i]);
			orsum|=arr[i];
			sum+=arr[i]*i;
		}
		if (!orsum)
			break;
		printf("Collection #%d:\n",++TT);
		memset(dp,0,sizeof(dp));
		if (sum&1)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		sum/=2;
		//printf("sum=%d\n",sum);
		for (int i=1;i<=6;i++)
			for (int j=1;j<=arr[i] && j;)
			{
				for (int k=sum;k>=1;k--)
					if (k>=j*i)
						dp[k]=max(dp[k],dp[k-j*i]+j*i);
				// for (int k=1;k<=sum;k++)
				// 	printf("%4d",dp[k]);
				// printf("\n");
				arr[i]-=j;
				if (j*2<=arr[i])
					j<<=1;
				else
					j=arr[i];

			}
		printf(dp[sum]==sum?"Can be divided.\n\n":"Can't be divided.\n\n");
	}
	return 0;
}