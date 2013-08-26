#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double pi=acos(-1.0);
double ANS;
int N,L,stack[1005],top;
struct Point
{
	int x,y;
	inline int operator < (const Point &p)const
	{
		return y<p.y || (y==p.y && x<p.x);
	}
	inline double dis(const Point &p)
	{
		return sqrt(((double)x-p.x)*(x-p.x)+ ((double)y-p.y)*(y-p.y));
	}
	inline int cross(const Point &p1,const Point &p2) 
	{
		return (p1.x-x)*(p2.y-y)-(p2.x-x)*(p1.y-y);
	}
}ps[1005];
int main()
{
	while (scanf("%d%d",&N,&L)!=EOF)
	{
		int i,j;
		for (i=1;i<=N;i++)
			scanf("%d%d",&ps[i].x,&ps[i].y);
		sort(ps+1,ps+N+1);
		ANS=0;
		//left
		top=0;
		for (i=1;i<=N;i++)
			if (i==1 || ps[i].y>ps[i-1].y)
			{
				while(top>1 && ps[i].cross(ps[stack[top]],ps[stack[top-1]])<0)top--;
				stack[++top]=i;
			}
		stack[++top]=N;
		for (i=2;i<=top;i++)
			ANS+=ps[stack[i]].dis(ps[stack[i-1]]);
		//right
		top=0;
		stack[++top]=1;
		for (i=1;i<=N;i++)
			if (i==N || ps[i+1].y>ps[i].y)
			{
				while(top>1 && ps[i].cross(ps[stack[top]],ps[stack[top-1]])>0)top--;
				stack[++top]=i;
			}
		for (i=2;i<=top;i++)
			ANS+=ps[stack[i]].dis(ps[stack[i-1]]);
		//output
		ANS+=2*pi*L;
		printf("%.0f\n",ANS);
	}
	return 0;
}