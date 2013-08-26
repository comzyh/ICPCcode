#include <cstdio>
#include <iostream>
using namespace std;
struct line
{
	int x1,x2,y1,y2;
	int P(line k)
	{
		int a=(x2-x1)*(k.y1-y1)-(k.x1-x1)*(y2-y1),
			b=(x2-x1)*(k.y2-y1)-(k.x2-x1)*(y2-y1);
		if (a==0 && b==0)//共线
		{
			if(x1==x2)
				return ((y1<=k.y1)^(y1<=k.y2))|| ((y2<=k.y1)^(y2<=k.y2)) || y1==k.y1 || y1==k.y2 || y2==k.y1 || y2==k.y2;
			else
				return ((x1<=k.x1)^(x1<=k.x2))|| ((x2<=k.x1)^(x2<=k.x2)) || x1==k.x1 || x1==k.x2 || x2==k.x1 || x2==k.x2;
		}
		return ((a<=0 && b>=0)||(a>=0 && b<=0));
	}
}L;
int T;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int x1,y1,x2,y2;
		line l1,l2,l3,l4;
		scanf("%d%d%d%d%d%d%d%d",&L.x1,&L.y1,&L.x2,&L.y2,&x1,&y1,&x2,&y2);
		if(x2<x1)swap(x1,x2);
		if(y2<y1)swap(y1,y2);
		l1.x1=x1;l1.y1=y1;l1.x2=x2;l1.y2=y1;
		l2.x1=x2;l2.y1=y1;l2.x2=x2;l2.y2=y2;
		l3.x1=x2;l3.y1=y2;l3.x2=x1;l3.y2=y2;
		l4.x1=x1;l4.y1=y2;l4.x2=x1;l4.y2=y1;
		int ANS=(x1<=L.x1 && L.x1<=x2 && x1<=L.x2 && L.x2<=x2 && 
				 y1<=L.y1 && L.y1<=y2 && y1<=L.y2 && L.y2<=y2);
		ANS|=(L.P(l1) && l1.P(L));
		ANS|=(L.P(l2) && l2.P(L));
		ANS|=(L.P(l3) && l3.P(L));
		ANS|=(L.P(l4) && l4.P(L));
		if (ANS)
			printf("T\n");
		else
			printf("F\n");
	}
	return 0;
}
