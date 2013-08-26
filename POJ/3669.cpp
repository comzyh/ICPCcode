#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
struct meteor
{
	int x,y,t;
	inline int operator <(const meteor &o)const
	{
		return t<o.t;
	}
}ms[50009];
int R;
struct state
{
	int x,y,step;
};
int M;
int map[505][505],final[505][505],dis[505][505];
inline void destory(int t)
{
	while (ms[R].t<=t && R<=M)
	{
		int x=ms[R].x,y=ms[R].y;
		map[x][y]=map[x-1][y]=map[x+1][y]=map[x][y-1]=map[x][y+1]=1;
		R++;
	}
}
inline int legal(const state &s)
{
	return (s.x>=1 && s.x<500 & s.y>=1 && s.y<500 && !map[s.x][s.y]);
}
int BFS()
{
	queue<state> q;
	state S;
	S.x=1;
	S.y=1;
	S.step=0;
	memset(dis,0x3f,sizeof(dis));
	q.push(S);
	while (!q.empty())
	{
		state h=q.front();
		q.pop();
		if (h.step>dis[h.x][h.y])
			continue;
		if (final[h.x][h.y]==0)
			return h.step;
		destory(h.step+1);
		for (int d=0;d<4;d++)
		{
			state r=h;
			r.x+=dx[d];
			r.y+=dy[d];
			r.step++;
			if (legal(r) && r.step<dis[r.x][r.y])
			{
				dis[r.x][r.y]=r.step;
				q.push(r);
			}

		}
	}
	return 0x3f3f3f3f;
}
int main()
{
	while (scanf("%d",&M)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(final,0,sizeof(final));
		for (int i=1;i<=M;i++)
		{
			int x,y;
			scanf("%d%d%d",&x,&y,&ms[i].t);
			ms[i].x=++x;
			ms[i].y=++y;
			final[x][y]=final[x+1][y]=final[x-1][y]=final[x][y+1]=final[x][y-1]=1;
		}
		sort(ms+1,ms+M+1);
		R=1;
		destory(0);
		int ans;
		if (map[1][1])
			ans=0x3f3f3f3f;
		else
			ans=BFS();
		if (ans==0x3f3f3f3f)
			ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}