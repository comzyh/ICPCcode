#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
struct T_ball
{
	int index,x,y;
}bs[2009];
int f[2009];
vector<int>tab[2009];
int getf(int x)
{
	if(f[x]==x)return x;
	return f[x]=getf(f[x]);
}
inline void add(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if (fx==fy)return;
	f[fx]=fy;
}
inline int cmpx(const T_ball &x,const T_ball &y)
{
	return x.x<y.x;
}
inline int cmpy(const T_ball &x,const T_ball &y)
{
	return x.y<y.y;
}
inline int cmpindex(const T_ball &x,const T_ball &y)
{
	return x.index<y.index;
}
void buildtree(int(*cmp)(const T_ball&,const T_ball&))
{
	sort(bs+1,bs+N+1,cmp);
	for (int i=1;i<N;i++)
		if (cmp(bs[i],bs[i+1])==0 && cmp(bs[i+1],bs[i])==0 && getf(bs[i].index)!=getf(bs[i+1].index))
		{
			add(bs[i].index,bs[i+1].index);
			tab[bs[i].index].push_back(bs[i+1].index);
			tab[bs[i+1].index].push_back(bs[i].index);
		}
}
int dfs(int x,int f)
{
	for (int i=0;i<tab[x].size();i++)
		if (tab[x][i]!=f)
			dfs(tab[x][i],x);
	if (f!=0)
	{
		printf("(%d, %d) ",bs[x].x,bs[x].y);
		if (bs[x].x>bs[f].x)printf("LEFT");
		if (bs[x].x<bs[f].x)printf("RIGHT");
		if (bs[x].y<bs[f].y)printf("UP");
		if (bs[x].y>bs[f].y)printf("DOWN");
		printf("\n");
	}
}
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			bs[i].index=i;
			scanf("%d%d",&bs[i].x,&bs[i].y);
			f[i]=i;
			tab[i].clear();
		}		
		buildtree(cmpx);
		buildtree(cmpy);
		sort(bs+1,bs+N+1,cmpindex);
		vector<int> roots;
		for (int i=1;i<=N;i++)
			if (f[i]==i)
				roots.push_back(i);
		printf("%d\n",roots.size());
		for (int i=0;i<roots.size();i++)
			dfs(roots[i],0);
	}
	return 0;
}