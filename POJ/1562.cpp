#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int dx[]={0,-1,-1,-1,0,1,1,1},dy[]={-1,-1,0,1,1,1,0,-1};
int M,N;
char map[100][101];
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
	f[fx]=fy;
}
int main()
{
	while (scanf("%d%d",&M,&N),M)
	{
		for (int i=0;i<M;i++)
			scanf("%s",map[i]);
		for (int i=0;i<M*N;i++)
			f[i]=i;
		for (int i=0;i<M;i++)
			for (int j=0;j<N;j++)
				if (map[i][j]=='@')
					for (int d=0;d<8;d++)
					{
						int x=i+dx[d],y=j+dy[d];
						if (x<0 || x>=M || y<0 || y>=N || map[x][y]!='@')
							continue;
						add(i*N+j,x*N+y);
					}
		int ans=0;
		for (int i=0;i<M;i++)
			for (int j=0;j<N;j++)
					ans+=map[i][j]=='@' && getf(i*N+j)==i*N+j;
		printf("%d\n",ans);
	}
	return 0;
}