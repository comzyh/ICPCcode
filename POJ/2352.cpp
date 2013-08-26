#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=15000;
struct T_Point
{
	int x,y;
	inline int operator <(const T_Point &k)const 
	{
		return (x<k.x) || (x==k.x && y<k.y);
	}
}ps[MAX+1];
int level[MAX+1];
int N;
int tree[32009];
inline int add(const T_Point &k);
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		int i;
		for (i=1;i<=N;i++)
		{
			scanf("%d%d",&ps[i].x,&ps[i].y);
			ps[i].y++;
		}
		sort(ps+1,ps+1+N);
		memset(tree,0,sizeof(tree));
		memset(level,0,sizeof(level));
		for (i=1;i<=N;i++)
			level[add(ps[i])]++;
		for (i=0;i<N;i++)
			printf("%d\n",level[i]);
	}
}
int add(const T_Point &k)
{
	
	int ans=0,y=k.y;
	while (y)
	{
		ans+=tree[y];
		y&=y-1;
	}
	y=k.y;
	while (y<=32001)
	{
		tree[y]++;
		y+=(y&-y);
	}
	return ans;
}