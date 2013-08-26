#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct T_prob
{
	int t,v;
	inline bool operator <(const T_prob &x )const
	{
		return t<x.t;
	}
}p[52];
int dp[1002][55];
int main()
{
	int T,i,j,k,n,t;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&t,&n);
		for(i=1;i<=n;i++)
			scanf("%d",&p[i].t);
		for(i=1;i<=n;i++)
			scanf("%d",&p[i].v);
		sort(p+1,p+n+1);
		//printf("readed\n");
		for(i=1;i<=n;i++)
			for(j=t;j>=p[i].t;j--)
			{
				//printf("i=%4d,j=%4d (%4d,%4d)\n",i,j,dp[j-p[i].t][0]+p[i].v,dp[j][0]);
				if (dp[j-p[i].t][0]+p[i].v>dp[j][0] || 
					(dp[j-p[i].t][0]+p[i].v==dp[j][0] && dp[j-p[i].t][52]+1>dp[j][52]))
				{
					//printf("--->i=%d,j=%d | %d\n",i,j,dp[j-p[i].t][0]+p[i].v);
					for (k=1;k<=n;k++)
							dp[j][k]=dp[j-p[i].t][k];
					dp[j][52]=dp[j-p[i].t][52];
					dp[j][i]=1;
					dp[j][52]++;
					dp[j][0]=dp[j-p[i].t][0]+p[i].v;
				}
			}
		//cout<<dp[t][0]<<endl;
		// for (i=1;i<=t;i++)
		// {
			// for (j=0;j<=n;j++)
				// printf("%d ",dp[i][j]);
			// printf("--|\n");
		// }
		
		int ans=0,nu=0,tnu;
		for (i=1;i<=n;i++)
			if (dp[t][i])
				nu++;
		tnu=nu;
		for (i=1;i<=n;i++)
			if (dp[t][i])
			{
				ans+=p[i].t*tnu;
				tnu--;
			}
		printf("%d %d %d\n",dp[t][0],nu,ans);
		//cout<<ans<<endl;
	}
	return 0;
}
