#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int N,M,K;
int map[100][100];
int f[10000],rank[10000];
int getf(int x)
{
	if (f[x]==x)return x;
	return f[x]=getf(f[x]);
}
inline void add(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy)return ;
	f[fx]=fy;
	rank[fy]+=rank[fx];
}
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	memset(map,0,sizeof(map));
	while (K--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		map[r-1][c-1]=1;
	}
	for (int i=0;i<M*N;i++)
	{
		f[i]=i;
		rank[i]=1;
	}
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			if (map[i][j])
			{
				for (int d=0;d<4;d++)
				{
					int r=i+dx[d],c=j+dy[d];
					if (r>=0 && c>=0 && r<N && c<M && map[r][c])
						add(i*M+j,r*M+c);
				}
			}
	int ans=0;
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			ans=max(ans,rank[getf(i*M+j)]);
	printf("%d\n",ans );
	return 0;
}
