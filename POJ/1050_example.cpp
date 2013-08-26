/*
  Name:POJ 1050 
  Copyright: flymouse@galaxy                                         
  Author:chenlei
  Date: 15-02-06 07:36
  Description: DP O(N^3)
*/
#include <stdio.h>
#include <string.h>
#define mt 101
int main()
{
	int a[mt][mt];
	int st[mt][mt];
	int p,k,n,i,j,sum,maxn;
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	memset(st,0,sizeof(st));
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			st[i][j]=st[i][j-1]+a[j][i];
	maxn=0;

	for (i=1;i<=n;i++)
	{
		for (j=i;j<=n;j++)
		{
			p=st[1][j]-st[1][i-1];
			sum=p;
			for (k=2;k<=n;k++)
			{
				if (sum>0)
				sum+=st[k][j]-st[k][i-1];
				else sum=st[k][j]-st[k][i-1];
				if (sum>p) p=sum;
			}
			if (p>maxn) maxn=p;
		}
	}
	printf("%d\n",maxn);
	return 0;
}