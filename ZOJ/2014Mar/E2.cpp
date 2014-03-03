#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct T_ball
{
	int index,x,y;
}bs[2009];
int f[2009];
int N;
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
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		for (int i=1;i<=N;i++)
		{
			bs[i].index=i;
			scanf("%d%d",&bs[i].x,&bs[i].y);
			f[i]=i;
		}		
		sort(bs+1,bs+N+1,cmpx);
		for (int i=1;i<N;i++)
			if (bs[i].x==bs[i+1].x)
				add(bs[i].index,bs[i+1].index);
		sort(bs+1,bs+N+1,cmpy);
		for (int i=1;i<N;i++)
			if (bs[i].y==bs[i+1].y)
				add(bs[i].index,bs[i+1].index);	
		int ans=0;
		for (int i=1;i<=N;i++)
			ans+=f[i]==i;
		printf("%d\n",ans);
	}
	return 0;
}