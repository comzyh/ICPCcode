#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct Point
{
	int x,y;
	inline int operator <(const Point &t)
	{
		return x<t.x || (x==t.x && y<t.y);
	}
	inline int read()
	{
		if(scanf("%d%d",&x,&y)!=EOF)
		{
			if (x==-1 && y==--1)
				return -1;
			else
				return 1;
		}
		return EOF;
	}
}ps[40005],B,E,line[201][201];
int Nps;
int main()
{
	Nps=0;
	B.read();ps[++Nps]=B;
	E.read();ps[++Nps]=E;
	int L=0;
	while (line[++L][1].read()!=EOF)
	{
		line[L][0].x=1;
		while (line[L][++line[L][0].x].read!=-1)ps[++Nps]=line[L][line[L][0].x];
		line[L][0].x--;
	}
	L--;
	//
	sort(ps+1,ps+Nps+1);
	
}