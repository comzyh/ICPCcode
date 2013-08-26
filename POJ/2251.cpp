#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int dx[]={-1,1,0,0,0,0},dy[]={0,0,-1,1,0,0},dz[]={0,0,0,0,-1,1};
struct point
{
	int x,y,z,step;
}S,E;
int L,R,C;
int map[31][31][31];
int dis[31][31][31];
inline int legal(const point &p)
{
	return (p.x>=1 && p.y>=1 && p.z>=1 && p.x<=R && p.y<=C && p.z<=L && map[p.x][p.y][p.z]);
}
int BFS()
{
	queue<point> q;
	S.step=0;
	memset(dis,0x3f,sizeof(dis));
	q.push(S);
	while (!q.empty())
	{
		point T=q.front();
		q.pop();
		if (T.step>dis[T.x][T.y][T.z])
			continue;
		//printf("x=%4d,y=%4d,z=%4d\n",T.x,T.y,T.z);
		for (int d=0;d<6;d++)
		{
			point r=T;
			r.x+=dx[d];
			r.y+=dy[d];
			r.z+=dz[d];
			r.step++;
			if (legal(r) && r.step<dis[r.x][r.y][r.z])
			{
				dis[r.x][r.y][r.z]=r.step;
				q.push(r);
			}
		}
	}
	return dis[E.x][E.y][E.z];
}
int main()
{
	while (scanf("%d%d%d",&L,&R,&C),L || R || C)
	{
		char tmp[50];
		for (int i=1;i<=L;i++)
		{
			gets(tmp);
			for (int j=1;j<=R;j++)
			{
				gets(tmp+1);
				for (int k=1;k<=C;k++)
					switch(tmp[k])
					{
						case '#':
							map[j][k][i]=0;
							break;
						case 'S':
							if (tmp[k]=='S')
							{
								S.x=j;
								S.y=k;
								S.z=i;
							}
						case 'E':
							if (tmp[k]=='E')
							{
								E.x=j;
								E.y=k;
								E.z=i;
							}
						case '.':
							map[j][k][i]=1;
							break;
					}
			}
			
		}
		int ans=BFS();
		if (ans<0x3f3f3f3f)
			printf("Escaped in %d minute(s).\n",ans);
		else
			printf("Trapped!\n");
	}
	return 0;
}