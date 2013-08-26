#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX=100000;
int P;
struct point
{
	int x,y;
}ps[MAX+5];
int ANS;
int sortx[MAX+5],sorty[MAX+5];
int in[MAX+5];
inline bool lessx(const point &a,const point &b)
{
	return (a.x<b.x) || (a.x==b.x && a.y<b.y);
}
inline bool lessy(const point &a,const point &b)
{
	return (a.y<b.y) || (a.y==b.y && a.x<b.x);
}
int main()
{	
	while (scanf("%d",&P),P)
	{
		int i,j;
		memset(ps,0,sizeof(ps));
		for (i=1;i<=P;i++)
			scanf("%d%d",&ps[i].x,&ps[i].y);
		ANS=0;
		sort(ps+1,ps+P+1,lessx);
		for (i=1;i<=P;i+=2)
			if(ps[i+1].x==ps[i].x)
				ANS+=ps[i+1].y-ps[i].y;
		sort(ps+1,ps+P+1,lessy);
		for (i=1;i<=P;i+=2)
			if(ps[i+1].y==ps[i].y)
				ANS+=ps[i+1].x-ps[i].x;
		printf("The length of the fence will be %d units.\n",ANS);
	}
}