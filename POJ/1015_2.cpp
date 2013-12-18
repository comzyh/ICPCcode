#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[21][805];
int path[21][805];
int D[201],P[201];
int N,M,TT=0;
void ANS(int k)
{
	//printf("k=%d\n",k);
	int his[21],sumd=0,sump=0;
	for (int j=M;j>=1;j--)
	{
		//printf("k=%4d\n",k);
		his[j]=path[j][k];
		k-=D[his[j]]-P[his[j]];
		sumd+=D[his[j]];
		sump+=P[his[j]];
	}
	printf("Best jury has value %d for prosecution and value %d for defence:\n",sump,sumd);
	sort(his+1,his+M+1);
	for (int i=1;i<=M;i++)
		printf(" %d",his[i]);
	printf("\n");
}
inline int selected(int j,int k,int i)
{
	while (j)
	{
		int &p=path[j][k];
		//printf("j=%4d,k=%4d\n",j,k);
		if (p==i)
			return 1;
		k-=D[p]-P[p];
		j--;
	}
	return 0;
}
void pri()
{
	for (int k=370;k<=430;k++)
	{
		printf("k=%4d:",k);
		for (int j=0;j<=M;j++)
			printf("(%4d,%4d)",dp[j][k],path[j][k]);
		printf("\n");
	}
}
int main()
{
	while (scanf("%d%d",&N,&M),N || M)
	{
		memset(dp,0,sizeof(dp));
		memset(path,0xff,sizeof(path));
		printf("Jury #%d\n",++TT);
		path[0][400]=0;
		for (int i=1;i<=N;i++)
			scanf("%d%d",&P[i],&D[i]);
		for (int j=0;j<M;j++)
			for (int k=0;k<=800;k++)
				if (path[j][k]>=0)
					for (int i=1;i<=N;i++)
					{
						int d=D[i],p=P[i];
						if (dp[j][k]+d+p>=dp[j+1][k+d-p] && !selected(j,k,i))
						{
							dp[j+1][k+d-p]=dp[j][k]+d+p;
							path[j+1][k+d-p]=i;
						}

					}
		// for (int i=0;i<N;i++)
		// {
		// 	int d,p;
		// 	scanf("%d%d",&p,&d);
		// 	D[i+1]=d;
		// 	P[i+1]=p;
		// 	for (int j=0;j<M;j++)
		// 		//for (int k=(d-p>0?800:0);k!=(d-p>0?-1:801);k+=(d-p>0?-1:1))
		// 		for (int k=0;k<=800;k++)
		// 			if (path[j][k]>=0 && !selected(j,k,i+1))
		// 			{
		// 				if (dp[j][k]+d+p>dp[j+1][k+d-p])
		// 				{
		// 					dp[j+1][k+d-p]=dp[j][k]+d+p;
		// 					path[j+1][k+d-p]=i+1;
		// 				}
		// 			}
		// }
		for (int i=0;i<=400;i++)
			if (path[M][400+i]>=0 || path[M][400-i]>=0)
			{
				if (dp[M][400+i]>dp[M][400-i])
					ANS(400+i);
				else
					ANS(400-i);
				break;
			}
		//pri();
	}
	return 0;
}