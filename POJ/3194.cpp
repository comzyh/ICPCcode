#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int dx[4]={-1,0,1,0},dy[]={0,-1,0,1};
int N;
int arr[109][109];
int f[10009],rank[10009];
int getf(int x)
{
	if (f[x]==x)return x;
	return f[x]=getf(f[x]);
}
inline void add(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy)return ;
	rank[fx]+=rank[fy];
	f[fy]=fx;
}
int main()
{
	while (scanf("%d",&N),N)
	{
		memset(arr,0,sizeof(arr));
		for (int i=1;i<N;i++)
			for (int j=1;j<=N;j++)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				arr[x-1][y-1]=i;
			}
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				if (arr[i][j]==0)
					arr[i][j]=N;
		//UFS
		for (int i=0;i<N*N;i++)
		{
			f[i]=i;
			rank[i]=1;
		}
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				for (int d=0;d<4;d++)
				{
					int x=i+dx[d],y=j+dy[d];
					if (x<0 || x>=N || y<0 || y>=N)
						continue;
					if (arr[i][j]==arr[x][y])
						add(i*N+j,x*N+y);
				}
		int ans=1;
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				ans&=rank[getf(i*N+j)]==N;
		if (ans==1)
			printf("good\n");
		else
			printf("wrong\n");
	}
	return 0;
}