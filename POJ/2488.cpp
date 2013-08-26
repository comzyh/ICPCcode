#include <cstdio>
#include <cstring>
const int dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={-1,1,-2,2,-2,2,-1,1};
struct point
{
	int x,y;
	inline void set(int &tx,int &ty )
	{
		x=tx;
		y=ty;
	}
	inline void print()
	{
		printf("%c%d",x+'A'-1,y);
	}
}q[900];
int used[100][100];
int X,Y,T,MUL;
inline int legal(int x,int y)
{
	return (x>0) && (y>0) && (x<=X) && (y<=Y);
}
int DFS(int x,int y,int k )
{
	q[k].set(x,y);
	used[x][y]=1;
	if (k==1)return 1;
	for (int i=0;i<8;i++)
		if (legal(x+dx[i],y+dy[i]) && !used[x+dx[i]][y+dy[i]] && DFS(x+dx[i],y+dy[i],k-1))return 1;
	used[x][y]=0;
	return 0;
}
int main()
{
	int i,j;
	scanf("%d",&T);
	for (i=1;i<=T;i++)
	{
		scanf("%d%d",&Y,&X);
		memset(used,0,sizeof(used));
		MUL=X*Y;
		printf("Scenario #%d:\n",i);
		if (DFS(1,1,X*Y))
		{
			for (j=MUL;j>=1;j--)
				q[j].print();
			printf("\n");
		}
		else
			printf("impossible\n");
		printf("\n");
	}
	_ASM
}
/*
_,3,_,5,_,
1,_,_,_,7
_,_,X,_,_
2,_,_,_,8
_,4,_,6,_
*/