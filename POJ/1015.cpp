#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int dp[201][21][801];
int path[201][21][801];
int D[201],P[201];
int N,M,TT=0;
void ANS(int k)
{
	//printf("k=%d\n",k);
	int sumd=0,sump=0,MM=M;
	int i=N,j=M;
	int his[21];
	do
	{
		his[MM]=path[i][j][k];
		sumd+=D[his[MM]];
		sump+=P[his[MM]];
		i=his[MM]-1;
		j--;
		k-=D[his[MM]]-P[his[MM]];
	}while(--MM);
	printf("Best jury has value %d for prosecution and value %d for defence:\n",sump,sumd);
	for (int i=1;i<=M;i++)
		printf(" %d",his[i]);
	printf("\n");
}
int main()
{
	while (scanf("%d%d",&N,&M),N || M)
	{
		printf("Jury #%d\n",++TT); 
		memset(dp,0,sizeof(dp));
		memset(path,0xff,sizeof(path));//-1
		path[0][0][400]=0;
		for (int i=0;i<N;i++)
		{
			int d,p;
			scanf("%d%d",&p,&d);
			D[i+1]=d;
			P[i+1]=p;
			for (int j=max(0,i-N+M);j<=min(i,M);j++)
				for (int k=0;k<=800;k++)
					if (path[i][j][k]>=0)
					{
						if (dp[i][j][k]+d+p>=dp[i+1][j+1][k+d-p] && j<M)
						{
							dp[i+1][j+1][k+d-p]=dp[i][j][k]+d+p;
							path[i+1][j+1][k+d-p]=i+1;
						}
						if (dp[i][j][k]>=dp[i+1][j][k])
						{
							dp[i+1][j][k]=dp[i][j][k];
							path[i+1][j][k]=path[i][j][k];
						}
					}
		}
		int ans=0;
		for (int i=0;i<=400;i++)
			if (path[N][M][400+i]>=0 || path[N][M][400-i]>=0)
			{
				if (dp[N][M][400+i]>dp[N][M][400-i])
					ANS(400+i);
				else
					ANS(400-i);
				break;
			}		
	}
	return 0;
}