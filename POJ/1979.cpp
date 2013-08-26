#include <cstdio>
#include <cstring>
const int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int N,M,ANS;
int map[100][100];
int used[100][100];
int bx,by;
inline int legal(int x,int y);
int dfs(int x,int y);
int main()
{
	int i,j;
	char str[100];
	while (scanf("%d%d",&M,&N),N || M)
	{
		memset(map,0,sizeof(map));
		getchar();
		for (i=1;i<=N;i++)
		{
			gets(str);
			for (j=1;j<=M;j++)
			{
				if(str[j-1]!='#')
					map[i][j]=1;
				if (str[j-1]=='@')
				{
					bx=i;
					by=j;
				}
			}
		}
		memset(used,0,sizeof(used));
		ANS=0;
		dfs(bx,by);
		printf("%d\n",ANS);
		
	}
}
inline int legal(int x,int y)
{
	return (map[x][y] && !used[x][y] && x>0 && x<=N && y>0 && y<=M);
}
int dfs(int x,int y)
{
	ANS++;
	used[x][y]=1;
	for (int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if (legal(tx,ty))
			dfs(tx,ty);
	}
}
