#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int V,P;
int num[305];
int dp[305][35],w[305][305];
int main()
{
	scanf("%d%d",&V,&P);
	int i,j,k;
	for (i=1;i<=V;i++)
		scanf("%d",&num[i]);
	memset(w,0x3f,sizeof(w));
	for (i=1;i<=V;i++)
	{
		int left=0;
		for (j=i;j<=V;j++)
		{
			left+=num[j];
			int right=0;
			for (k=j;k<=V;k++)
			{
				right+=num[k];
				if ((j-i+1)*num[j]-left+right-(k-j+1)*num[j]<w[i][k])	
					w[i][k]=(j-i+1)*num[j]-left+right-(k-j+1)*num[j];
				
			}
			
		}
	}
	/* for (int i=1;i<=V;i++)
	{
		for (j=1;j<=V;j++)
			if (w[i][j]<0x3f3f3f3f)
				printf("%4d",w[i][j]);
			else
				printf("   M");
		printf("\n");
	} */
	//DP
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for (i=1;i<=V;i++)
		for (j=1;j<=P;j++)
			for (k=0;k<i;k++)
				if (dp[k][j-1]+w[k+1][i]<dp[i][j])
					dp[i][j]=dp[k][j-1]+w[k+1][i];
/* 	cout << endl;
	for (int i=1;i<=V;i++)
	{
		for (j=1;j<=V;j++)
			if (dp[i][j]<0x3f3f3f3f)
				printf("%4d",dp[i][j]);
			else
				printf("   M");
		printf("\n");
	} */
	printf("%d\n",dp[V][P]);
	return 0;
}