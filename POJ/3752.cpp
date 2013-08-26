#include <cstdio>
#include <cstring>
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int M,N;
char tab[100][100],C;
inline char inc()
{
	C++;
	if (C>'Z')
		C='A';
	return C;
}
int main()
{
	int i,j;
	int x=1,y=1;
	memset(tab,0,sizeof(tab));
	scanf("%d%d",&N,&M);
	for (i=0;i<=M+1;i++)
	{
		tab[0][i]=0x3f;
		tab[N+1][i]=0x3f;
	}
	for (i=0;i<=N+1;i++)
	{
		tab[i][0]=0x3f;
		tab[i][M+1]=0x3f;
	}
	C='Z';
	while (tab[x][y]==0)
		for (i=0;i<4;i++)
		{
			while (tab[x][y]==0)
			{
				tab[x][y]=inc();
				x+=dx[i];
				y+=dy[i];
			}
			x-=dx[i];
			y-=dy[i];
			x+=dx[(i+1)&3];
			y+=dy[(i+1)&3];
		}
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=M;j++)
			printf("   %c",tab[i][j]);
		printf("\n");
	}
}
