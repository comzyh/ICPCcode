#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int dp[100009];
int C,N;
int W[200];
int main()
{
	while (scanf("%d%d",&C,&N)!=EOF)
	{
		int n,w;
		W[0]=0;
		while (N--)
		{
			scanf("%d%d",&n,&w);
			int m;
			for (m=1;((m<<1)-1)<n>>1;m<<=1);
			//printf("n=%4d,m=%4d\n",n,m);
			if (n==0)m=0;
			for (;m;m>>=1)
			{
				W[++W[0]]=w*m;
				n-=m;
			}
			W[++W[0]]=w*n;
			//printf("w*n=%d\n",w*n);
		}
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=W[0];i++)
			for (int j=C;j>=W[i];j--)
				dp[j]=max(dp[j],dp[j-W[i]]+W[i]);
		printf("%d\n",dp[C]);
	}
	return 0;
}