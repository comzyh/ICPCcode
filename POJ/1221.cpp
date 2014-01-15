#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int dp[300][300];//和为2*i最大值为j偶回文的个数
int main()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=1;i<=150;i++)
		for (int j=1;j<=i;j++)
			for (int k=j;k>=0;k--)
				dp[i][j]+=dp[i-j][k];
	int N;
	while (scanf("%d",&N),N)
	{
		long long  ans=0;
		//单峰
		for (int i=1;i<=N;i++)
			if (((N-i)&1)==0)
				for (int j=0;j<=i;j++)
					ans+=dp[(N-i)>>1][j];
		//双峰
		if((N&1)==0)
			for (int i=1;i<=N>>1;i++)
				ans+=dp[N>>1][i];
		printf("%d %lld\n",N,ans);
	}
	return 0;
}