#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int dx[]={0,-1,-1,-1,0,1,1,1},dy[]={-1,-1,0,1,1,1,0,-1};
const int kx[]={-1,-2,-2,-1,1,2,2,1},ky[]={-2,-1,1,2,2,1,-1,-2};
int map[1001][1001];
int N,M,Case=0;
inline int inMap(int x,int y)
{
	return x<=N && x>=1 && y<=M && y>=1;
}
int main()
{
	while (scanf("%d%d",&N,&M),N && M)
	{
		memset(map,0,sizeof(map));
		int k,x,y;
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d%d",&x,&y);
			map[x][y]='Q';
		}
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d%d",&x,&y);
			map[x][y]='K';
		}
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d%d",&x,&y);
			map[x][y]='P';
		}
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)
				switch(map[i][j])
				{
					case 0:
						break;
					case 'Q':
						for (int d=0;d<8;d++)
							for (int tx=i+dx[d],ty=j+dy[d];
								inMap(tx,ty) && map[tx][ty]<=1;
								tx+=dx[d],ty+=dy[d])
								map[tx][ty]=1;

						break;
					case 'K':
						for (int d=0;d<8;d++)
							if (inMap(i+kx[d],j+ky[d]) && map[i+kx[d]][j+ky[d]]==0)
								map[i+kx[d]][j+ky[d]]=1;
						break;
				}
		int ans=0;
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)
				ans+=map[i][j]==0;	
		// for (int i=1;i<=N;i++)
		// {
		// 	for (int j=1;j<=M;j++)
		// 		printf("%4d",map[i][j]);
		// 	printf("\n");
		// }
		printf("Board %d has %d safe squares.\n",++Case,ans);
	}
	return 0;
}