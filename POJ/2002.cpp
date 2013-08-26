#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int N,ANS;
struct TP 
{
	int x,y;
	inline bool operator <(const TP &t)const
	{
		return x<t.x || (x==t.x && y<t.y);
	}
}ps[1001];
inline int bin(int x,int y)
{
	//printf("x=%4d,y=%4d\n",x,y);
	TP t;
	t.x=x;t.y=y;
	int b=1,e=N,k;
	while (b<e)
	{
		k=(b+e)>>1;
		if (ps[k]<t)
			b=k+1;
		else if (t<ps[k])
			e=k-1;
		else
			return 1;
	}
	if (ps[b].x==x && ps[b].y==y)
		return 1;
	else
		return 0;
}
int main()
{
	while (scanf("%d",&N),N)
	{
		int i,j;
		for (i=1;i<=N;i++)
			scanf("%d%d",&ps[i].x,&ps[i].y);
		sort(ps+1,ps+N+1);
		ANS=0;
		for (i=1;i<N;i++)
			for (j=i+1;j<=N;j++)
				if (ps[i].x<ps[j].x && ps[i].y<=ps[j].y)
				{
					int dx=ps[j].x-ps[i].x,dy=ps[j].y-ps[i].y;
					//printf("(%3d,%3d),(%3d,%3d)\n",ps[i].x,ps[i].y,ps[j].x,ps[j].y);
					if (bin(ps[i].x-dy,ps[i].y+dx) && bin(ps[j].x-dy,ps[j].y+dx))
					{
						ANS++;
						//printf("---------->(%3d,%3d),(%3d,%3d)\n",ps[i].x,ps[i].y,ps[j].x,ps[j].y);
					}
					//printf("<--------%d,%d-------->\n",bin(0,1),bin(1,2));
				}
		printf("%d\n",ANS);
	}
	return 0;
}