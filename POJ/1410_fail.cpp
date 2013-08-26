#include <cstdio>
#include <iostream>
using namespace std;
int T;
struct line
{
	int x1,y1,x2,y2;
	int VP(int x,int y)
	{
		return (x2-x1)*(y-y1)-(x-x1)*(y2-y1);
	}
	int DP(int x,int y)
	{
		return (x2-x1)*(x-x2)+(y2-y1)*(y-y2);
	}
}L;
int dis(int x1,int x2,int y1,int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d%d%d%d%d",&L.x1,&L.y1,&L.x2,&L.y2,&x1,&y1,&x2,&y2);
		int v1=L.VP(x1,y1),
			v2=L.VP(x1,y2),
			v3=L.VP(x2,y1),
			v4=L.VP(x2,y2);
		if ((v1 >0 && v2>0 && v3>0 && v4>0) || (v1 <0 && v2<0 && v3<0 && v4<0))
			printf("F\n");
		else
		{
			if (dis(L.x1,L.y1,x1,y1)+dis(L.x1,L.y1,x1,y2)+dis(L.x1,L.y1,x2,y1)+dis(L.x1,L.y1,x2,y2)<dis(L.x2,L.y2,x1,y1)+dis(L.x2,L.y2,x1,y2)+dis(L.x2,L.y2,x2,y1)+dis(L.x2,L.y2,x2,y2))
			{
				swap(L.x1,L.x2);
				swap(L.y1,L.y2);
			}
			//printf("%d %d %d %d\n",L.x1,L.y1,L.x2,L.y2);
			int bz=(L.DP(x1,y1)<=0)+(L.DP(x1,y2)<=0)+(L.DP(x2,y1)<=0)+(L.DP(x2,y2)<=0);
			//printf("bz=%d\n",bz);
			if (bz>1)
				printf("T\n");
			else
				printf("F\n");
		}
	}
	return 0;
}